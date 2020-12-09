#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
struct info {
	int x, y;
};
info tmp;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int arr[12][12];
int row, col, result;

void bfs(int val) {
	queue<info> q;
	tmp.x = 0;
	tmp.y = 0;
	q.push(tmp);
	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && ny >= 0 && nx <= col + 1 && ny <= row + 1 && arr[ny][nx] < val) {
				arr[ny][nx] = val;
				tmp.x = nx;
				tmp.y = ny;
				q.push(tmp);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int test, maxi;
	cin >> test;
	for (int t = 0; t < test; t++) {
		//초기화
		result = 0;
		for (int i = 0; i < 12; i++)
			for (int j = 0; j < 12; j++)
				arr[i][j] = 0;
		maxi = 0;

		cin >> row >> col;
		for (int i = 1; i <= row; i++)
			for (int j = 1; j <= col; j++) {
				cin >> arr[i][j];
				maxi = max(maxi, arr[i][j]);
			}
		for (int k = 1; k <= maxi; k++) {
			bfs(k);
			for (int i = 1; i <= row; i++)
				for (int j = 1; j <= col; j++) {
					if (arr[i][j] < k) {
						arr[i][j] = k;
						result++;
					}
				}
		}
		cout << "Case #" << t + 1 << ": " << result << '\n';
	}
	return 0;
}