#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int row, col;
bool finish = false;
struct info {
	int x, y;
};
info tmp;
vector<info> v[2];
vector<int> order;
char arr[10][10];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

void move() {
	int rcx = v[0][0].x; int rcy = v[0][0].y;
	int bcx = v[1][0].x; int bcy = v[1][0].y;
	for (int i = 0; i < 10; i++) {
		int cd = order[i];
		int nrx = rcx; int nry = rcy; int nbx = bcx; int nby = bcy;
		bool fin_red = false, fin_blue = false;
		while (1) {
			nrx += dx[cd];
			nry += dy[cd];
			if (nrx >= 0 && nry >= 0 && nrx < col && nry < row && arr[nry][nrx] != '#') {
				if (arr[nry][nrx] == 'O') {
					fin_red = true;
					break;
				}
			}
			else {
				nrx -= dx[cd];
				nry -= dy[cd];
				break;
			}
		}
		while (1) {
			nbx += dx[cd];
			nby += dy[cd];
			if (nbx >= 0 && nby >= 0 && nbx < col && nby < row && arr[nby][nbx] != '#') {
				if (arr[nby][nbx] == 'O') {
					fin_blue = true;
					break;
				}
			}
			else {
				nbx -= dx[cd];
				nby -= dy[cd];
				break;
			}
		}
		if (fin_blue) 	break;	//파란공이 나가는 경우
		if (fin_red) {			//빨간공만 나가는 경우
			finish = true;
			break;
		}
		if (nrx == nbx && nry == nby) {
			if (cd == 0) {
				if (rcy < bcy) nby += 1;
				else nry += 1;
			}
			else if (cd == 1) {
				if (rcx < bcx) nrx -= 1;
				else nbx -= 1;
			}
			else if (cd == 2) {
				if (rcy < bcy) nry -= 1;
				else nby -= 1;
			}
			else if (cd == 3) {
				if (rcx < bcx) nbx += 1;
				else nrx += 1;
			}
		}
		rcx = nrx; rcy = nry;
		bcx = nbx; bcy = nby;
	}
}

void dfs(int cnt) {
	if (finish) return;
	if (cnt == 10) {
		move();
		return;
	}
	for (int i = 0; i < 4; i++) {
		order.push_back(i);
		dfs(cnt + 1);
		order.pop_back();
	}
}

int main() {
	cin >> row >> col;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'B' || arr[i][j] == 'R') {
				tmp.x = j;
				tmp.y = i;
				if (arr[i][j] == 'B') v[1].push_back(tmp);
				else v[0].push_back(tmp);
				arr[i][j] = '.';
			}
		}
	dfs(0);
	if (finish) cout << 1;
	else cout << 0;
	system("pause");
	return 0;
}