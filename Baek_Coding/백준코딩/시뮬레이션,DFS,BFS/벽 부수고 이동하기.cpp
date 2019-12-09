#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
int row, col;
struct info {
	int x;
	int y;
	int wall;
};
info tmp;
queue<info> q;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int arr[1001][1001];
int check[2][1001][1001];
int cx, cy, cv, nx, ny, cw;
int main() {
	string str;
	int result = 0;
	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		cin >> str;
		for (int j = 0; j < col; j++)
			arr[i][j] = str[j]-'0';
	}
	tmp.x = 0;
	tmp.y = 0;
	tmp.wall = 0;
	check[0][0][0] = 1;
	q.push(tmp);
	bool flag = false;
	if (row == 1 && col == 1) 
		cout << 1;
	else {
		while (!q.empty()) {
			cx = q.front().x;
			cy = q.front().y;
			cw = q.front().wall;
			q.pop();
			for (int i = 0; i < 4; i++) {
				nx = cx + dx[i];
				ny = cy + dy[i];
				if (nx >= 0 && ny >= 0 && nx < col && ny < row && check[cw][ny][nx] == 0) {
					if (ny == row - 1 && nx == col - 1) {
						flag = true;
						result = check[cw][cy][cx] + 1;
						break;
					}
					if (arr[ny][nx] == 0) {
						check[cw][ny][nx] = check[cw][cy][cx] + 1;
						tmp.x = nx;
						tmp.y = ny;
						tmp.wall = cw;
						q.push(tmp);
					}
					else if (arr[ny][nx] == 1 && cw == 0) {
						check[1][ny][nx] = check[cw][cy][cx] + 1;
						tmp.x = nx;
						tmp.y = ny;
						tmp.wall = 1;
						q.push(tmp);
					}
				}
			}
			if (flag)
				break;
		}
		if (flag)
			cout << result;
		else
			cout << -1;
	}
	system("pause");
	return 0;
}