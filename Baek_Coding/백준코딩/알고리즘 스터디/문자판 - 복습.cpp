#include <iostream>
#include <string>
using namespace std;
char arr[100][100];
int dp[100][100][81];
int row, col, dist, result = 0;
string str;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

int dfs(int y, int x, int len) {
	if (dp[y][x][len] != -1) return dp[y][x][len];
	if (len == str.size()) {
		dp[y][x][len] = 1;
		return dp[y][x][len];
	}
	dp[y][x][len] = 0;
	for (int k = 1; k <= dist; k++) {
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i] * k;
			int ny = y + dy[i] * k;
			if (nx >= 0 && ny >= 0 && nx < col && ny < row && arr[ny][nx]==str[len]) 
				dp[y][x][len] += dfs(ny, nx, len + 1);			
		}
	}
	return dp[y][x][len];
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> row >> col >> dist;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			cin >> arr[i][j];
	cin >> str;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			for (int k = 0; k <= str.size(); k++)
				dp[i][j][k] = -1;

	for (int i = 0; i < row; i++) 
		for (int j = 0; j < col; j++) 
			if (arr[i][j] == str[0]) 
				result+=dfs(i, j, 1);		
	cout << result;
	system("pause");
	return 0;
}