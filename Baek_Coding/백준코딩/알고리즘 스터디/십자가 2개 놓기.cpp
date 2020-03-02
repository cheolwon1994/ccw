#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int row, col, result = 0;
char arr[15][15];

int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
struct info {
	int x, y, val;
};
struct cmp {
	bool operator()(info &a, info &b) {
		return a.val < b.val;
	}
};
info tmp;
vector<info> v;
vector<int> order;

void cal() {
	bool check[15][15];
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) 
			check[i][j] = false;
	
	bool avail = true;
	int big = 0, small = 0;
	for (int m = 0; m < 2; m++) {
		int cx = v[order[m]].x;
		int cy = v[order[m]].y;
		int cv = v[order[m]].val;
		vector<info> tt;
		tmp.x = cx;
		tmp.y = cy;
		tt.push_back(tmp);
		for (int i = 1; i <= cv; i++) {
			for (int j = 0; j < 4; j++) {
				int nx = cx + dx[j] * i;
				int ny = cy + dy[j] * i;
				if (check[ny][nx]) {
					avail = false;
					break;
				}
				else {
					tmp.x = nx;
					tmp.y = ny;
					tt.push_back(tmp);
				}
			}
		}
		if (avail) {
			for (int i = 0; i < tt.size(); i++)
				check[tt[i].y][tt[i].x] = true;
			if (big == 0)
				big = (4 * cv + 1);
			else {
				small = (4 * cv + 1);
				break;
			}
		}
	}
	result = max(result, big*small);
}

void dfs(int cnt, int idx) {
	if (cnt == 2) {
		cal();
		return;
	}
	for (int i = idx; i < v.size(); i++) {		
		order.push_back(i);
		dfs(cnt+1,i + 1);
		order.pop_back();		
	}
}

int main() {
	cin >> row >> col;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) 
			cin >> arr[i][j];
		
	priority_queue<info, vector<info>, cmp> pq;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) {
			if (arr[i][j] == '#') {
				int cnt = 1;
				while (1) {		
					bool avail = true;
					for (int k = 0; k < 4; k++) {
						int nx = j + dx[k] * cnt;
						int ny = i + dy[k] * cnt;
						if (nx >= 0 && ny >= 0 && nx < col && ny < row && arr[ny][nx]=='#') {
							continue;
						}
						else {
							avail = false;
							break;
						}
					}
					if (avail)	cnt++;										
					else {
						tmp.x = j;
						tmp.y = i;
						tmp.val = cnt - 1;
						pq.push(tmp);
						break;
					}
				}
			}
		}
	while (!pq.empty()) {
		tmp.x = pq.top().x;
		tmp.y = pq.top().y;
		tmp.val = pq.top().val;
		pq.pop();
		v.push_back(tmp);
	}
	dfs(0, 0);
	cout << result;
	system("pause");
	return 0;
}