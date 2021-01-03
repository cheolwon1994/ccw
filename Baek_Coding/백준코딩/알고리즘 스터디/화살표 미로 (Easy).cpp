#include <iostream>
#include <algorithm>
using namespace std;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
char arr[51][51];
int check[51][51];
int row, col, paper;
bool avail = false;

void dfs(int y, int x, int r, int l) {
	if (avail) return;
	int use = max(r, l);;
	check[y][x] = use;
	if (x == col && y == row) {
		avail = true;
		return;
	}
	char c = arr[y][x];
	int dir, nd;
	if (c == 'U') dir = 0;
	else if (c == 'R') dir = 1;
	else if (c == 'D') dir = 2;
	else dir = 3;
	int nx = x + dx[dir];
	int ny = y + dy[dir];
	if (nx > 0 && ny > 0 && nx <= col && ny <= row && check[ny][nx] > use)
		dfs(ny, nx, r, l);
	//회전
	if (r < paper) {
		//오른쪽
		nd = (dir + 1) % 4;
		nx = x + dx[nd];
		ny = y + dy[nd];
		if (nx > 0 && ny > 0 && nx <= col && ny <= row && check[ny][nx] > use + 1)
			dfs(ny, nx, r + 1, l);
	}
	//왼쪽
	if (l < paper) {
		nd = (dir + 3) % 4;
		nx = x + dx[nd];
		ny = y + dy[nd];
		if (nx > 0 && ny > 0 && nx <= col && ny <= row && check[ny][nx] > use + 1)
			dfs(ny, nx, r, l + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> row >> col >> paper;
	for(int i=1;i<=row;i++)
		for (int j = 1; j <= col; j++) {
			cin >> arr[i][j];
			check[i][j] = 3;
		}
	dfs(1, 1, 0, 0);
	avail ? cout << "Yes" : cout << "No";
	return 0;
}