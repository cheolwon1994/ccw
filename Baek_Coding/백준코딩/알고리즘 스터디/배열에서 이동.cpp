#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct info {
	int x, y;
};
info tmp;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int num, mini = 201, maxi = -1, l, r, mid, result = 201;
int arr[100][100];
bool check[100][100];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> num;
	for (int i = 0; i < num; i++)
		for (int j = 0; j < num; j++) {
			cin >> arr[i][j];
			mini = min(mini, arr[i][j]);
			maxi = max(maxi, arr[i][j]);
		}
	l = mini, r = mini;
	while (l <= r && r <= maxi) {
		if ((arr[0][0] < l) || arr[0][0] > r) {
			r++;
			continue;
		}
		bool avail = false;
		queue<info> q;
		for (int i = 0; i < num; i++)
			for (int j = 0; j < num; j++)
				check[i][j] = false;
		tmp.x = 0;
		tmp.y = 0;
		q.push(tmp);
		while (!q.empty()) {
			int cx = q.front().x;
			int cy = q.front().y;
			q.pop();
			if (cx == num - 1 && cy == num - 1) {
				avail = true;
				break;
			}
			for (int i = 0; i < 4; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if (nx >= 0 && ny >= 0 && nx < num && ny < num && !check[ny][nx]) {					
					if (l<=arr[ny][nx] && arr[ny][nx]<=r) {
						tmp.x = nx;
						tmp.y = ny;
						q.push(tmp);
						check[ny][nx] = true;
					}
				}
			}
		}
		if (avail) {
			result = min(result, r - l);
			if (l != r)	l++;
			else r++;
		}
		else
			r++;
	}
	cout << result;
	system("pause");
	return 0;
}