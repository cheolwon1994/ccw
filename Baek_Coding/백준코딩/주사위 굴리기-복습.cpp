#include <iostream>
using namespace std;
int arr[20][20];
int row, col, order, sx, sy, val;
int dice[6] = { 0,0,0,0,0,0 };
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };

void mv(int dir) {
	if (dir == 0) {				//동쪽
		int tt = dice[3];
		dice[3] = dice[2]; 
		dice[2] = dice[1]; 
		dice[1] = dice[5]; 
		dice[5] = tt;
	}
	else if (dir == 1) {			//서쪽
		int tt = dice[1];
		dice[1] = dice[2];
		dice[2] = dice[3];
		dice[3] = dice[5];
		dice[5] = tt;
	}
	else if (dir == 2) {			//북쪽
		int tt = dice[2];
		dice[2] = dice[4];
		dice[4] = dice[5];
		dice[5] = dice[0];
		dice[0] = tt;
	}
	else {					//남쪽
		int tt = dice[5];
		dice[5] = dice[4];
		dice[4] = dice[2];
		dice[2] = dice[0];
		dice[0] = tt;
	}
}

int main() {
	cin >> row >> col >> sy >> sx >> order;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			cin >> arr[i][j];

	for (int t = 0; t < order; t++) {
		cin >> val;
		val -= 1;
		int nx = sx + dx[val];
		int ny = sy + dy[val];
		if (nx >= 0 && ny >= 0 && nx < col && ny < row) {
			mv(val);		//방향바꾸기
			sx = nx;
			sy = ny;
			if (arr[sy][sx] == 0)
				arr[sy][sx] = dice[5];
			else {
				dice[5] = arr[sy][sx];
				arr[sy][sx] = 0;
			}
			cout << dice[2] << '\n';
		}
		else continue;		//범위밖으로 나가는것은 무시
	}
	system("pause");
	return 0;
}