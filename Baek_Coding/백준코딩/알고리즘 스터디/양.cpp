#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
struct info {
	int x, y;
};
info tmp;
bool check[250][250];
char arr[250][250];
int row, col;

int main() {
	cin >> row >> col;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			cin >> arr[i][j];
	int cx, cy, nx, ny, l = 0, w = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (!check[i][j] && arr[i][j] != '#') {
				tmp.x = j;
				tmp.y = i;
				queue<info> q;
				q.push(tmp);
				check[i][j] = true;
				int lamb = 0;
				int wolf = 0;
				if (arr[i][j] == 'o') lamb++;
				else if (arr[i][j] == 'v') wolf++;
				while (!q.empty()) {
					cx = q.front().x;
					cy = q.front().y;
					q.pop();
					for (int k = 0; k < 4; k++) {
						nx = cx + dx[k];
						ny = cy + dy[k];
						if (nx >= 0 && ny >= 0 && nx < col && ny < row && arr[ny][nx]!='#' && !check[ny][nx]) {
							if (arr[ny][nx] == 'o') lamb++;
							else if (arr[ny][nx] == 'v') wolf++;
							check[ny][nx] = true;
							tmp.x = nx;
							tmp.y = ny;
							q.push(tmp);
						}
					}
				}
				if (lamb > wolf) {
					l += lamb;
				}
				else
					w += wolf;
			}
		}
	}
	cout << l << " " << w;
	system("pause");
	return 0;
}