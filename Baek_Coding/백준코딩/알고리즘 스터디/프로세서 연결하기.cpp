#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
struct info {
	int x, y;
};
info tmp;
vector<info> v;
int num, maxConnect, minlen;
int arr[12][12];

void dfs(int idx, int len, int conn) {
	if (idx == v.size()) {
		if (conn > maxConnect) {
			minlen = len;
			maxConnect = conn;
		}
		else if (conn == maxConnect) 
			minlen = min(minlen, len);		
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = v[idx].x;
		int ny = v[idx].y;
		int cnt = 0;
		while (1) {
			nx += dx[i];
			ny += dy[i];
			cnt++;
			if (arr[ny][nx] == 1 || arr[ny][nx] == 2) {
				cnt = 0;
				break;
			}
			if (arr[ny][nx]==0 && (nx == 0 || ny == 0 || nx == num - 1 || ny == num - 1)) {
				break;
			}
		}
		if (cnt > 0) {
			nx = v[idx].x;
			ny = v[idx].y;
			while (1) {
				nx += dx[i];
				ny += dy[i];
				if (nx < 0 || ny < 0 || nx > num - 1 || ny > num - 1)
					break;
				arr[ny][nx] = 2;
			}
			dfs(idx + 1, len + cnt, conn + 1);
			nx = v[idx].x;
			ny = v[idx].y;
			while (1) {
				nx += dx[i];
				ny += dy[i];
				if (nx < 0 || ny < 0 || nx > num - 1 || ny > num - 1)
					break;
				arr[ny][nx] = 0;
			}
		}
	}
	dfs(idx + 1, len, conn);
}

int main() {
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		cin >> num;
		v.clear();
		for (int i = 0; i < num; i++)
			for (int j = 0; j < num; j++) {
				cin >> arr[i][j];
				if (arr[i][j] == 1) {
					//¿Ü°ûÀº ¹«½Ã
					if (i == 0 || i == num - 1 || j == 0 || j == num - 1) continue;
					tmp.x = j;
					tmp.y = i;
					v.push_back(tmp);
				}
			}
		maxConnect = 0;
		minlen = 987654321;
		dfs(0, 0, 0);
		cout << "#" << t << " " << minlen << '\n';
	}
	system("pause");
	return 0;
}