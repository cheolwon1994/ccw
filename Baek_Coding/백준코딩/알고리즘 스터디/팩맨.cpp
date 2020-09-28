#define MAX 987654321
#include <iostream>
#include <queue>
#include <string>
using namespace std;
struct info {
	int x1, y1, x2, y2;
	string str;
};
info tmp;
int row, col, nfx, nfy, nsx, nsy;
char arr[50][50];
int check[50][50][50][50];		//fy,fx,sy,sx
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
char dir[4] = { 'N','E','S','W' };
string finish;
bool ghost;

void set_next(int x, int y,int d, int flag) {
	int ny = y + dy[d];
	int nx = x + dx[d];
	if (nx == -1) nx = col - 1;
	else if (nx == col) nx = 0;
	if (ny == -1) ny = row - 1;
	else if (ny == row) ny = 0;
	if (arr[ny][nx] == 'G') 
		ghost = true;
	else if (arr[ny][nx] == '.') {
		if (flag == 0) {
			nfx = nx;
			nfy = ny;
		}
		else {
			nsx = nx;
			nsy = ny;
		}
	}
	else {
		if (flag == 0) {
			nfx = x;
			nfy = y;
		}
		else {
			nsx = x;
			nsy = y;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int test;
	cin >> test;
	for (int t = 0; t < test; t++) {
		cin >> row >> col;
		//초기화
		finish = "IMPOSSIBLE";
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				for (int k = 0; k < row; k++)
					for (int m = 0; m < col; m++)
						check[i][j][k][m] = MAX;
		int fx = -1, fy, sx, sy;
		queue<info> q;
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++) {
				cin >> arr[i][j];
				if (arr[i][j] == 'P') {
					if (fx == -1) {
						tmp.x1 = j;
						tmp.y1 = i;
						fx = j;
					}
					else {
						tmp.x2 = j;
						tmp.y2 = i;
						tmp.str = "";
						q.push(tmp);
						check[tmp.y1][tmp.x1][tmp.y2][tmp.x2] = true;
					}
					arr[i][j] = '.';
				}
			}
		while (!q.empty()) {
			fx = q.front().x1;
			fy = q.front().y1;
			sx = q.front().x2;
			sy = q.front().y2;
			string ss = q.front().str;
			q.pop();
			if (fx == sx && fy == sy) {
				finish = ss;
				break;
			}
			for (int i = 0; i < 4; i++) {
				ghost = false;
				set_next(fx, fy, i, 0);
				set_next(sx, sy, i, 1);
				if (ghost) continue;
				if (check[nfy][nfx][nsy][nsx]>check[fy][fx][sy][sx]+1) {
					check[nfy][nfx][nsy][nsx] = check[fy][fx][sy][sx] + 1;
					tmp.x1 = nfx;
					tmp.y1 = nfy;
					tmp.x2 = nsx;
					tmp.y2 = nsy;
					char c = dir[i];
					tmp.str = ss + c;
					//cout << tmp.str << endl;
					q.push(tmp);
				}
			}
		}
		if (finish != "IMPOSSIBLE")
			cout << finish.size() << " ";
		cout << finish << '\n';
	}
	return 0;
}