#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
int row, col;
int arr[50][50];
bool check[50][50];
int dx[8] = { 0,1,1,1,0,-1,-1,-1 };
int dy[8] = { -1,-1,0,1,1,1,0,-1 };
struct info {
	int x, y;
};
info tmp;
int main() {
	int cx, cy, nx, ny;
	while (1) {
		cin >> col >> row;
		if (row == 0 && col == 0)
			break;
		for (int i = 0; i < row; i++)
			memset(check[i], false, sizeof(check[i]));

		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				cin >> arr[i][j];
		int cnt = 0;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (arr[i][j] == 1 && !check[i][j]) {
					queue<info> q;
					tmp.x = j;
					tmp.y = i;
					q.push(tmp);
					check[i][j] = true;
					++cnt;
					while (!q.empty()) {
						cx = q.front().x;
						cy = q.front().y;
						q.pop();
						for (int k = 0; k < 8; k++) {
							nx = cx + dx[k];
							ny = cy + dy[k];
							if (nx >= 0 && ny >= 0 && ny < row && nx < col && !check[ny][nx] && arr[ny][nx] == 1) {
								check[ny][nx] = true;
								tmp.x = nx;
								tmp.y = ny;
								q.push(tmp);
							}
						}
					}
				}
			}
		}
		cout << cnt << endl;
	}
	system("pause");
	return 0;
}