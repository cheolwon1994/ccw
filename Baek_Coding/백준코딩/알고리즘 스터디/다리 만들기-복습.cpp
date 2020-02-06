#define MAX 3000
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int row, col, cnt = 1;
int arr[10][10];
struct info {
	int x, y;
};
info tmp;
deque<info> island[7];	//1~6¸¸ »ç¿ë
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int dist[7][7];
bool flag[7] = { false, };
int result = MAX;

void dfs(int num, int sum) {
	if (num == cnt - 1) {
		result = min(result, sum);
		return;
	}
	for (int i = 1; i < cnt; i++) {
		if (flag[i]) {
			for (int j = 1; j < cnt; j++) {
				if (i == j) continue;
				if (!flag[j] && dist[i][j] != MAX) {
					flag[j] = true;
					dfs(num + 1, sum + dist[i][j]);
					flag[j] = false;
				}
			}
		}
	}
}

void connect() {
	for (int i = 1; i < cnt; i++) 
		for (int j = 1; j < cnt; j++)
			dist[i][j] = MAX;
	deque<info> dq;
	int cx, cy, nx, ny;
	for (int i = 1; i < cnt; i++) {
		dq.clear();
		dq = island[i];
		while (!dq.empty()) {
			cx = dq[0].x;
			cy = dq[0].y;
			dq.pop_front();
			for (int k = 0; k < 4; k++) {
				nx = cx + dx[k];
				ny = cy + dy[k];
				if (nx >= 0 && ny >= 0 && nx < col && ny < row) {
					int tt = 1;
					if (arr[ny][nx] != 0) continue;
					while (1) {
						nx += dx[k];
						ny += dy[k];
						if (nx >= 0 && ny >= 0 && nx < col && ny < row) {
							if (arr[ny][nx] == 0) tt++;
							else if (arr[ny][nx] != arr[cy][cx]) {
								if (tt < 2) break;
								if (dist[arr[cy][cx]][arr[ny][nx]] > tt) {
									dist[arr[cy][cx]][arr[ny][nx]] = tt;
									dist[arr[ny][nx]][arr[cy][cx]] = tt;
								}
								break;
							}
							else if (arr[ny][nx] == arr[cy][cx]) break;
						}
						else
							break;
					}
				}
			}
		}
	}
	flag[1] = true;
	dfs(1,0);
}

void divide_island() {
	bool check[10][10] = { false, };
	int cx, cy, nx, ny;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (arr[i][j] == -1 && !check[i][j]) {
				queue<info> q;
				tmp.x = j;
				tmp.y = i;
				q.push(tmp);
				check[i][j] = true;
				while (!q.empty()) {
					cx = q.front().x;
					cy = q.front().y;
					arr[cy][cx] = cnt;
					q.pop();
					bool mv_avail = false;
					for (int k = 0; k < 4; k++) {
						nx = cx + dx[k];
						ny = cy + dy[k];
						if (nx >= 0 && ny >= 0 && nx < col && ny < row && !check[ny][nx]) {
							if (arr[ny][nx] == -1) {
								tmp.y = ny;
								tmp.x = nx;
								check[ny][nx] = true;
								q.push(tmp);
							}
							if (arr[ny][nx] == 0) 
								mv_avail = true;
						}
					}
					if (mv_avail) {
						tmp.x = cx;
						tmp.y = cy;
						island[cnt].push_back(tmp);
					}
				}
				cnt++;
			}
		}
	}
	connect();
}

int main() {
	cin >> row >> col;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1)
				arr[i][j] = -1;
		}
	divide_island();
	if (result == MAX) cout << -1;
	else cout << result;
	system("pause");
	return 0;
}