#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
int arr[100][100];
int g_amount[1001];
vector<int> check[100][100];
int num, germ, limit;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

struct info {
	int x, y, dir, qty, gnum;
};
info tmp;
vector<info> v;
int result;
void move() {
	int cx, cy, nx, ny, cd, cq, cg;
	vector<info> dup;
	while (limit > 0) {
		for (int i = 0; i < num; i++)
			for (int j = 0; j < num; j++)
				check[i][j].clear();
		dup.clear();
		for (int i = 0; i < v.size(); i++) {
			cx = v[i].x;
			cy = v[i].y;
			cd = v[i].dir;
			cq = v[i].qty;
			cg = v[i].gnum;
			nx = cx + dx[cd];
			ny = cy + dy[cd];
			if (nx == 0 || ny == 0 || nx == num - 1 || ny == num - 1) {
				cq = cq / 2;
				cd = (cd + 2) % 4;
			}
			tmp.x = nx;
			tmp.y = ny;
			tmp.gnum = cg;
			tmp.qty = cq;
			tmp.dir = cd;
			g_amount[cg] = cq;
			dup.push_back(tmp);
			check[ny][nx].push_back(cg);
		}
		for (int i = 0; i < dup.size(); i++) {
			cy = dup[i].y;
			cx = dup[i].x;
			if (check[cy][cx].size() == 1 || g_amount[dup[i].gnum] == 0)
				continue;
			else {
				int idx = check[cy][cx][0];
				int maxi = g_amount[idx];
				int tot = maxi;
				for (int j = 1; j < check[cy][cx].size(); j++) {
					tot += g_amount[check[cy][cx][j]];
					if (g_amount[check[cy][cx][j]] > maxi) {
						g_amount[idx] = 0;
						maxi = g_amount[check[cy][cx][j]];
						idx = check[cy][cx][j];
					}
					else
						g_amount[check[cy][cx][j]] = 0;
				}
				g_amount[idx] = tot;
			}
		}
		v.clear();
		for (int i = 0; i < dup.size(); i++) {
			if (g_amount[dup[i].gnum] == 0)
				continue;
			else {
				tmp.x = dup[i].x;
				tmp.y = dup[i].y;
				tmp.dir = dup[i].dir;
				tmp.gnum = dup[i].gnum;
				tmp.qty = g_amount[dup[i].gnum];
				v.push_back(tmp);
			}
		}
		limit--;
	}
	for (int i = 0; i < v.size(); i++)
		result += v[i].qty;
}

int main() {
	int test, x, y, dir, qty;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		cin >> num >> limit >> germ;
		memset(g_amount, 0, sizeof(g_amount));
		result = 0;
		v.clear();
		for (int i = 0; i < germ; i++) {
			cin >> y >> x >> qty >> dir;
			if (dir == 1)
				dir = 0;
			else if (dir == 4)
				dir = 1;
			tmp.x = x;
			tmp.y = y;
			tmp.dir = dir;
			tmp.qty = qty;
			tmp.gnum = i + 1;
			g_amount[i + 1] = qty;
			v.push_back(tmp);
		}
		move();
		cout << "#" << t << " " << result << endl;
	}
	system("pause");
	return 0;
}