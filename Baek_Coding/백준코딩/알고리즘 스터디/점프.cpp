#include <iostream>
#include <string.h>
using namespace std;
int num, tt;
int arr[110][110];
long long dp[110][110];
int dx[2] = { 1,0 };
int dy[2] = { 0,1 };
int main() {
	cin >> num;
	for (int i = 0; i < num; i++)
		for (int j = 0; j < num; j++)
			cin >> arr[i][j];
	for (int i = 0; i < 110; i++)
		memset(dp[i], 0, sizeof(dp[i]));
	dp[0][0] = 1;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			if (dp[i][j] != 0) {
				if (i == num - 1 && j == num - 1)
					continue;					
				tt = arr[i][j];
				dp[i][j + tt] += dp[i][j];
				dp[i + tt][j] += dp[i][j];
			}
		}
	}
	cout << dp[num - 1][num - 1];
	system("pause");
	return 0;
}