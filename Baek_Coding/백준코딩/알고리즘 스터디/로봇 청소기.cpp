#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int arr[50][50];
bool check[50][50];
int row, col, result = 0;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
bool finish = false;

void start(int y, int x, int dir) {
	if (finish)
		return;
	int nx, ny, nd;
	if (!check[y][x]) { check[y][x] = true; result++; }
	nd = dir;
	bool block = true;
	for (int i = 0; i < 4; i++) {
		nd = (nd + 3) % 4;
		nx = x + dx[nd];
		ny = y + dy[nd];
		if (nx > 0 && ny > 0 && nx < col && ny < row  && arr[ny][nx] == 0) {
			if (!check[ny][nx]) {
				block = false;
				start(ny, nx, nd);
				if (finish)
					break;
			}
		}
	}
	if (finish)
		return;
	if (block) {
		nd = (dir + 2) % 4;
		nx = x + dx[nd];
		ny = y + dy[nd];
		if (arr[ny][nx] == 0)
			start(ny, nx, dir);
		else {
			finish = true;
			return;
		}
	}
}

int main() {
	int y, x, dir;
	cin >> row >> col;
	cin >> y >> x >> dir;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			cin >> arr[i][j];
	for (int i = 0; i < row; i++)
		memset(check[i], false, sizeof(check[i]));
	start(y, x, dir);
	cout << result;
	system("pause");
	return 0;
}