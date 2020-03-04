#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int row, col, result = 11;
bool finish = false;
char arr[10][10];
struct info {
	int x, y;
};
info tmp;
vector<info> red;
vector<info> blue;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

void start(int cnt) {
	if (cnt > 10) 
		return;
	int rx = red[0].x;
	int ry = red[0].y;
	int bx = blue[0].x;
	int by = blue[0].y;
	for (int i = 0; i < 4; i++) {
		bool r_finish = false, b_finish = false;
		int nrx = rx, nry = ry;
		int nbx = bx, nby = by;		
		while (1) {
			if (arr[nry + dy[i]][nrx + dx[i]]=='.') {
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
		if (b_finish) continue;		//파란공이 어떻게든 들어가는 경우
		if (r_finish) {			//빨간공만 들어가는 경우
			finish = true;
			result = min(result, cnt);
			return;
		}
		if (nrx == nbx && nry == nby) {			//포개진 경우
			if (i == 0) {
				if (ry > by) 	nry += 1;	//빨간공이 밑에 있었던 경우
				else			nby += 1;			
			}
			else if (i == 1) {
				if (rx > bx)	nbx -= 1;		//파란공이 더 왼쪽에서 시작한 경우
				else			nrx -= 1;
			}
			else if (i == 2) {
				if (ry > by)		nby -= 1;		//파란공이 더 위에서 시작
				else				nry -= 1;
			}
			else if (i == 3) {
				if (rx > bx)		nrx += 1;		//빨간공이 더 오른쪽에서 시작
				else				nbx += 1;
			}
		}
		red[0].x = nrx;
		red[0].y = nry;
		blue[0].x = nbx;
		blue[0].y = nby;
		start(cnt + 1);
		red[0].x = rx;
		red[0].y = ry;
		blue[0].x = bx;
		blue[0].y = by;
	}
}

int main() {
	cin >> row >> col;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'R') {
				tmp.x = j;
				tmp.y = i;
				red.push_back(tmp);
				arr[i][j] = '.';
			}
			else if (arr[i][j] == 'B') {
				tmp.x = j;
				tmp.y = i;
				blue.push_back(tmp);
				arr[i][j] = '.';
			}
		}
	start(1);
	if (finish) cout << result;
	else cout << -1;
	system("pause");
	return 0;
}