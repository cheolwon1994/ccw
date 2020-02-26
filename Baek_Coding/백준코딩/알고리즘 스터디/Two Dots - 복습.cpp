#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;
struct info {
	int x, y;
};
info tmp;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
char arr[50][50];
int check[50][50];
bool finish = false;
int row, col;

void bfs(int y, int x) {
	queue<info> q;
	tmp.x = x;
	tmp.y = y;
	q.push(tmp);
	check[y][x] = 1;
	bool avail = false;
	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (nx >= 0 && ny >= 0 && ny < row && nx < col && arr[ny][nx] == arr[y][x]) {
				if (check[ny][nx] == 0) {
					check[ny][nx] = check[cy][cx] + 1;
					tmp.x = nx;
					tmp.y = ny;
					q.push(tmp);
				}
				else if (check[ny][nx] > check[cy][cx]) {
					avail = true;
					break;
				}
			}
		}
		if (avail)
			break;
	}
	if (avail)
		finish = true;
}

int main() {
	cin >> row >> col;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			cin >> arr[i][j];
	memset(check, 0, sizeof(check));
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (check[i][j] == 0) {
				bfs(i, j);
				if (finish) break;
			}
		}
		if (finish) break;
	}
	if (finish) cout << "Yes";
	else cout << "No";
	system("pause");
	return 0;
}