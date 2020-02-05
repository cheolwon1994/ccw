#define MAX 30000000
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <queue>
#include <math.h>
using namespace std;
int row, col, r, l;
int arr[1000][1000];
long long val[1000][1000];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
struct info {
	int x, y;
};
info tmp;
queue<info> q;

void bfs() {
	int cx, cy, nx, ny;
	long long cr, cl, nr, nl, tr, tl;
	while (!q.empty()) {
		cx = q.front().x;
		cy = q.front().y;
		q.pop();
		cr = val[cy][cx] / 3000;
		cl = val[cy][cx] % 3000;		
		for (int i = 0; i < 4; i++) {
			nx = cx + dx[i];
			ny = cy + dy[i];
			if (nx >= 0 && ny >= 0 && nx < col && ny < row && arr[ny][nx]!=1) {
				nr = val[ny][nx] / 3000;
				nl = val[ny][nx] % 3000;
				if (i == 1){
					if (cr + 1 <= r) {
						tr = cr + 1;
						tl = cl;
					}
					else
						continue;
				}
				else if (i == 3) {
					if (cl + 1 <= l) {
						tl = cl + 1;
						tr = cr;
					}
					else
						continue;
				}
				else if (i == 0 || i == 2) {
					tr = cr;
					tl = cl;
				}
				if (abs(nr - nl) > abs(tr - tl)) {
					val[ny][nx] = tr * 3000 + tl;
					tmp.x = nx;
					tmp.y = ny;
					q.push(tmp);
				}
				else if (abs(nr - nl) == abs(tr - tl)) {
					if (nr + nl > tr + tl) {
						val[ny][nx] = tr * 3000 + tl;
						tmp.x = nx;
						tmp.y = ny;
						q.push(tmp);
					}
				}
			}
		}
	}
}

int main() {
	string str;
	cin >> row >> col >> l >> r;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			val[i][j] = MAX;

	for (int i = 0; i < row; i++) {
		cin >> str;
		for (int j = 0; j < col; j++) {
			arr[i][j] = str[j]-'0';
			if (arr[i][j] == 2) {
				tmp.x = j;
				tmp.y = i;
				q.push(tmp);
				arr[i][j] = 0;
				val[i][j] = 0;
			}
		}
	}

	bfs();
	long long tl, tr, result = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (arr[i][j] != 1) {
				tr = val[i][j] / 3000;
				tl = val[i][j] % 3000;
				if (tr <= r && tl <= l)
					result++;
			}
		}
	}
	cout << result;
	system("pause");
	return 0;
}