#include <iostream>
#include <algorithm>
using namespace std;
int row, col, result = 0;
int arr[500][500];
bool check[500][500] = { false, };
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

void dfs(int y, int x, int cnt, int sum) {
	if (cnt == 4) {
		result = max(result, sum);
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < col && ny < row && !check[ny][nx]) {
			check[ny][nx] = true;
			dfs(ny, nx, cnt + 1, arr[ny][nx] + sum);
			check[ny][nx] = false;
		}
	}
}

void cal(int y, int x) {
	int tt;
	if (y - 1 >= 0 && y + 1 < row) {
		if (x + 1 < col) {
			tt = arr[y][x] + arr[y - 1][x] + arr[y + 1][x] + arr[y][x + 1];
			result = max(result, tt);
		}
		if (x - 1 >= 0) {
			tt = arr[y][x] + arr[y - 1][x] + arr[y + 1][x] + arr[y][x - 1];
			result = max(result, tt);
		}
	}
	if (x - 1 >= 0 && x + 1 < col) {
		if (y + 1 < row) {
			tt = arr[y][x] + arr[y + 1][x] + arr[y][x - 1] + arr[y][x + 1];
			result = max(result, tt);
		}
		if (y - 1 >= 0) {
			tt = arr[y][x] + arr[y - 1][x] + arr[y][x - 1] + arr[y][x + 1];
			result = max(result, tt);
		}
	}
}

int main() {
	cin >> row >> col;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			cin >> arr[i][j];
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			check[i][j] = true;
			dfs(i, j, 1, arr[i][j]);
			cal(i, j);
			check[i][j] = false;
		}
	}
	cout << result;
	system("pause");
	return 0;
}