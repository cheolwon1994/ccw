#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int arr[8][8];
int check[8][8];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int num, mh, result, maxi, sx, sy;

void dfs(int y, int x, int cnt, int ch, bool dig) {
	int cx, cy, ny, nx;
	cx = x;
	cy = y;
	for (int i = 0; i < 4; i++) {
		nx = cx + dx[i];
		ny = cy + dy[i];
		if (nx >= 0 && ny >= 0 && nx < num && ny < num) {
			if (nx == sx && ny == sy)
				continue;
			if (dig == true) {		//더이상 공사 불가
				if (arr[ny][nx] >= ch)
					continue;
				else if (arr[ny][nx] < ch && check[ny][nx] == 0) {
					int t = check[ny][nx];
					check[ny][nx] = cnt + 1;
					dfs(ny, nx, cnt + 1, arr[ny][nx], dig);
					check[ny][nx] = t;
				}
			}
			else if (!dig) {		//공사가 가능한 경우
				if (arr[ny][nx] < ch && check[ny][nx] == 0) {
					int t = check[ny][nx];
					check[ny][nx] = cnt + 1;
					dfs(ny, nx, cnt + 1, arr[ny][nx], dig);
					check[ny][nx] = t;
				}
				else if (arr[ny][nx] >= ch) {
					for (int j = 1; j <= mh; j++) {
						if (ch + j > arr[ny][nx] && check[ny][nx] == 0) {
							int t = check[ny][nx];
							int pre_arr = arr[ny][nx];
							check[ny][nx] = cnt + 1;
							arr[ny][nx] -= j;
							dfs(ny, nx, cnt + 1, arr[ny][nx], true);
							arr[ny][nx] = pre_arr;
							check[ny][nx] = t;
						}
					}
				}
			}
		}
	}
	result = max(result, cnt);
	return;
}

int main() {
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		cin >> num >> mh;
		//초기화
		result = 0;
		maxi = 0;
		for (int i = 0; i < num; i++)
			for (int j = 0; j < num; j++) {
				cin >> arr[i][j];
				if (arr[i][j] > maxi)
					maxi = arr[i][j];
			}
		for (int i = 0; i < num; i++)
			for (int j = 0; j < num; j++) {
				if (arr[i][j] == maxi) {
					for (int k = 0; k < num; k++)
						memset(check[k], 0, sizeof(check[k]));
					check[i][j] = 1;
					sx = j;
					sy = i;
					dfs(i, j, 1, maxi, false);
				}
			}
		cout << "#" << t << " " << result << endl;
	}
	system("pause");
	return 0;
}