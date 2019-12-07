#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;
int arr[100][100];
int check[100][100];
int num;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
struct info {
	int x;
	int y;
	int val;
	int dist = 0;
};
info tmp;
queue<info> q;
int result = 10000;
int main() {
	cin >> num;
	int flag = 0;
	int cx, cy, cv, nx, ny;
	for (int i = 0; i < num; i++)
		for (int j = 0; j < num; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1)
				arr[i][j] = -1;
		}
	for(int i=0;i<num;i++)
		for(int j=0;j<num;j++)
			if (arr[i][j] == -1 && check[i][j] != 1) {
				tmp.x = j;
				tmp.y = i;
				tmp.val = ++flag;
				arr[i][j] = flag;
				check[i][j] = 1;
				q.push(tmp);
				while (!q.empty()) {
					cx = q.front().x;
					cy = q.front().y;
					cv = q.front().val;
					q.pop();
					for (int k = 0; k < 4; k++) {
						nx = cx + dx[k];
						ny = cy + dy[k];
						if (nx >= 0 && ny >= 0 && nx < num && ny < num) {
							if (arr[ny][nx] == -1 && check[ny][nx] != 1) {
								check[ny][nx] = 1;
								tmp.x = nx;
								tmp.y = ny;
								tmp.val = flag;
								arr[ny][nx] = flag;
								q.push(tmp);
							}
						}
					}
				}
			}
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			if (arr[i][j] != 0) {
				bool test = false;
				for (int k = 0; k < 4; k++) {
					nx = j + dx[k];
					ny = i + dy[k];
					if (nx >= 0 && ny >= 0 && nx < num && ny < num && arr[ny][nx] != arr[i][j]) {
						test = true;
						break;
					}
				}
				if (test) {
					for (int k = 0; k < num; k++)
						for (int m = 0; m < num; m++)
							check[k][m] = 0;
					tmp.x = j;
					tmp.y = i;
					tmp.val = arr[i][j];
					tmp.dist = 0;
					check[i][j] = 1;
					q.push(tmp);
					int cd;
					bool found = false;
					while (!q.empty()) {
						cx = q.front().x;
						cy = q.front().y;
						cv = q.front().val;
						cd = q.front().dist;
						q.pop();
						for (int k = 0; k < 4; k++) {
							nx = cx + dx[k];
							ny = cy + dy[k];
							if (nx >= 0 && ny >= 0 && nx < num && ny < num && check[ny][nx] != 1) {
								if (arr[ny][nx] == 0) {
									tmp.x = nx;
									tmp.y = ny;
									tmp.val = cv;
									tmp.dist = cd + 1;
									q.push(tmp);
									check[ny][nx] = 1;
								}
								else if (arr[ny][nx] != cv) {
									found = true;
									cd + 1;
									break;
								}
							}
						}
						if (found)
							break;
					}
					if (found) {
						while (!q.empty())
							q.pop();
						result = min(result, cd);
					}
				}	
			}
		}
	}
	cout << result;
	system("pause");
	return 0;
}