#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int row, col, result = 10000;
string ss;
struct info {
	int x, y;
};
info tmp;
vector<info> red;
vector<info> blue;
char arr[10][10];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

void start(int cnt, string ans) {
	if (cnt > 9 || cnt >= result) return;
	int crx, cry, cbx, cby, nrx, nry, nbx, nby;
	crx = red[0].x; cry = red[0].y;
	cbx = blue[0].x; cby = blue[0].y;
	for (int i = 0; i < 4; i++) {
		nrx = crx + dx[i];
		nry = cry + dy[i];
		nbx = cbx + dx[i];
		nby = cby + dy[i];
		bool r_finish = false, b_finish = false;
		if (arr[nry][nrx] != '#') {
			if (arr[nry][nrx] == 'O')
				r_finish = true;
			else {
				while (1) {
					nrx += dx[i];
					nry += dy[i];
					if (arr[nry][nrx] == 'O') {
						r_finish = true;
						break;
					}
					else if (arr[nry][nrx] == '#') {
						nrx -= dx[i];
						nry -= dy[i];
						break;
					}
				}
			}
		}
		else {
			nrx -= dx[i];
			nry -= dy[i];
		}
		if (arr[nby][nbx] != '#') {
			if (arr[nby][nbx] == 'O')
				b_finish = true;
			else {
				while (1) {
					nbx += dx[i];
					nby += dy[i];
					if (arr[nby][nbx] == 'O') {
						b_finish = true;
						break;
					}
					else if (arr[nby][nbx] == '#') {
						nbx -= dx[i];
						nby -= dy[i];
						break;
					}
				}
			}
		}
		else {
			nbx -= dx[i];
			nby -= dy[i];
		}
		if (b_finish) continue;
		if (r_finish) {
			result = min(result, cnt + 1);
			if (i == 0) ss = ans + "U";
			else if (i == 1) ss = ans + "R";
			else if (i == 2) ss = ans + "D";
			else if (i == 3) ss = ans + "L";
			return;
		}
		if (nrx == nbx && nry == nby) {
			if (i == 0) {
				if (cry > cby) nry += 1;
				else nby += 1;
			}
			else if (i == 1) {
				if (crx > cbx) nbx -= 1;
				else nrx -= 1;
			}
			else if (i == 2) {
				if (cry > cby) nby -= 1;
				else nry -= 1;
			}
			else if (i == 3) {
				if (crx > cbx) nrx += 1;
				else nbx += 1;
			}
		}
		red[0].x = nrx;
		red[0].y = nry;
		blue[0].x = nbx;
		blue[0].y = nby;
		if(i==0) start(cnt + 1,ans+"U");
		else if (i == 1) start(cnt + 1, ans + "R");
		else if (i == 2) start(cnt + 1, ans + "D");
		else if (i == 3) start(cnt + 1, ans + "L");
		red[0].x = crx;
		red[0].y = cry;
		blue[0].x = cbx;
		blue[0].y = cby;		
	}
}

int main() {
	cin >> row >> col;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'B') {
				tmp.x = j;
				tmp.y = i;
				blue.push_back(tmp);
				arr[i][j] = '.';
			}
			else if (arr[i][j] == 'R') {
				tmp.x = j;
				tmp.y = i;
				red.push_back(tmp);
				arr[i][j] = '.';
			}
		}
	start(0,"");
	if (result == 10000) result = -1;
	cout << result;
	if (result != -1) cout << '\n'<<ss;
	system("pause");
	return 0;
}