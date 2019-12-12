#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int arr[500][500];
int check[500][500];
int many, result, row, col, cx, cy, nx, ny;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
struct info {
	int y;
	int x;
};
queue<info> q;

int main() {
	cin >> row >> col;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			cin >> arr[i][j];

	many = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (arr[i][j] == 1 && check[i][j] == 0) {
				q.push({ i,j });
				check[i][j] = ++many;
				int tmp = 1;
				while (!q.empty()) {
					cx = q.front().x;
					cy = q.front().y;
					q.pop();
					for (int k = 0; k < 4; k++) {
						nx = cx + dx[k];
						ny = cy + dy[k];
						if (nx >= 0 && ny >= 0 && nx < col && ny < row && check[ny][nx] == 0 && arr[ny][nx] == 1) {
							check[ny][nx] = many;
							q.push({ ny,nx });
							tmp++;
						}
					}
				}
				result = max(result, tmp);

			}
		}
	}
	cout << many << endl << result;
	system("pause");
	return 0;
}