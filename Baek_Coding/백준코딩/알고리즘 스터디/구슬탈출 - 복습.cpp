#include <iostream>
#include <algorithm>
using namespace std;
int row, col;
char arr[10][10];
int answer = 11;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

void dfs(int ry, int rx, int by, int bx, int cnt) {
	if (cnt>=answer) return;
	for (int i = 0; i < 4; i++) {
		int nry = ry, nrx = rx, nbx = bx, nby = by;
		bool r_finish = false, b_finish = false;
		while (1) {
			if (arr[nry + dy[i]][nrx + dx[i]] == '.') {
				nry += dy[i];
				nrx += dx[i];
			}
			else if (arr[nry + dy[i]][nrx + dx[i]] == 'O') {
				r_finish = true;
				nry += dy[i];
				nrx += dx[i];
				break;
			}
			else if (arr[nry + dy[i]][nrx + dx[i]] == '#') break;
		}
		while (1) {
			if (arr[nby + dy[i]][nbx + dx[i]] == '.') {
				nby += dy[i];
				nbx += dx[i];
			}
			else if (arr[nby + dy[i]][nbx + dx[i]] == 'O') {
				b_finish = true;
				nby += dy[i];
				nbx += dx[i];
			}
			else if (arr[nby + dy[i]][nbx + dx[i]] == '#') break;
		}
		if (b_finish) continue;
		if (r_finish) {
			answer = min(answer, cnt + 1);
			return;
		}
		if (nry == nby && nrx == nbx) {
			if (i == 0) {
				if (ry > by) nry += 1;
				else nby += 1;
			}
			else if (i == 1) {
				if (rx < bx) nrx -= 1;
				else nbx -= 1;
			}
			else if (i == 2) {
				if (ry > by) nby -= 1;
				else nry -= 1;
			}
			else {
				if (rx < bx) nbx += 1;
				else nrx += 1;
			}
		}
		dfs(nry, nrx, nby, nbx, cnt + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> row >> col;
	int  rx, ry, bx, by;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'R') {
				rx = j;
				ry = i;
				arr[i][j] = '.';
			}
			else if (arr[i][j] == 'B') {
				bx = j;
				by = i;
				arr[i][j] = '.';
			}
		}
	dfs(ry, rx, by, bx, 0);
	(answer == 11) ? (cout << 0) : (cout << 1);
	return 0;
}