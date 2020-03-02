#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
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
int row, col, result = 0;
char arr[101][101];
bool check[101][101];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> row >> col;
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++) {
			cin >> arr[i][j];
			check[i][j] = false;
		}
	
	priority_queue<info, vector<info>, cmp> pq;
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++) {
			if (arr[i][j] == '*') {
				int cnt = 1;
				vector<info> v;				
				while (1) {
					bool avail = true;
					for (int k = 0; k < 4; k++) {
						int nx = j + dx[k] * cnt;
						int ny = i + dy[k] * cnt;
						if (nx >= 1 && ny >= 1 && nx <= col && ny <= row && arr[ny][nx] == '*') {
							tmp.x = nx;
							tmp.y = ny;
							v.push_back(tmp);
						}
						else {
							avail = false;
							break;
						}
					}
					if (avail) 
						cnt++;					
					else {
						if (cnt == 1) break;
						else {
							for (int k = 0; k < v.size(); k++)
								check[v[k].y][v[k].x] = true;
							check[i][j] = true;
							tmp.x = j;
							tmp.y = i;
							tmp.val = cnt - 1;
							pq.push(tmp);
							break;
						}
					}
				}
			}
		}
	bool finish = true;
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			if (arr[i][j] == '*' && !check[i][j]) {
				finish = false;
				result = -1;
				break;
			}
		}
		if (!finish) break;
	}
	vector<info> ans;
	if (finish) {
		int cnt = 0;
		while (!pq.empty()) {
			int cx = pq.top().x;
			int cy = pq.top().y;
			int cv = pq.top().val;
			pq.pop();
			int tt = 0;
			if (check[cy][cx]) {
				tt++;
				check[cy][cx] = false;
			}
			for (int k = 1; k <= cv; k++) {
				for (int i = 0; i < 4; i++) {
					int nx = cx + dx[i] * k;
					int ny = cy + dy[i] * k;
					if (check[ny][nx]) {
						check[ny][nx] = false;
						tt++;
					}
				}
			}
			if (tt > 0) {
				tmp.x = cx;
				tmp.y = cy;
				tmp.val = cv;
				ans.push_back(tmp);
			}
		}
		result = ans.size();
	}
	
	cout << result << '\n';
	if(result!=0)
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i].y << " " << ans[i].x << " " << ans[i].val << '\n';

	system("pause");
	return 0;
}