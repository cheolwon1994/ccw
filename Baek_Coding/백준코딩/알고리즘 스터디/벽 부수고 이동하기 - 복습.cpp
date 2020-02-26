#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;
int arr[1000][1000];
bool check[1000][1000][2];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
struct info {
	int x, y, val, destroy;
};
info tmp;
int row, col, result = -1;

void bfs() {
	queue<info> q;
	tmp.x = 0;
	tmp.y = 0;
	tmp.val = 1;
	tmp.destroy = 0;
	q.push(tmp);
	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		int cv = q.front().val;
		int cd = q.front().destroy;
		q.pop();
		if (cx == col - 1 && cy == row - 1) {
			result = max(result, cv);
			break;
		}
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && ny >= 0 && nx < col && ny < row) {
				if (arr[ny][nx] == 0) {
					if ((cd==1 && !check[ny][nx][cd]) || (cd==0 && !check[ny][nx][cd])) {
						check[ny][nx][cd] = true;
						tmp.x = nx;
						tmp.y = ny;
						tmp.destroy = cd;
						tmp.val = cv + 1;
						q.push(tmp);
					}
				}
				else if (arr[ny][nx] == 1 && cd==0 && !check[ny][nx][cd]) {
					check[ny][nx][cd] = true;
					tmp.x = nx;
					tmp.y = ny;
					tmp.val = cv + 1;
					tmp.destroy = 1;
					q.push(tmp);
				}
			}
		}
	}
}

int main() {
	string str;
	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		cin >> str;
		for (int j = 0; j < col; j++)
			arr[i][j] = str[j] - '0';
	}
	bfs();
	cout << result;
	system("pause");
	return 0;
}