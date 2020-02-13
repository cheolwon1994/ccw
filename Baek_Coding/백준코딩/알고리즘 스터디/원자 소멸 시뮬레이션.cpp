#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
struct info {
	int x, y, dir, val;
}atom[1001];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int check[2001][2001];			//이동할때 사용
int next_check[2001][2001];		//다음값 보유
bool explode[1002];		//1~1001 사용

int num;
long long result;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int test, y, x, d, val;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		cin >> num;
		//초기화
		result = 0;
		memset(check, 0, sizeof(check));
		memset(next_check, 0, sizeof(next_check));
		memset(explode, false, sizeof(explode));
			
		for (int i = 1; i <= num; i++) {
			cin >> x >> y >> d >> val;
			atom[i].x = x + 1000;
			atom[i].y = y + 1000;
			atom[i].dir = d;
			atom[i].val = val;
			check[atom[i].y][atom[i].x] = i;
		}
		int tt = 1;
		while (1) {
			if (tt == 2001) break;
			for (int i = 1; i <= num; i++) {
				if (explode[i]) continue;	//폭발했거나 나간경우
				int cx = atom[i].x;
				int cy = atom[i].y;
				int cv = atom[i].val;
				int cd = atom[i].dir;
				int nx = cx + dx[cd];
				int ny = cy + dy[cd];
				if (nx < 0 || ny < 0 || nx>2000 || ny>2000) {		//나간 경우, 0으로 변환
					explode[i] = true;
					if (i == 2 || i == 3) {
						cout << tt << " "<<cd<<endl;
						cout << "여기1" << endl;
						system("pause");
					}
					atom[i].val = 0;
					continue;
				}
				atom[i].x = nx;
				atom[i].y = ny;
				check[cy][cx] = 0;
				if (check[ny][nx] != 0) {		//움직이기 전의 원자와 마주함
					if (cd + atom[check[ny][nx]].dir==1 || cd + atom[check[ny][nx]].dir == 5) {		//반대 원자와 충돌
						explode[check[ny][nx]] = true;
						explode[i] = true;
						check[ny][nx] = 0;
						continue;
					}
				}
				if (next_check[ny][nx] == 0)		//다음에 배칠될 곳에 미리 배치된 원자가 없다
					next_check[ny][nx] = i;
				else if (next_check[ny][nx] != 0) {
					explode[next_check[ny][nx]] = true;
					explode[i] = true;
				}
			}
			for (int i = 1; i <= num; i++) {
				int cx = atom[i].x;
				int cy = atom[i].y;
				next_check[cy][cx] = 0;
				if (!explode[i])
					check[cy][cx] = i;
			}
			tt++;
		}
		for (int i = 1; i <= num; i++) {
			if (explode[i])
				result += atom[i].val;
		}
		cout << "#" << t << " " << result << endl;
	}
	system("pause");
	return 0;
}