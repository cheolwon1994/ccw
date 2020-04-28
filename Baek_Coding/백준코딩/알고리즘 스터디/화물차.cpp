#define MAX 987654321
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct info {
	int x, y, val;
};
struct info2 {
	int a, b, x, y;		//좌우,상하
};
info tmp;
info2 tmp2;
char arr[20][20];
int check[20][20];
vector<info2> v;
int row, col, result, idx, a, b;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int x[10], y[10];

int main() {
	while (1) {
		cin >> row >> col;
		if (row == 0 && col == 0) break;
		bool finish = false;
		queue<info> q;
		int cnt = 0;
		result = MAX;
		v.clear();
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++) {
				check[i][j] = MAX;
				cin >> arr[i][j];
				if (arr[i][j] == 'A') {
					tmp.x = j;
					tmp.y = i;
					tmp.val = 0;
					q.push(tmp);
					check[i][j] = 0;							
				}
				else if (0 <= arr[i][j] - '0' && arr[i][j] - '0' <= 9) {
					cnt++;
					x[arr[i][j] - '0'] = j;
					y[arr[i][j] - '0'] = i;
				}
			}
		char c;
		for (int i = 0; i < cnt; i++) {
			cin >> idx >> c >> a >> b;
			tmp2.x = x[i];
			tmp2.y = y[i];
			if (c == '-') {
				tmp2.a = a;
				tmp2.b = b;
			}
			else {
				tmp2.b = a;
				tmp2.a = b;
			}
			arr[y[i]][x[i]] = c;
			v.push_back(tmp2);
		}

		int tt = 0;		//다음 이동하려는 칸의 시간
		while (!q.empty()) {
			int len = q.size();			
			//교차로 신호등 변화
			if (tt != 0) {
				for (int i = 0; i < cnt; i++) {
					int val = tt % (v[i].a + v[i].b);
					int cx = v[i].x;
					int cy = v[i].y;
					if (val == 0 || val == v[i].a) {
						if (arr[cy][cx] == '-')
							arr[cy][cx] = '|';
						else
							arr[cy][cx] = '-';
					}
				}
			}

			for (int i = 0; i < len; i++) {
				int cx = q.front().x;
				int cy = q.front().y;
				int cv = q.front().val;
				q.pop();
				if (arr[cy][cx] == 'B') {
					result = min(result, cv);
					finish = true;
					continue;
				}
				for (int k = 0; k < 4; k++) {
					int nx = cx + dx[k];
					int ny = cy + dy[k];
					if (nx >= 0 && ny >= 0 && nx < col && ny < row && arr[ny][nx] != '.') {
						if ((arr[ny][nx] == '#' || arr[ny][nx] == 'B') && check[ny][nx] > cv + 1) {
							check[ny][nx] = cv + 1;
							tmp.x = nx;
							tmp.y = ny;
							tmp.val = cv + 1;
							q.push(tmp);
						}
						else if (arr[ny][nx] == '-' && check[ny][nx] > cv + 1) {		
							if (k == 1 || k == 3) {		//교차로에 진입 가능한 경우
								check[ny][nx] = cv + 1;
								tmp.x = nx;
								tmp.y = ny;
								tmp.val = cv + 1;
								q.push(tmp);
							}
							else if (k == 0 || k == 2) {	//교차로에 진입 불가능한 경우
								tmp.x = cx;
								tmp.y = cy;
								tmp.val = cv + 1;
								q.push(tmp);
							}
						}
						else if (arr[ny][nx] == '|' && check[ny][nx] > cv + 1) {
							if (k == 0 || k == 2) {		//교차로에 진입 가능한 경우
								check[ny][nx] = cv + 1;
								tmp.x = nx;
								tmp.y = ny;
								tmp.val = cv + 1;
								q.push(tmp);
							}
							else if (k == 1 || k == 3) {	//교차로에 진입 불가능한 경우
								tmp.x = cx;
								tmp.y = cy;
								tmp.val = cv + 1;
								q.push(tmp);
							}
						}
					}
				}
			}
			tt++;
		}
		if (!finish) cout << "impossible\n";
		else cout << result << '\n';
	}
	return 0;
}