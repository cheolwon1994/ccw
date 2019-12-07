#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int arr[50][50];
int row, col;
int clean_num = 0;

void clean_cur_pos(int y, int x, int dir) {			//현재 위치 청소
	if (arr[y][x] == 0) {
		arr[y][x] = 2;
		clean_num++;
	}
	int ny, nx, nd;
	nd = dir;
	int flag = 0;
	for (int i = 0; i <= 4; i++) {
		if (i == 4)			//2.c or 2.d
			flag = 2;
		nd = (nd + 3) % 4;		//왼쪽
		ny = y + dy[nd];
		nx = x + dx[nd];
		if (ny >= 0 && nx >= 0 && ny < row && nx < col) {
			if (arr[ny][nx] == 0) {		//2.a
				flag = 1;
				break;
			}
		}
	}
	if (flag == 1)		//2.a
		clean_cur_pos(ny, nx, nd);
	else if(flag == 2) {		//2.c or 2.d
		int dir_back;
		dir_back = (dir + 2) % 4;
		ny = y + dy[dir_back];
		nx = x + dx[dir_back];
		if (ny >= 0 && nx >= 0 && ny < row && nx < col) {
			if (arr[ny][nx] != 1)			//2.c
				clean_cur_pos(ny, nx, dir);
		}
		else if (arr[ny][nx] == 1 || ny<0 || nx<0 || ny>=row || nx>=col)		//2.d
			return;
	}
}

int main() {
	int x, y, dir;
	cin >> row >> col;
	cin >> y >> x >> dir;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> arr[i][j];
		}
	}
	clean_cur_pos(y, x, dir);
	cout << clean_num << endl;
	system("pause");
	return 0;
}