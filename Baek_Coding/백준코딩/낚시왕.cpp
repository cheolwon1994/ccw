#define CRT_NO_SECURE_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

/***********************************************************************
(r, c)는 상어의 위치, s는 속력, d는 이동 방향, z는 크기이다.
d가 1인 경우는 위, 2인 경우는 아래, 3인 경우는 오른쪽, 4인 경우는 왼쪽
**********************************************************************/
struct info {
	int vel;
	int dir;
	int size;
};
info arr[101][101];
info dup[101][101];
int row, col, s_num;
int loc = 0;      //사람의 행위치
long long result = 0;
info tmp;

void move_shark() {
	info dup[101][101] = { 0 };
	int dist;
	int nx, ny;
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			if (arr[i][j].size != 0) {
				if (arr[i][j].dir <= 2) {		//위아래
					dist = arr[i][j].vel % (2 * (row - 1));
					ny = i;
					for (int k = 0; k < dist; k++) {
						if (arr[i][j].dir == 1) {		//위
							if (ny == 1) {
								ny += 1;
								arr[i][j].dir = 2;
							}
							else
								ny -= 1;
						}
						else {
							if (ny == row) {
								ny -= 1;
								arr[i][j].dir = 1;
							}
							else
								ny += 1;
						}
					}
					if(dup[ny][j].size < arr[i][j].size)
						dup[ny][j] = { arr[i][j].vel,arr[i][j].dir,arr[i][j].size };
				}
				else {			//오른왼쪽
					dist = arr[i][j].vel % (2 * (col - 1));
					nx = j;
					for (int k = 0; k < dist; k++) {		//오른왼						
						if (arr[i][j].dir == 3) {
							if (nx == col) {
								nx -= 1;
								arr[i][j].dir = 4;
							}
							else
								nx += 1;
						}
						else {
							if (nx == 1) {
								nx += 1;
								arr[i][j].dir = 3;
							}
							else
								nx -= 1;
						}
					}
					if(dup[i][nx].size < arr[i][j].size)
						dup[i][nx] = { arr[i][j].vel,arr[i][j].dir,arr[i][j].size };				
				}

			}
		}
	}	
	memcpy(arr, dup, sizeof(dup));
}

void catch_shark() {
	for (int i = 1; i <= row; i++) {
		if (arr[i][loc].size != 0) {
			result += arr[i][loc].size;
			arr[i][loc] = { 0,0,0 };
			break;
		}
	}
}

int main() {
	cin >> row >> col >> s_num;
	int r, c, s, d, z;		//행,열,속도,방향,크기
	for (int i = 0; i < s_num; i++) {
		cin >> r >> c >> s >> d >> z;
		arr[r][c] = { s,d,z };
	}
	while (loc < col) {
		loc++;
		catch_shark();
		move_shark();
	}
	cout << result;
	system("PAUSE");
	return 0;
}