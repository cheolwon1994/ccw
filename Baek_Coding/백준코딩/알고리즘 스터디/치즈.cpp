#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;
int arr[102][102];
int check[102][102];

struct info {
	int x, y, val;
};
info tmp;
int row, col, result = 0;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int order[6][2] = { {0,1},{0,2},{0,3},{1,2},{1,3},{2,3} };
int main() {
	cin >> row >> col;
	for (int i = 1; i <= row; i++) 
		for (int j = 1; j <= col; j++) 
			cin >> arr[i][j];
		
	queue<info> q;
	while (1) {		
		//외부검사 -> 내부 검사
		for (int i = 1; i <= row; i++)
			for (int j = 1; j <= col; j++) {
				if (arr[i][j] == 1) {
					tmp.x = j;
					tmp.y = i;
					q.push(tmp);
				}
			}
		if (q.empty()) break;

		memset(check, 0, sizeof(check));
		int cnt = 1;
		for (int i = 0; i <= row+1; i++) {
			for (int j = 0; j <= col+1; j++) {
				if (check[i][j] == 0 && arr[i][j] == 0) {
					queue<info> air;
					tmp.x = j;
					tmp.y = i;
					tmp.val = cnt;
					air.push(tmp);
					check[i][j] = cnt++;
					while (!air.empty()) {
						int cx = air.front().x;
						int cy = air.front().y;
						int cv = air.front().val;
						air.pop();
						for (int k = 0; k < 4; k++) {
							int nx = cx + dx[k];
							int ny = cy + dy[k];
							if (nx >= 0 && ny >= 0 && nx <= col+1 && ny <= row+1 && check[ny][nx] == 0 && arr[ny][nx] == 0) {
								check[ny][nx] = cv;
								tmp.x = nx;
								tmp.y = ny;
								tmp.val = cv;
								air.push(tmp);
							}
						}

					}
				}
			}
		}

		while (!q.empty()) {
			int cx = q.front().x;
			int cy = q.front().y;
			q.pop();
			
			for (int i = 0; i < 6; i++) {
				int nx1 = cx + dx[order[i][0]];
				int ny1 = cy + dy[order[i][0]];
				int nx2 = cx + dx[order[i][1]];
				int ny2 = cy + dy[order[i][1]];
				bool out1 = false, out2 = false;
				if (nx1 == 0 || ny1 == 0 || nx1 > col || ny1 > row)
					out1 = true;
				if (nx2 == 0 || ny2 == 0 || nx2 > col || ny2 > row)
					out2 = true;
				if (out1 && out2) {		//외곽
					arr[cy][cx] = 0;
					break;
				}
				else if (!out1 && !out2) {
					if (arr[ny2][nx2] == 0 && arr[ny1][nx1] == 0 && check[ny2][nx2] ==1 && check[ny1][nx1]==1) {
						arr[cy][cx] = 0;
						break;
					}
				}
			}
		}
		result++;
	}
	cout << result;
	system("pause");
	return 0;
}