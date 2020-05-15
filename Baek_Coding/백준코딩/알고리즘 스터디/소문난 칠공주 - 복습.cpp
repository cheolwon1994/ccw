#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
char arr[5][5];
int check[25], result = 0;
struct info {
	int x, y;
};
info tmp;
vector<info> v;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

bool check_near() {
	queue<info> q;
	bool flag[7] = { false, };
	tmp.x = v[0].x;
	tmp.y = v[0].y;
	q.push(tmp);
	flag[0] = true;
	int cnt = 1;
	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		q.pop();
		for (int k = 1; k < 7; k++) {
			if (flag[k]) continue;
			for (int i = 0; i < 4; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];				
				if (nx == v[k].x && ny == v[k].y) {
					tmp.x = nx;
					tmp.y = ny;
					q.push(tmp);
					flag[k] = true;
					cnt++;
				}
			}
		}
	}
	if (cnt == 7) return true;
	else return false;
}

void dfs(int idx, int lee, int lim) {
	if (lee + lim == 7) {
		if (lim > lee) return;
		if (check_near())
			result++;
		return;
	}
	for (int i = idx; i < 25; i++) {
		if (check[i]) continue;
		int r = i / 5;
		int c = i % 5;
		tmp.x = c;
		tmp.y = r;
		v.push_back(tmp);
		check[i] = 1;
		if (arr[r][c] == 'Y')
			dfs(i + 1, lee, lim + 1);
		else
			dfs(i + 1, lee + 1, lim);
		check[i] = 0;
		v.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	string str;
	for (int i = 0; i < 5; i++) {
		cin >> str;
		for (int j = 0; j < 5; j++) 
			arr[i][j] = str[j];		
	}
	dfs(0, 0, 0);
	cout << result;
	system("pause");
	return 0;
}