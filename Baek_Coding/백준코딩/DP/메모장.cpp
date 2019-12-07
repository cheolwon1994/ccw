#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int test, row;
int arr[3][100001];
int dp[3][100001];

long long result = 0;
int main() {
	cin >> test;
	for (int t = 0; t < test; t++) {
		cin >> row;
		for (int i = 1; i < 3; i++) {
			memset(arr, 0, sizeof(arr));
			memset(dp, 0, sizeof(dp));
		}
		for (int i = 1; i < 3; i++) 
			for (int j = 1; j <= row; j++)
				cin >> arr[i][j];
		dp[1][1] = arr[1][1];
		dp[2][1] = arr[2][1];
		dp[1][2] = arr[2][1] + arr[1][2];
		dp[2][2] = arr[1][1] + arr[2][2];
		for (int i = 3; i <= row; i++) {
			dp[1][i] = max(dp[2][i - 1], dp[1][i - 2]);
			dp[1][i] = max(dp[1][i], dp[2][i - 2]);
			dp[1][i] += arr[1][i];

			dp[2][i] = max(dp[1][i - 1], dp[1][i - 2]);
			dp[2][i] = max(dp[2][i], dp[2][i - 2]);
			dp[2][i] += arr[2][i];
		}
		cout << max(dp[1][row], dp[2][row]) << endl;
	}
	system("pause");
	return 0;
}