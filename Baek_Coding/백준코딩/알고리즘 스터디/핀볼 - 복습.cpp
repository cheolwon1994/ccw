#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;
int arr[102][102];
bool check[102][102][4];
int num, sx, sy,sd, result;
int block[6][4] = { {},{2,3,1,0},{1,3,0,2},{3,2,0,1},{2,0,3,1},{2,3,0,1} };
struct info {
	int x, y, dir, val, origin;
};
info tmp;
vector<info> warmhole[5];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
void start(int y, int x) {
	queue<info> q;
	tmp.x = x;
	tmp.y = y;
	tmp.val = 0;
	tmp.origin = true;
	for (int i = 0; i < 4; i++) {
		tmp.dir = i;
		q.push(tmp);
	}
	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		int cv = q.front().val;
		int cd = q.front().dir;
		int co = q.front().origin;
		q.pop();
		if ((cy == sy && cx == sx && !co) || arr[cy][cx] == -1) {		//시작자리로 온 경우, 블랙홀에 빠진 경우
			result = max(result, cv);
			continue;
		}
		if (check[cy][cx][cd]) { //이미 같은 경로로 온 경우가 있을 때
			result = max(result, cv);
			continue;
		}
		check[cy][cx][cd] = true;
		int nx = cx + dx[cd];
		int ny = cy + dy[cd];
		int val = arr[ny][nx];
		tmp.x = nx;
		tmp.y = ny;
		tmp.origin = false;
		tmp.val = cv;
		tmp.dir = cd;
		if (val == 0 || val == -1) {
			q.push(tmp);
		}
		else if (1 <= val && val <= 5) {		//블록
			int nd = block[val][cd];
			tmp.val = cv + 1;
			tmp.dir = nd;
			q.push(tmp);
		}
		else {			//웜홀
			if (nx == warmhole[val - 6][0].x && ny == warmhole[val - 6][0].y) {
				tmp.x = warmhole[val - 6][1].x;
				tmp.y = warmhole[val - 6][1].y;
			}
			else {
				tmp.x = warmhole[val - 6][0].x;
				tmp.y = warmhole[val - 6][0].y;
			}	
			q.push(tmp);
		}
	}
}

int main() {
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		cin >> num;
		//초기화 및 생성
	
		for (int i = 0; i < 5; i++)
			warmhole[i].clear();
		result = 0;
		for(int i=0;i<num+2;i++)
			for (int j = 0; j < num + 2; j++) {
				if (i == 0 || i == num + 1 || j == 0 || j == num + 1) {	arr[i][j] = 5; continue;}
				cin >> arr[i][j];
				if (arr[i][j] > 5) {
					tmp.x = j;
					tmp.y = i;
					warmhole[arr[i][j]-6].push_back(tmp);
				}
			}
		for(int i=1;i<=num;i++)
			for (int j = 1; j <= num; j++) {
				if (arr[i][j] == 0) {
					memset(check, false, sizeof(check));
					sx = j;	sy = i;
					start(i, j);
				}			
			}
		cout << "#" << t << " " << result << '\n';
	}
	system("pause");
	return 0;
}