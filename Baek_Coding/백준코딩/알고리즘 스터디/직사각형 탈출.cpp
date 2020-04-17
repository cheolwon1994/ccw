#define MAX 987654321
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int arr[1000][1000];
bool check[1000][1000] = { false, };
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

struct info {
	int x, y, val;
};
info tmp;
int row, col, r, c, sx, sy, tx, ty, result = MAX;

bool test(int y, int x, int dir) {
	if (dir == 0) {		//위로 이동
		for (int i = x; i < x + c; i++) {
			if (arr[y][i] == 1)
				return false;			
		}
	}
	else if (dir == 1) {		//오른쪽으로 이동
		int nx = x + c - 1;
		if (nx >= col) return false;
		for (int i = y; i < y + r; i++)
			if (arr[i][nx] == 1)
				return false;
	}
	else if (dir == 2) {		//아래로 이동
		int ny = y + r - 1;
		if (ny >= row) return false;
		for (int i = x; i < x + c; i++) {
			if (arr[ny][i] == 1)
				return false;
		}
	}
	else if (dir == 3) {		//왼쪽으로 이동
		for (int i = y; i < y + r; i++)
			if (arr[i][x] == 1)
				return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> row >> col;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) 
			cin >> arr[i][j];		
	cin >> r >> c >> sy >> sx >> ty >> tx;
	sy--; sx--; ty--; tx--;
	queue<info> q;
	tmp.x = sx;
	tmp.y = sy;
	tmp.val = 0;
	q.push(tmp);
	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		int cv = q.front().val;
		q.pop();
		if (cx == tx && cy == ty) {
			result = cv;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && ny >= 0 && nx<col && ny<row && !check[ny][nx] && arr[ny][nx]==0) {
				check[ny][nx] = true;
				if (test(ny, nx,i)) {		//이동 가능한 경우
					tmp.x = nx;
					tmp.y = ny;
					tmp.val = cv + 1;
					q.push(tmp);
				}
			}
		}
	}
	if (result == MAX) result = -1;
	cout << result;
	system("pause");
	return 0;
}