#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int row, col, ans = 0;
int arr[50][50];
bool check[50][50] = { false, };
int dp[50][50];		//현재 위치, 현재위치의 이전 위치
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
bool cycle = false;

int dfs(int cy, int cx) {
	if (cx < 0 || cy < 0 || cx >= col || cy >= row) return 0;
	if (arr[cy][cx] == 0) return 0;
	if (dp[cy][cx] != -1) return dp[cy][cx];
	if (check[cy][cx]) {
		cycle = true;
		return -1;
	}
	int ret = dp[cy][cx];
	int val = arr[cy][cx];
	check[cy][cx] = true;
	for (int i = 0; i < 4; i++) {
		int nx = cx + dx[i] * val;
		int ny = cy + dy[i] * val;
		ret = max(ret, 1+ dfs(ny, nx));
	}
	dp[cy][cx] = ret;
	check[cy][cx] = false;
	return dp[cy][cx];
}

int main() {
	cin >> row >> col;
	string str;
	for (int i = 0; i < row; i++) {
		cin >> str;
		for (int j = 0; j < col; j++) {
			if (str[j] == 'H')	arr[i][j] = 0;
			else	arr[i][j] = str[j] - '0';
		}
	}
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			dp[i][j] = -1;
	ans = dfs(0, 0);
	if (cycle) ans = -1;
	cout << ans;
	return 0;
}