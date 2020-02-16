#include <iostream>
#include <string.h>
using namespace std;
char arr[501][501];
bool check[501][501][4];
int dir[4];
int row, col, result = 0;
char d;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

void start(int y, int x, int di) {
	int sum = 1;
	memset(check, false, sizeof(check));
	check[y][x][di] = true;
	int cy,cx,cd;
	cx = x;	cy = y; cd = di;
	while (1) {
		cx += dx[cd];
		cy += dy[cd];
		if (cx > 0 && cy > 0 && cx <= col && cy <= row) {
			if (check[cy][cx][cd]) {
				sum = -1;
				break;
			}
			if (arr[cy][cx] == 'C') break;
			else if (arr[cy][cx] == '/') {
				if (cd == 0) cd = 1;
				else if (cd == 1) cd = 0;
				else if (cd == 2) cd = 3;
				else if (cd == 3) cd = 2;
			}
			else if (arr[cy][cx] == '\\') {
				if (cd == 0) cd = 3;
				else if (cd == 1) cd = 2;
				else if (cd == 2) cd = 1;
				else if (cd == 3) cd = 0;
			}
			sum++;
			check[cy][cx][cd] = true;
		}
		else
			break;
	}
	dir[di] = sum;
}

int main() {
	int sx, sy;
	cin >> row >> col;
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++)
			cin >> arr[i][j];
	cin >> sy >> sx;
	char c;
	result = 0;
	for (int i = 0; i < 4; i++) {
		start(sy, sx, i);
		if (dir[i] == -1) {
			if (i == 0) c = 'U';
			else if (i == 1) c = 'R';
			else if (i == 2) c = 'D';
			else if (i == 3) c = 'L';
			result = -1;
			break;
		}
		else {
			if (dir[i] > result) {
				result = dir[i];
				if (i == 0) c = 'U';
				else if (i == 1) c = 'R';
				else if (i == 2) c = 'D';
				else if (i == 3) c = 'L';
			}
		}
	}
	if (result == -1) cout << c << endl << "Voyager";
	else 
		cout << c << endl << result;
	
	system("pause");
	return 0;
}