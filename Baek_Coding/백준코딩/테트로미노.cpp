#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
int row, col;
int arr[500][500];
int check[500][500];
int result = -1;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

struct info {
	int x;
	int y;
};
info tmp;

void tet2(int y, int x) {
	int cy = y;
	int cx = x;
	int ny, nx;
	for (int i = 0; i < 4; i++) {
		int temp = arr[cy][cx];
		for (int j = 0; j < 3; j++) {
			ny = cy + dy[(i + j)%4];
			nx = cx + dx[(i + j)%4];
			if (ny >= 0 && nx >= 0 && ny < row && nx < col) {
				temp += arr[ny][nx];
			}
		}
		result = max(result, temp);
	}
}

void tet(vector<info> v, int cnt) {			
	if (cnt == 4) {
		int temp = 0;
		for (int i = 0; i < 4; i++)
			temp += arr[v[i].y][v[i].x];
		result = max(result, temp);
		return;
	}
	int cy = v[cnt - 1].y;
	int cx = v[cnt - 1].x;
	int ny, nx;
	for (int i = 0; i < 4; i++) {
		ny = cy + dy[i];
		nx = cx + dx[i];
		if (ny >= 0 && nx >= 0 && nx < col && ny < row) {
			if (check[ny][nx] != 1) {
				check[ny][nx] = 1;
				tmp.x = nx;
				tmp.y = ny;
				v.push_back(tmp);
				tet(v, cnt+1);
				check[ny][nx] = 0;
				v.pop_back();
			}
		}
	}
}

int main() {
	cin >> row >> col;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			cin >> arr[i][j];
	for (int k = 0; k < row; k++)
		memset(check[k], 0, sizeof(check[k]));

	for(int i=0;i<row;i++)
		for (int j = 0; j < col; j++) {
			vector<info> v;
			tmp.x = j;
			tmp.y = i;
			v.push_back(tmp);
			check[i][j] = 1;
			tet(v,1);
			tet2(i, j);
			check[i][j] = 0;
		}
	cout << result;
	system("pause");
	return 0;
}