#include <iostream>
#include <queue>
using namespace std;
int arr[1000][1000];
int row, col, result = 0;
struct info {
	int x, y;
};
info tmp;
int dx[8] = { 0,1,1,1,0,-1,-1,-1 };
int dy[8] = { -1,-1,0,1,1,1,0,-1 };
queue<info> q;

void bfs() {
	while (1) {
		int len = q.size();
		for (int i = 0; i < len; i++) {
			int cx = q.front().x;
			int cy = q.front().y;
			q.pop();
			for (int j = 0; j < 8; j++) {
				int nx = cx + dx[j];
				int ny = cy + dy[j];
				if (nx >= 0 && ny >= 0 && nx < col && ny < row && arr[ny][nx]>0) {
					arr[ny][nx] -= 1;
					if (arr[ny][nx] == 0) {
						tmp.x = nx;
						tmp.y = ny;
						q.push(tmp);
					}
				}
			}
		}
		if (q.empty()) break;
		result++;
	}
}

int main() {
	cin >> row >> col;
	char c;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) {		
			cin >> c;
			if (c == '.') {
				tmp.x = j;
				tmp.y = i;
				q.push(tmp);
				arr[i][j] = 0;
			}
			else
				arr[i][j] = c - '0';
		}
	bfs();
	cout << result;
	system("pause");
	return 0;
}