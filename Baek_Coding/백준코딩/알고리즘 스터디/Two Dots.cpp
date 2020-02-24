#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;
struct info {
	int x, y;
	char c;
};
info tmp;
int row, col;
bool cycle = false;
char arr[50][50];
int check[50][50];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

void bfs(int y, int x) {
	queue<info> q;
	tmp.x = x;
	tmp.y = y;
	tmp.c = arr[y][x];
	check[y][x] = 1;
	q.push(tmp);
	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		char cc = q.front().c;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && ny >= 0 && nx < col && ny < row && arr[ny][nx] == cc) {
				if (check[ny][nx] == 0) {
					tmp.x = nx;
					tmp.y = ny;
					tmp.c = arr[ny][nx];
					q.push(tmp);
					check[ny][nx] = check[cy][cx] + 1;
				}
				else if (check[ny][nx] > check[cy][cx]) {
					if (check[ny][nx] + check[cy][cx] >= 4) {
						cycle = true;
						break;
					}
				}
			}
		}
		if (cycle)
			break;
	}
	
}

int main() {
	cin >> row >> col;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			cin >> arr[i][j];
	memset(check, 0, sizeof(check));
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			if (check[i][j] == 0) {
				bfs(i, j);
				if (cycle)
					break;
			}
		if (cycle) break;
	}
	if (cycle) cout << "Yes";
	else cout << "No";
	system("pause");
	return 0;
}