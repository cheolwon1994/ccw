#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int arr[1000][1000], dp[1000][1000];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int row, col, result = 0;
	cin >> row >> col;
	string str;
	for (int i = 0; i < row; i++) {
		cin >> str;
		for (int j = 0; j < col; j++)
			arr[i][j] = str[j] - '0';
	}
	for (int i = 0; i < col; i++)
		if (arr[row - 1][i]) {
			dp[row - 1][i] = 1;
			result = 1;
		}
	for (int i = 0; i < row; i++)
		if (arr[i][col - 1]) {
			dp[i][col - 1] = 1;
			result = 1;
		}

	for (int i = row - 2; i >= 0; i--) {
		for (int j = col - 2; j >= 0; j--) {
			if (arr[i][j]) {
				dp[i][j] = 1;
				int mini = min(dp[i + 1][j], dp[i][j + 1]);
				mini = min(mini, dp[i + 1][j + 1]);
				dp[i][j] = mini + 1;
				result = max(result, dp[i][j]*dp[i][j]);				
			}
		}
	}
	cout << result;
	return 0;
}