#define MAX 987654321
#include <iostream>
#include <queue>
using namespace std;

struct info {
	int x, y, dir, val;
};
info tmp;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int arr[101][101];
int check[101][101][4];
int row, col, sx, sy, sd, tx, ty, td, result = MAX;

void bfs() {
	queue<info> q;
	tmp.x = sx;
	tmp.y = sy;
	tmp.dir = sd;
	tmp.val = 0;
	q.push(tmp);
	check[sy][sx][sd] = 0;
	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		int cd = q.front().dir;
		int cv = q.front().val;
		q.pop();
		if (cx == tx && cy == ty && cd == td) {
			result = cv;
			break;
		}
		//앞으로 전진
		for (int k = 1; k <= 3; k++) {
			int nx = cx + dx[cd] * k;
			int ny = cy + dy[cd] * k;
			if (nx > 0 && ny > 0 && nx <= col && ny <= row && arr[ny][nx] == 0) {
				if (check[ny][nx][cd] > cv + 1) {
					check[ny][nx][cd] = cv + 1;
					tmp.x = nx;
					tmp.y = ny;
					tmp.dir = cd;
					tmp.val = cv + 1;
					q.push(tmp);
				}
			}
			else break;
		}
		//우 회전
		int nd = (cd + 1) % 4;
		if (check[cy][cx][nd] > cv + 1) {
			check[cy][cx][nd] = cv + 1;
			tmp.x = cx;
			tmp.y = cy;
			tmp.dir = nd;
			tmp.val = cv + 1;
			q.push(tmp);
		}
		//좌 회전
		nd = (cd + 3) % 4;
		if (check[cy][cx][nd] > cv + 1) {
			check[cy][cx][nd] = cv + 1;
			tmp.x = cx;
			tmp.y = cy;
			tmp.dir = nd;
			tmp.val = cv + 1;
			q.push(tmp);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> row >> col;
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++) {
			cin >> arr[i][j];
			for (int k = 0; k < 4; k++)
				check[i][j][k] = MAX;
		}
	cin >> sy >> sx >> sd >> ty >> tx >> td;
	if (sd == 2) sd = 3;
	else if (sd == 3) sd = 2;
	else if (sd == 4) sd = 0;
	if (td == 2) td = 3;
	else if (td == 3) td = 2;
	else if (td == 4) td = 0;
	bfs();
	cout << result;
	return 0;
}