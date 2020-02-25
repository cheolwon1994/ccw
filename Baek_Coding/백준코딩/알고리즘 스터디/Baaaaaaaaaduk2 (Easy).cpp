#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int row, col, result = 0;
int arr[20][20];
bool check[20][20];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
struct info {
	int x, y;
};
info tmp;
vector<info> zero;
bool used[400];

void bfs() {
	int t_result = 0;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			check[i][j] = false;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (arr[i][j] == 2 && !check[i][j]) {
				queue<info> q;
				tmp.x = j;
				tmp.y = i;
				q.push(tmp);
				int cnt = 1;
				check[i][j] = true;
				bool avail = true;
				while (!q.empty()) {
					int cx = q.front().x;
					int cy = q.front().y;
					q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = cx + dx[k];
						int ny = cy + dy[k];
						if (nx >= 0 && ny >= 0 && nx < col &&ny < row && !check[ny][nx]) {
							if (arr[ny][nx] == 0) 
								avail = false;						
							else if (arr[ny][nx] == 1) continue;
							else if (arr[ny][nx] == 2) {
								check[ny][nx] = true;
								tmp.x = nx;
								tmp.y = ny;
								q.push(tmp);
								cnt++;
							}
						}
					}
				}
				if (avail) 
					t_result += cnt;				
			}
		}
	}
	result = max(result, t_result);
}

void locate(int cnt, int idx) {
	if (cnt == 2) {
		/*cout << endl;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++)
				cout << arr[i][j] << " ";
			cout << endl;
		}
		system("pause");*/
		bfs();
		return;
	}
	for (int i = idx; i < zero.size(); i++) {
		if (!used[i]) {
			used[i] = true;
			int x = zero[i].x;
			int y = zero[i].y;
			arr[y][x] = 1;
			locate(cnt + 1,i+1);
			arr[y][x] = 0;
			used[i] = false;
		}
	}
}

int main() {
	cin >> row >> col;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) {
				tmp.x = j;
				tmp.y = i;
				zero.push_back(tmp);
			}
		}
	for (int i = 0; i < zero.size(); i++)
		used[i] = false;
	locate(0,0);
	cout << result;
	system("pause");
	return 0;
}