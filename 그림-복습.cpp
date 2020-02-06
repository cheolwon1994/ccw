#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
struct i {
	int idx, val;
};
struct cmp {
	bool operator()(i &a, i&b) {
		return a.val < b.val;
	}
};
struct info {
	int x, y;
};
info tmp;
i tmp2;
priority_queue<i, vector<i>, cmp> pq;
int row, col;
int arr[500][500];
bool check[500][500];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

int main() {
	cin >> row >> col;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			cin >> arr[i][j];
	int cx,cy,nx,ny,cnt = 1;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (arr[i][j] == 1 && !check[i][j]) {
				queue<info> q;
				tmp.x = j;
				tmp.y = i;
				q.push(tmp);
				check[i][j] = true;
				int tt = 1;
				while (!q.empty()) {
					cx = q.front().x;
					cy = q.front().y;
					q.pop();
					for (int k = 0; k < 4; k++) {
						nx = cx + dx[k];
						ny = cy + dy[k];
						if (nx >= 0 && ny >= 0 && nx < col &&ny < row && !check[ny][nx] && arr[ny][nx]==1) {
							check[ny][nx] = true;
							tmp.x = nx;
							tmp.y = ny;
							q.push(tmp);
							tt++;
						}
					}
				}
				tmp2.idx = cnt;
				tmp2.val = tt;
				pq.push(tmp2);
				cnt++;
			}
		}
	}
	cout << pq.size() << endl;
	if (pq.empty()) cout << 0;
	else cout << pq.top().val;
	system("pause");
	return 0;
}
