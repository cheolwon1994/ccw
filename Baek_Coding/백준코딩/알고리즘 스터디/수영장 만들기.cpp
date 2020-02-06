#include <iostream>
#include <queue>
#include <string>
using namespace std;
int row, col, result = 0, maxi = 0;
int arr[52][52];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
struct info {
	int x, y;
};
info tmp;

void bfs(int height) {
	queue<info> q;
	tmp.x = 0;
	tmp.y = 0;
	q.push(tmp);
	int cx, cy, nx, ny;
	while (!q.empty()) {
		cx = q.front().x;
		cy = q.front().y;
		q.pop();
		for (int k = 0; k < 4; k++) {
			nx = cx + dx[k];
			ny = cy + dy[k];
			if (nx >= 0 && ny >= 0 && nx <= col + 1 && ny <= row + 1 && arr[ny][nx] < height) {
				tmp.x = nx;
				tmp.y = ny;
				arr[ny][nx] = height;
				q.push(tmp);
			}
		}
	}
}

int main() {
	string str;
	cin >> row >> col;
	for (int i = 1; i <= row; i++) {
		cin >> str;
		for (int j = 1; j <= col; j++) {
			arr[i][j] = str[j-1] - '0';
			maxi = max(maxi, arr[i][j]);
		}
	}

	for (int t = 1; t <= maxi; t++) {
		bfs(t);
		for (int i = 1; i <= row; i++) {
			for (int j = 1; j <= col; j++) {
				if (arr[i][j] < t) {
					arr[i][j] += 1;
					result++;
				}
			}
		}
	}
	cout << result;
	system("pause");
	return 0;
}