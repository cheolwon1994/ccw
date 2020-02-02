#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <queue>
using namespace std;
int sx, sy, tx, ty, num;
int result = 10000;
struct info {
	int x, y;
};
info tmp;
int dx[6] = { 1,2,1,-1,-2,-1 };
int dy[6] = { -2,0,2,2,0,-2 };
int check[200][200];

void bfs() {
	for (int i = 0; i < num; i++)
		memset(check[i], 0, sizeof(check[i]));
	queue<info> q;
	tmp.x = sx;
	tmp.y = sy;
	q.push(tmp);
	check[sy][sx] = 0;
	int cx, cy, cv, nx, ny;
	while (!q.empty()) {
		cx = q.front().x;
		cy = q.front().y;
		q.pop();
		if (cx == tx && cy == ty) {
			result = min(result, check[cy][cx]);
			break;
		}
		for (int i = 0; i < 6; i++) {
			nx = cx + dx[i];
			ny = cy + dy[i];
			if (nx >= 0 && ny >= 0 && nx < num && ny < num) {
				if (check[ny][nx]==0 || check[ny][nx] > (check[cy][cx] + 1)) {
					check[ny][nx] = check[cy][cx] + 1;
					tmp.x = nx;
					tmp.y = ny;
					q.push(tmp);
				}
			}
		}
	}
}

int main() {
	cin >> num >> sy >> sx >> ty >> tx;
	if (abs(sy - ty) % 2 != 0)		result = -1;
	else	bfs();
	if (result == 10000)
		result = -1;
	cout << result;
	system("pause");
	return 0;
}