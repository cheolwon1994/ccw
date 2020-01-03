#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;
int arr[50][50];
int check[50][50];
bool avail[8][4] = { {0,0,0,0}, {1,1,1,1}, {1,0,1,0},{0,1,0,1},{1,1,0,0},{0,1,1,0},{0,0,1,1},{1,0,0,1} };
struct info {
	int x, y, t;
};
info tmp;
int row, col, tt, tx, ty, result;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

void ans() {
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			if (check[i][j] == 1)
				result++;
}
void bfs() {
	queue<info> q;
	tmp.x = tx;
	tmp.y = ty;
	tmp.t = 1;
	q.push(tmp);
	int cx, cy, ct, nx, ny, ca, na;
	while (!q.empty()) {
		cx = q.front().x;
		cy = q.front().y;
		ct = q.front().t;
		ca = arr[cy][cx];
		q.pop();
		if (ct == tt)
			continue;
		for (int i = 0; i < 4; i++) {
			bool flag = false;
			nx = cx + dx[i];
			ny = cy + dy[i];
			na = arr[ny][nx];
			if (nx >= 0 && ny >= 0 && nx < col && ny < row && check[ny][nx] == 0 && avail[ca][i] == 1 && na>0) {
				if (i == 0 && avail[na][2] == 1)
					flag = true;
				else if (i == 1 && avail[na][3] == 1)
					flag = true;
				else if (i == 2 && avail[na][0] == 1)
					flag = true;
				else if (i == 3 && avail[na][1] == 1)
					flag = true;
			}
			if (flag) {
				tmp.x = nx;
				tmp.y = ny;
				tmp.t = ct + 1;
				check[ny][nx] = 1;
				q.push(tmp);
			}
		}
	}
	ans();
}

int main() {
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		cin >> row >> col >> ty >> tx >> tt;
		//√ ±‚»≠
		result = 0;
		for (int i = 0; i < row; i++) {
			memset(check[i], 0, sizeof(check[i]));
			memset(arr[i], 0, sizeof(arr[i]));
		}
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				cin >> arr[i][j];
		check[ty][tx] = 1;
		bfs();
		cout << "#" << t << " " << result << endl;

	}
	system("pause");
	return 0;
}