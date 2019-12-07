#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;
int arr[300][300];
int dup[300][300];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
struct info {
	int x;
	int y;
	int val;
};
info tmp;
vector<info> v;
int row, col;
int result = 0;
//³ì´Â´Ù -> ºÐ¸®µÆ´ÂÁö È®ÀÎ -> º¹»ç

void melt() {
	while (1) {
		result += 1;
		int cx, cy, cv, nx, ny, cnt;
		//³ì´Â´Ù
		for (int i = 0; i < v.size(); i++) {
			cx = v[i].x;
			cy = v[i].y;
			cv = v[i].val;
			cnt = 0;
			for (int j = 0; j < 4; j++) {
				nx = cx + dx[j];
				ny = cy + dy[j];
				if (nx >= 0 && ny >= 0 && nx < col && ny < row) {
					if (arr[ny][nx] == 0)
						cnt++;
				}
			}
			cv -= cnt;
			if (cv <= 0)
				cv = 0;
			v[i].val = cv;
		}
		vector<info> dv;
		int maxi = 0;
		int mx = 0;
		int my = 0;
		for (int i = 0; i < v.size(); i++) {
			tmp.x = v[i].x;
			tmp.y = v[i].y;
			tmp.val = v[i].val;
			arr[tmp.y][tmp.x] = tmp.val;
			if (v[i].val != 0) {
				dv.push_back(tmp);
				if (v[i].val > maxi) {
					maxi = v[i].val;
					mx = tmp.x;
					my = tmp.y;
				}
			}
		}
		if (dv.empty()) {
			cout << 0;
			break;
		}
		v.clear();
		v = dv;
		queue<info> q;
		int check[300][300];
		for (int i = 0; i < row; i++)
			memset(check[i], 0, sizeof(check[i]));
		tmp.x = mx;
		tmp.y = my;
		check[my][mx] = 1;
		q.push(tmp);
		int check2 = 1;
		while (!q.empty()) {
			cx = q.front().x;
			cy = q.front().y;
			q.pop();
			for (int i = 0; i < 4; i++) {
				nx = cx + dx[i];
				ny = cy + dy[i];
				if (nx >= 0 && ny >= 0 && nx < col && ny < row) {
					if (check[ny][nx] != 1 && arr[ny][nx] > 0) {
						check[ny][nx] = 1;
						check2 += 1;
						tmp.x = nx;
						tmp.y = ny;
						q.push(tmp);
					}
				}
			}
		}
		if (check2 != v.size()) {
			cout <<result;
			break;
		}
	}
}

int main() {
	cin >> row >> col;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) {
			cin >> arr[i][j];
			if (arr[i][j] != 0) {
				tmp.x = j;
				tmp.y = i;
				tmp.val = arr[i][j];
				v.push_back(tmp);
			}
		}
	melt();
	system("pause");
	return 0;
}