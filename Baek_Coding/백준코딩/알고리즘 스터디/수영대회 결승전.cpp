#define MAX 987654321
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
struct info {
	int x, y, val;
};
info tmp;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int arr[15][15], num, sx, sy, ex, ey;
int check[15][15];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(false); cout.tie(false);
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		cin >> num;
		for (int i = 0; i < num; i++)
			for (int j = 0; j < num; j++) {
				cin >> arr[i][j];
				check[i][j] = MAX;
			}
		cin >> sy >> sx >> ey >> ex;
		queue<info> q;
		tmp.x = sx;
		tmp.y = sy;
		tmp.val = 0;
		q.push(tmp);
		check[sy][sx] = 0;
		int result = MAX;
		while (!q.empty()) {
			int cx = q.front().x;
			int cy = q.front().y;
			int cv = q.front().val;
			q.pop();
			if (cy == ey && cx == ex) {
				result = min(result, cv);
				continue;
			}
			for (int i = 0; i < 4; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if (nx >= 0 && ny >= 0 && nx < num && ny<num && check[ny][nx]>cv + 1) {
					if (arr[ny][nx] == 0) {
						tmp.x = nx;
						tmp.y = ny;
						tmp.val = cv + 1;
						q.push(tmp);
						check[ny][nx] = cv + 1;
					}
					else if (arr[ny][nx] == 2) {
						if (cv % 3 == 2) {
							tmp.x = nx;
							tmp.y = ny;
							tmp.val = cv + 1;
							q.push(tmp);
							check[ny][nx] = cv + 1;
						}
						else {
							int tt = 1;
							while (1) {
								if ((tt + cv) % 3 == 2) break;
								tt++;
							}
							int nv = tt + cv;
							if (check[ny][nx] > nv + 1) {
								check[ny][nx] = nv + 1;
								tmp.x = nx;
								tmp.y = ny;
								tmp.val = nv + 1;
								q.push(tmp);
								check[ny][nx] = nv + 1;
							}
						}
					}
				}
			}
		}
		if (result == MAX) result = -1;
		cout << "#" << t << " " << result << '\n';
	}
	system("pause");
	return 0;
}