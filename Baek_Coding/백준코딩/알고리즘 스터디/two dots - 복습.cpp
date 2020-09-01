#include <iostream>
#include <string>
#include <queue>
using namespace std;
struct info {
	int x, y;
	char c;
};
info tmp;
int row, col;
char arr[50][50];
int check[50][50] = { false, };
bool cycle = false;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

void bfs(int y, int x, char c) {
	queue<info> q;
	tmp.x = x;
	tmp.y = y;
	tmp.c = c;
	q.push(tmp);
	check[y][x] = 1;
	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		char cc = q.front().c;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = cx + dx[k];
			int ny = cy + dy[k];
			if (nx >= 0 && ny >= 0 && nx < col && ny < row && arr[ny][nx] == cc) {
				if (check[ny][nx] == 0) {
					check[ny][nx] = check[cy][cx] + 1;
					tmp.x = nx;
					tmp.y = ny;
					tmp.c = cc;
					q.push(tmp);
				}
				else if(check[ny][nx] > check[cy][cx]){
					if (check[ny][nx] + check[cy][cx] > 3) {
						cycle = true;
						break;
					}
				}
			}
		}
		if (cycle) break;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str;
	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		cin >> str;
		for (int j = 0; j < col; j++)
			arr[i][j] = str[j];
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (check[i][j]==0)
				bfs(i, j, arr[i][j]);
			if (cycle) break;
		}
		if (cycle) break;
	}
	if (cycle) cout << "Yes";
	else cout << "No";
	return 0;
}