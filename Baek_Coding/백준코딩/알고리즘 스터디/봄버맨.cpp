#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
int row, col, limit, t = 0;
char arr[200][200];
int bomb[200][200];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

int main() {
	cin >> row >> col >> limit;
	int nx, ny;
	for (int i = 0; i < row; i++)
		memset(bomb[i], -1, sizeof(bomb[i]));
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'O')
				bomb[i][j] = t + 3;
		}
	while (t < limit) {
		t++;
		if (t % 2 != 1)	{
			for (int i = 0; i < row; i++) {		//ÆøÅº Ãß°¡
				for (int j = 0; j < col; j++) {
					if (arr[i][j] == '.') {
						arr[i][j] = 'O';
						bomb[i][j] = t + 3;
					}
				}
			}
		}
		for (int i = 0; i < row; i++) {		//ÅÍÆ®¸®´Â °úÁ¤
			for (int j = 0; j < col; j++) {
				if (bomb[i][j] == t && arr[i][j] == 'O') {
					bomb[i][j] = 0;
					arr[i][j] = '.';
					for (int k = 0; k < 4; k++) {
						nx = j + dx[k];
						ny = i + dy[k];
						if (nx >= 0 && ny >= 0 && nx < col && ny < row && bomb[ny][nx] != t) {
							arr[ny][nx] = '.';
							bomb[ny][nx] = 0;
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			cout << arr[i][j];
		cout << endl;
	}
	system("pause");
	return 0;
}