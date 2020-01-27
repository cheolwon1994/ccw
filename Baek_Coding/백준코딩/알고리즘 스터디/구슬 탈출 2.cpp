#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
int row, col;
bool finish = false;
char arr[10][10];
struct info {
	int x, y;
};
info tmp;
int result = 100;
stack<info> r;
stack<info> b;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

void start(int cnt) {
	if (cnt>=result)	return;
	if (cnt > 9) 
		return;
	int crx, cry, nrx, nry, cbx, cby, nbx, nby;
	crx = r.top().x;
	cry = r.top().y;
	cbx = b.top().x;
	cby = b.top().y;
	for (int i = 0; i < 4; i++) {
		bool r_finish = false;
		bool b_finish = false;
		for (int j = 1;; j++) {		//빨간공 이동
			nrx = crx + dx[i] * j;
			nry = cry + dy[i] * j;
			if (nrx >= 0 && nry >= 0 && nrx < col && nry < row) {
				if (arr[nry][nrx] == 'O') {
					r_finish = true;
					break;
				}
				else if (arr[nry][nrx] == '.')	continue;
				else if (arr[nry][nrx] == '#') {
					nrx -= dx[i];
					nry -= dy[i];
					tmp.x = nrx;
					tmp.y = nry;
					r.push(tmp);
					break;
				}
			}
		}
		for (int j = 1;; j++) {		//파란공 이동
			nbx = cbx + dx[i] * j;
			nby = cby + dy[i] * j;
			if (nbx >= 0 && nby >= 0 && nbx < col && nby < row) {
				if (arr[nby][nbx] == 'O') {
					b_finish = true;
					break;
				}
				else if (arr[nby][nbx] == '.')	continue;
				else if (arr[nby][nbx] == '#') {
					nbx -= dx[i];
					nby -= dy[i];
					tmp.x = nbx;
					tmp.y = nby;
					b.push(tmp);
					break;
				}
			}
		}
		if (b_finish)	continue;
		if (r_finish) {
			result = min(result,cnt + 1);
			finish = true;
			return;
		}
		//겹친 경우
		if (r.top().x == b.top().x && r.top().y == b.top().y) {
			if(i==0){	//위쪽방향으로 이동
				if (cry < cby) {
					tmp.y = nby + 1;
					tmp.x = nbx;
					b.pop();
					b.push(tmp);
				}
				else {
					tmp.y = nry + 1;
					tmp.x = nrx;
					r.pop();
					r.push(tmp);
				}
			}
			else if (i == 1) {		//오른쪽 방향으로 이동
				if (crx < cbx) {
					tmp.y = nry;
					tmp.x = nrx-1;
					r.pop();
					r.push(tmp);
				}
				else {
					tmp.y = nby;
					tmp.x = nbx - 1;
					b.pop();
					b.push(tmp);
				}
			}
			else if (i == 2) {		//아래쪽으로 이동
				if (cry < cby) {
					tmp.y = nry-1;
					tmp.x = nrx;
					r.pop();
					r.push(tmp);
				}
				else {
					tmp.y = nby - 1;
					tmp.x = nbx;
					b.pop();
					b.push(tmp);
				}
			}
			else if (i == 3) {		//왼쪽으로 이동
				if (crx < cbx) {
					tmp.y = nby;
					tmp.x = nbx + 1;
					b.pop();
					b.push(tmp);
				}
				else {
					tmp.y = nry;
					tmp.x = nrx + 1;
					r.pop();
					r.push(tmp);
				}
			}
		}
		if (r.top().x == crx && r.top().y == cry && b.top().x == cbx && b.top().y == cby) {
			b.pop();
			r.pop();
			continue;
		}
		start(cnt + 1);
		r.pop();
		b.pop();
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> row >> col;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'R') {
				tmp.x = j;
				tmp.y = i;
				r.push(tmp);
				arr[i][j] = '.';
			}
			else if (arr[i][j] == 'B') {
				tmp.x = j;
				tmp.y = i;
				b.push(tmp);
				arr[i][j] = '.';
			}
		}
	start(0);
	if (!finish)
		result = -1;
	cout << result;
	return 0;
}