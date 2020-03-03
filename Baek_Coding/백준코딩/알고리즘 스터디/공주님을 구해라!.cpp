#define MAX 987654321
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
struct info {
	int x, y, sword, val;
};
info tmp;
int arr[100][100];
bool check[100][100][2] = { false, };
int row, col, limit, result = MAX;

void bfs() {
	queue<info> q;
	tmp.sword = 0;
	tmp.x = 0;
	tmp.y = 0;
	tmp.val = 0;
	q.push(tmp);
	check[0][0][0] = true;
	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		int cv = q.front().val;
		int cs = q.front().sword;
		q.pop();
		if (arr[cy][cx] == 2) 	cs = 1;
		if (cy == row - 1 && cx == col - 1) {
			result = cv;
			break;
		}
		if (cv >= limit) continue;
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && ny >= 0 && nx < col && ny < row && !check[ny][nx][cs]) {
				if (arr[ny][nx] == 2 || arr[ny][nx] == 0 || (arr[ny][nx] == 1 && cs == 1)) {
					check[ny][nx][cs] = true;
					tmp.x = nx;
					tmp.y = ny;
					tmp.val = cv + 1;
					tmp.sword = cs;
					q.push(tmp);
				}
			}
		}
	}
}

int main() {
	cin >> row >> col >> limit;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			cin >> arr[i][j];
	bfs();
	if (result == MAX) cout << "Fail";
	else cout << result;
	system("pause");
	return 0;
}