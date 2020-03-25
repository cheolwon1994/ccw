#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct info {
	int x, y, wall, dist;
};
info tmp;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int arr[1000][1000];
bool check[1000][1000][11] = { false, };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int row, col, crash;
	string s;
	cin >> row >> col >> crash;
	for (int i = 0; i < row; i++) {
		cin >> s;
		for (int j = 0; j < col; j++) 
			arr[i][j] = s[j] - '0';		
	}
	queue<info> q;
	tmp.x = 0;
	tmp.y = 0;
	tmp.wall = 0;
	tmp.dist = 1;
	q.push(tmp);
	check[0][0][0] = true;
	int result = -1;
	bool sun = true;
	while (!q.empty()) {
		int len = q.size();
		for(int k=0;k<len;k++) {
			int cx = q.front().x;
			int cy = q.front().y;
			int cw = q.front().wall;
			int cd = q.front().dist;
			q.pop();
			if (cy == row - 1 && cx == col - 1) {
				result = cd;
				break;
			}
			bool block = false;
			for (int i = 0; i < 4; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if (nx >= 0 && ny >= 0 && nx < col && ny < row) {
					if (arr[ny][nx] == 0 && !check[ny][nx][cw]) {
						check[ny][nx][cw] = true;
						tmp.x = nx;
						tmp.y = ny;
						tmp.wall = cw;
						tmp.dist = cd + 1;
						q.push(tmp);
					}
					else if (arr[ny][nx] == 1 && !check[ny][nx][cw + 1] && cw < crash) {
						if (sun) {		//³·
							check[ny][nx][cw + 1] = true;
							tmp.x = nx;
							tmp.y = ny;
							tmp.wall = cw + 1;
							tmp.dist = cd + 1;
							q.push(tmp);
						}
						else 
							block = true;						
					}
				}
			}
			if (block) {
				tmp.x = cx;
				tmp.y = cy;
				tmp.dist = cd + 1;
				tmp.wall = cw;
				q.push(tmp);
			}
		}
		if (result > 0) break;
		sun = !sun;
	}
	cout << result;
	system("pause");
	return 0;
}