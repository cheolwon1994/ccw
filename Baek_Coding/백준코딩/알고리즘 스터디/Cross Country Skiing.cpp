#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
using namespace std;
struct info {
	int x, y;
};
info tmp;
int arr[500][500];
bool check[500][500];
int row, col, val;
vector<info> waypoint;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

bool bfs(int mid) {
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			check[i][j] = false;
	queue<info> q;
	tmp.x = waypoint[0].x;
	tmp.y = waypoint[0].y;
	q.push(tmp);
	check[tmp.y][tmp.x] = true;
	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && ny >= 0 && nx < col && ny < row && abs(arr[ny][nx] - arr[cy][cx]) <= mid && !check[ny][nx]) {
				check[ny][nx] = true;
				tmp.x = nx;
				tmp.y = ny;
				q.push(tmp);
			}
		}
	}
	for (int i = 1; i < waypoint.size(); i++) {
		int cx = waypoint[i].x;
		int cy = waypoint[i].y;
		if (!check[cy][cx])
			return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> row >> col;
	int l = 0, r = 0, mid, result;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) {
			cin >> arr[i][j];
			r = max(r, arr[i][j]);
		}
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) {
			cin >> val;
			if (val == 1) {
				tmp.x = j;
				tmp.y = i;
				waypoint.push_back(tmp);
			}
		}
	while (l <= r) {
		mid = l + (r - l) / 2;
		if (bfs(mid)) {
			result = mid;
			r = mid - 1;
		}
		else
			l = mid + 1;
	}
	cout << result;
	return 0;
}