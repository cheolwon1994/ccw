#define MAX 987654321
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;
struct info {
	int x, y, wall;
};
info tmp;
int arr[1000][1000];
int check[1000][1000][10];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int row, col, k;
	string str;
	cin >> row >> col >> k;
	for (int i = 0; i < row; i++) {
		cin >> str;
		for (int j = 0; j < col; j++) 
			arr[i][j] = str[j] - '0';		
	}
	queue<info> q;
	tmp.x = 0;
	tmp.y = 0;
	tmp.wall = 0;
	check[0][0][0] = 1;
	q.push(tmp);
	int result = MAX;
	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		int cw = q.front().wall;
		int cv = check[cy][cx][cw];
		q.pop();
		if (cx == col - 1 && cy == row - 1) {
			result = cv;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && ny >= 0 && nx < col && ny < row) {
				if (arr[ny][nx] == 0 && check[ny][nx][cw] == 0) {		//일반 길
					check[ny][nx][cw] = cv + 1;
					tmp.x = nx;
					tmp.y = ny;
					tmp.wall = cw;
					q.push(tmp);
				}
				else if (arr[ny][nx] == 1 && cw + 1 <= k && check[ny][nx][cw + 1] == 0) {
					check[ny][nx][cw + 1] = cv + 1;
					tmp.x = nx;
					tmp.y = ny;
					tmp.wall = cw + 1;
					q.push(tmp);
				}
			}
		}
	}
	if (result == MAX) result = -1;
	cout << result;
	return 0;
}