#include <iostream>
#include <string>
using namespace std;
char arr[100][100];
int dp[100][100][81];		//마지막은 몇번째 글자로 왔는지
int row, col, jmp, result = 0;
string str;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

int start(int y, int x, int idx) {
	if (dp[y][x][idx]!=-1) return dp[y][x][idx];		//이미 값이 저장된 경우
	if (idx == str.size()) {		//처음으로 끝까지 온 경우
		dp[y][x][idx] = 1;
		return 1;
	}
	dp[y][x][idx] = 0;
	for (int k = 0; k < 4; k++) {
		for (int i = 0; i < jmp; i++) {
			int nx = x + dx[k] * (i + 1);
			int ny = y + dy[k] * (i + 1);
			if (nx >= 0 && ny >= 0 && nx < col && ny < row &&arr[ny][nx] == str[idx]) {
				dp[y][x][idx] += start(ny, nx, idx + 1);
			}
		}
	}
	return dp[y][x][idx];
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> row >> col >> jmp;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			cin >> arr[i][j];
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			for (int k = 0; k < 81; k++)
				dp[i][j][k] = -1;
	cin >> str;
	char c = str[0];
	for (int i = 0; i < row; i++) 
		for (int j = 0; j < col; j++)
			if (arr[i][j] == c) 
				result += start(i, j, 1);
	cout << result;
	system("pause");
	return 0;
}