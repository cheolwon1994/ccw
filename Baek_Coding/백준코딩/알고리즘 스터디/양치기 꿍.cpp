#include <iostream>
#include <queue>
using namespace std;
char arr[250][250];
bool check[250][250] = { false, };
struct info {
	int x, y;
};
info tmp;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int main() {
	int row, col, sheep = 0, wolf = 0;
	cin >> row >> col;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			cin >> arr[i][j];

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (arr[i][j] != '#' && !check[i][j]) {
				int ts = 0, tw = 0;
				tmp.x = j;
				tmp.y = i;
				check[i][j] = true;
				queue<info> q;
				q.push(tmp);
				while (!q.empty()) {
					int cx = q.front().x;
					int cy = q.front().y;
					q.pop();
					if (arr[cy][cx] == 'k') ts++;
					else if (arr[cy][cx] == 'v') tw++;				
					for (int k = 0; k < 4; k++) {
						int nx = cx + dx[k];
						int ny = cy + dy[k];
						if (nx >= 0 && ny >= 0 && nx < col && ny < row && !check[ny][nx] && arr[ny][nx] != '#') {
							check[ny][nx] = true;
							tmp.x = nx;
							tmp.y = ny;
							q.push(tmp);
						}
					}
				}
				if (ts > tw) sheep += ts;
				else wolf += tw;
			}
		}
	}
	cout << sheep << " " << wolf;
	system("pause");
	return 0;
}