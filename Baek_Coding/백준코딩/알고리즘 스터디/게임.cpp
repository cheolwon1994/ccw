#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;

int arr[50][50];		//1~9는 일반, 0: 구멍
//bool check[50][50][4][10];		//어디서온건지 나타내는 dir,얼만큼 떨어진곳에서 온건지
bool check[50][50];
int dp[50][50];
bool cycle = false;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int row, col;

int dfs(int y, int x) {
	if (y < 0 || x < 0 || y >= row || x >= col)
		return 0;
	if (check[y][x]) { cycle = true; return -1;  }//순환
	if (arr[y][x] == 0) return 0;
	int result=dp[y][x];
	if (dp[y][x] != -1)	return dp[y][x];
	int tt = arr[y][x];	
	check[y][x] = true;
	result = 1 + max(max(dfs(y + dy[0] * tt, x + dx[0] * tt), dfs(y + dy[1] * tt, x + dx[1] * tt)),
		max(dfs(y + dy[2] * tt, x + dx[2] * tt), dfs(y + dy[3] * tt, x + dx[3] * tt)));
	dp[y][x] = result;
	check[y][x] = false;
	return result;
}

int main() {
	string str;
	int cx, cy, nx, ny, cv;
	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		cin >> str;
		for (int j = 0; j < col; j++) {
			if (str[j] == 'H')
				arr[i][j] = 0;
			else {
				arr[i][j] = str[j] - '0';
			}
		}
	}
	for (int i = 0; i < 50; i++)
		memset(dp[i], -1, sizeof(dp[i]));
	int ans = dfs(0,0);
	if (cycle)
		cout << -1;
	else
		cout << ans;
	system("pause");
	return 0;
}