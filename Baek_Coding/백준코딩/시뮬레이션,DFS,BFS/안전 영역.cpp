#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;
int arr[100][100];
int check[100][100];
int num;
int result = 1;
int mini = 101;
int maxi = 0;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
struct info {
	int x;
	int y;
};
info tmp;
queue<info> q;

int main() {
	cin >> num;
	int cx, cy, nx, ny, area;
	for (int i = 0; i < num; i++)
		for (int j = 0; j < num; j++) {
			cin >> arr[i][j];
			mini = min(mini, arr[i][j]);
			maxi = max(maxi, arr[i][j]);
		}
	//cout << maxi << " " << mini;
	for (int t = mini; t <= maxi; t++) {
		for (int i = 0; i < num; i++)
			memset(check[i], 0, sizeof(check[i]));
		area = 0;
		for (int i = 0; i < num; i++) {
			for (int j = 0; j < num; j++) {
				if (arr[i][j] - t > 0 && check[i][j]!=1) {
					tmp.x = j;
					tmp.y = i;
					q.push(tmp);
					check[i][j] = 1;
					while (!q.empty()) {
						cx = q.front().x;
						cy = q.front().y;
						q.pop();
						for (int k = 0; k < 4; k++) {
							nx = cx + dx[k];
							ny = cy + dy[k];
							if (nx >= 0 && ny >= 0 && nx < num && ny < num) {
								if (check[ny][nx] != 1 && arr[ny][nx]-t>0) {
									tmp.x = nx;
									tmp.y = ny;
									q.push(tmp);
									check[ny][nx] = 1;
								}
							}
						}
					}
					area += 1;
				}
			}
		}
		result = max(result, area);
	}
	cout << result;
	system("pause");
	return 0;
}