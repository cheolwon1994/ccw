#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
struct info {
	int x, y;
};
info tmp;
vector<info> arr[101][101];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
bool check[101][101] = { false, };
bool light[101][101] = { false, };
bool reachable[101][101] = { false, };
int num, room, sx, sy, tx, ty, result;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> num >> room;
	for (int i = 1; i <= num; i++)
		for (int j = 1; j <= num; j++)
	light[1][1] = true;
	for (int i = 0; i < room; i++) {
		cin >> sx >> sy >> tx >> ty;
		tmp.x = tx;
		tmp.y = ty;
		arr[sy][sx].push_back(tmp);
	}
	queue<info> q;
	tmp.x = 1;
	tmp.y = 1;
	q.push(tmp);
	check[1][1] = true;
	reachable[1][1] = true;
	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		q.pop();
		//스위치가 있으면 해제시킨다
		for (int i = 0; i < arr[cy][cx].size(); i++) {
			int nx = arr[cy][cx][i].x;
			int ny = arr[cy][cx][i].y;
			light[ny][nx] = true;
			if (reachable[ny][nx] && !check[ny][nx]) {
				check[ny][nx] = true;
				tmp.x = nx;
				tmp.y = ny;
				q.push(tmp);
			}
		}

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			reachable[ny][nx] = true;
			if (nx > 0 && ny > 0 && nx <= num && ny <= num && !check[ny][nx]) {
				if (light[ny][nx]) {
					check[ny][nx] = true;
					tmp.x = nx;
					tmp.y = ny;
					q.push(tmp);
				}
			}
		}
	}
	for (int i = 1; i <= num; i++) {
		for (int j = 1; j <= num; j++)
			if (light[i][j])
				result++;
	}
	cout << result;
	return 0;
}