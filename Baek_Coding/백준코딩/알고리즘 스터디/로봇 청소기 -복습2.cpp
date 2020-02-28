#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int row, col, result = 0;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
struct info {
	int x, y;
};
info tmp;
int arr[50][50];
bool finish = false;

void start(int y, int x, int dir, int sum) {
	if (finish) return;
	int clean = 0;
	if (arr[y][x] == 0) {		//1. 수행
		clean = 1;
		arr[y][x] = 2;
	}
	int cd = dir;
	bool clean_avail = false;
	for (int i = 0; i < 4; i++) {		//2.a~2.b 수행
		cd = (cd + 3) % 4;
		int nd = cd;
		int nx = x + dx[nd];
		int ny = y + dy[nd];
		if (nx >= 0 && ny >= 0 && nx < col && ny < row && arr[ny][nx]==0) {
			clean_avail = true;
			start(ny, nx, nd, sum + clean);
		}
	}
	if (!clean_avail) {
		cd = (dir + 2) % 4;
		int nx = x + dx[cd];
		int ny = y + dy[cd];
		if (arr[ny][nx] == 1) {
			finish = true;
			result = max(result, sum + clean);
			return;
		}
		else 
			start(ny, nx, dir, sum + clean);		
	}
}

int main() {
	int sx, sy, sd;
	cin >> row >> col >> sy >> sx >> sd;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			cin >> arr[i][j];
	start(sy, sx, sd, 0);
	cout << result;
	system("pause");
	return 0;
}