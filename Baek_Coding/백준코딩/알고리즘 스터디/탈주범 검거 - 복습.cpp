#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct info {
	int x, y, val;
};
info tmp;
bool avail[8][4] = {
	{},
	{true,true,true,true},
	{true,false,true,false},
	{false,true,false,true},
	{true,true,false,false},
	{false,true,true,false},
	{false,false,true,true},
	{true,false,false,true},
};
int row, col, tx, ty, remain, result;
int arr[50][50];
bool check[50][50];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		cin >> row >> col >> ty >> tx >> remain;
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++) {
				cin >> arr[i][j];
				check[i][j] = false;
			}
		queue<info> q;
		tmp.x = tx;
		tmp.y = ty;
		tmp.val = 1;
		q.push(tmp);
		check[ty][tx] = true;
		result = 1;
		remain;
		while (!q.empty()) {
			int cx = q.front().x;
			int cy = q.front().y;
			int cv = q.front().val;
			q.pop();
			if (cv == remain) continue;
			int vv = arr[cy][cx];
			for (int i = 0; i < 4; i++) {
				if (avail[vv][i]) {
					int nx = cx + dx[i];
					int ny = cy + dy[i];
					if (nx >= 0 && ny >= 0 && nx < col && ny < row && !check[ny][nx] && arr[ny][nx]>0) {
						int nd = (i + 2) % 4;
						int val = arr[ny][nx];
						if (avail[val][nd]) {
							result++;
							tmp.x = nx;
							tmp.y = ny;
							tmp.val = cv + 1;
							q.push(tmp);
							check[ny][nx] = true;
						}
					}
				}
			}
		}
		cout << "#" << t << " " << result << '\n';
	}
	return 0;
}