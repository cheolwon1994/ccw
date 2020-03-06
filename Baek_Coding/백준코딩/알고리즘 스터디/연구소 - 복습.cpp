#include <iostream>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;
int row, col, result = 0;
int arr[8][8];
int dup[8][8];

struct info {
	int x, y;
};
info tmp;
queue<info> virus;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

void bfs() {
	queue <info> q;
	q = virus;
	memcpy(dup, arr, sizeof(dup));
	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && ny >= 0 && nx < col && ny < row && dup[ny][nx]==0) {
				dup[ny][nx] = 2;
				tmp.x = nx;
				tmp.y = ny;
				q.push(tmp);
			}
		}
	}
	int t_result = 0;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			if (dup[i][j] == 0)
				t_result++;
	result = max(result, t_result);
}

void dfs(int y, int x, int cnt) {
	if (cnt == 3) {
		bfs();
		return;
	}
	if (x == col) {
		x = 0;
		y += 1;
	}
	if (y == row) return;
	if (arr[y][x] == 0) {
		arr[y][x] = 1;
		dfs(y, x + 1, cnt + 1);
		arr[y][x] = 0;
	}
	dfs(y, x + 1, cnt);
}

int main() {
	cin >> row >> col;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				tmp.x = j;
				tmp.y = i;
				virus.push(tmp);
			}
		}
	dfs(0, 0, 0);
	cout << result;
	system("pause");
	return 0;
}