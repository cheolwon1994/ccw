#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
bool desert[101];
int arr[20][20];
bool check[20][20];
int d[4][4] = { {1,0,3,2},{1,2,3,0},{2,1,0,3},{2,3,0,1} };	//무조건 밑으로 가는걸 시작
int dx[4] = { 1,1,-1,-1 };
int dy[4] = { -1,1,1,-1 };
int num, result, tx, ty;

void start(int y, int x, int cnt, int dir, int dir_idx) {
	int cx, cy, nx, ny;
	cx = x;
	cy = y;
	nx = x + dx[d[dir][dir_idx]];
	ny = y + dy[d[dir][dir_idx]];
	if (nx >= 0 && ny >= 0 && nx < num && ny < num) {
		if (tx == nx && ty == ny) {
			result = max(result, cnt);
			return;
		}
		else if (!desert[arr[ny][nx]] && !check[ny][nx]) {
			desert[arr[ny][nx]] = true;
			check[ny][nx] = true;
			start(ny, nx, cnt + 1, dir, dir_idx);
			desert[arr[ny][nx]] = false;
			check[ny][nx] = false;
		}
	}
	if (dir_idx != 3) {
		nx = x + dx[d[dir][dir_idx + 1]];
		ny = y + dy[d[dir][dir_idx + 1]];
		if (nx >= 0 && ny >= 0 && nx < num && ny < num) {
			if (tx == nx && ty == ny) {
				result = max(result, cnt);
				return;				
			}
			else if (!desert[arr[ny][nx]] && !check[ny][nx]) {
				desert[arr[ny][nx]] = true;
				check[ny][nx] = true;
				start(ny, nx, cnt + 1, dir, dir_idx + 1);
				desert[arr[ny][nx]] = false;
				check[ny][nx] = false;
			}		
		}
	}
}


int main() {
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		//초기화
		result = -1;
		cin >> num;
		for (int i = 0; i < num; i++)
			for (int j = 0; j < num; j++)
				cin >> arr[i][j];
		for (int i = 0; i < num; i++) {
			for (int j = 0; j < num; j++) {
				if (i == 0 && (j == 0 || j==num-1))
					continue;
				else if (i == num - 1 && (j == 0 || j == num - 1))
					continue;
				else {
					for (int k = 0; k < num; k++)
						memset(check[k], false, sizeof(check[k]));
					memset(desert, false, sizeof(desert));
					tx = j;
					ty = i;
					check[i][j] = true;
					desert[arr[i][j]] = true;
					for (int k = 0; k < 4; k++)
						start(i, j, 1, k, 0);
				}
			}
		}
		cout << "#" << t << " " << result << endl;
	}
	system("pause");
	return 0;
}