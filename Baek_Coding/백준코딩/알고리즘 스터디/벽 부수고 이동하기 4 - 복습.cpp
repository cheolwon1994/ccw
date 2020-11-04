#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
using namespace std;
struct info {
	int x, y;
};
info tmp;
int arr[1000][1000];
int check[1000][1000];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int row, col, idx = 0;
vector<int> ans;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> row >> col;
	string str;
	for (int i = 0; i < row; i++) {
		cin >> str;
		for (int j = 0; j < col; j++)
			arr[i][j] = str[j] - '0';
	}
	ans.push_back(0);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (arr[i][j] == 0 && check[i][j] == 0) {
				vector<info> v;
				queue<info> q;
				tmp.x = j;
				tmp.y = i;
				q.push(tmp);
				v.push_back(tmp);
				int cnt = 1;
				check[i][j] = ++idx;
				while (!q.empty()) {
					int cx = q.front().x;
					int cy = q.front().y;
					q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = cx + dx[k];
						int ny = cy + dy[k];
						if (nx >= 0 && ny >= 0 && nx < col && ny < row &&arr[ny][nx] == 0 && check[ny][nx] == 0) {
							check[ny][nx] = idx;
							cnt++;
							tmp.x = nx;
							tmp.y = ny;
							q.push(tmp);
							v.push_back(tmp);
						}
					}
				}
				for (int k = 0; k < v.size(); k++) {
					int cx = v[k].x;
					int cy = v[k].y;
					check[cy][cx] = idx;
				}
				ans.push_back(cnt);
			}
		}
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (arr[i][j] == 0) cout << 0;
			else {
				int cnt = 1;
				set<int> s;
				for (int k = 0; k < 4; k++) {
					int nx = j + dx[k];
					int ny = i + dy[k];
					if(nx >= 0 && ny >= 0 && nx < col && ny < row && arr[ny][nx]==0)
						s.insert(check[ny][nx]);
				}
				for (auto it = s.begin(); it != s.end(); it++)
					cnt += ans[*it];
				cout << cnt % 10;
			}
		}
		cout << '\n';
	}
	return 0;
}