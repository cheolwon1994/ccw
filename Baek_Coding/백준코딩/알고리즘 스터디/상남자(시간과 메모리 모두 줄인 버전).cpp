#include <iostream>
#include <string>
#include <queue>
using namespace std;
struct info {
	int x, y, l, r;
};
info tmp;
int row, col, l, r;
int arr[1000][1000];
bool check[1000][1000];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string str;
	cin >> row >> col >> l >> r;
	queue<info> q;
	for (int i = 0; i < row; i++) {
		cin >> str;
		for (int j = 0; j < col; j++) {
			arr[i][j] = str[j] - '0';
			if (arr[i][j] == 2) {
				tmp.x = j;
				tmp.y = i;
				tmp.r = 0;
				tmp.l = 0;
				q.push(tmp);
				check[i][j] = true;
			}
		}
	}
	int cx, cy, cl, cr, ty;
	while (!q.empty()) {
		ty = q.front().y;
		cx = q.front().x;
		cl = q.front().l;
		cr = q.front().r;
		q.pop();
		cy = ty;
		cy += 1;
		while (cy < row) {		//¹ØÀ¸·Î
			if (arr[cy][cx] != 1 && !check[cy][cx]) {
				tmp.x = cx;
				tmp.y = cy;
				tmp.l = cl;
				tmp.r = cr;
				q.push(tmp);
				check[cy][cx] = true;
				cy += 1;
			}
			else break;
		}
		cy = ty - 1;
		while (cy >= 0) {		//À§·Î
			if (arr[cy][cx] != 1 && !check[cy][cx]) {
				tmp.x = cx;
				tmp.y = cy;
				tmp.l = cl;
				tmp.r = cr;
				q.push(tmp);
				check[cy][cx] = true;
				cy -= 1;
			}
			else break;
		}
		cy = ty;
		if(cx < col-1) {		//¿À¸¥ÂÊÀ¸·Î 1Ä­
			if (arr[cy][cx+1] != 1 && !check[cy][cx+1] && cr + 1 <= r) {
				tmp.x = cx+1;
				tmp.y = cy;
				tmp.l = cl;
				tmp.r = cr+1;
				q.push(tmp);
				check[cy][cx+1] = true;
			}
		}
		if(cx > 0) {		//¿ÞÂÊÀ¸·Î 1Ä­
			if (arr[cy][cx-1] != 1 && !check[cy][cx-1] && cl + 1 <= l) {
				tmp.x = cx-1;
				tmp.y = cy;
				tmp.l = cl+1;
				tmp.r = cr;
				q.push(tmp);
				check[cy][cx-1] = true;
			}
		}
	}
	int result = 0;
	for (int i = 0; i < row; i++) 
		for (int j = 0; j < col; j++) 
			if (check[i][j]) result++;
	cout << result;
	system("pause");
	return 0;
}