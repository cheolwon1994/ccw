#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;
long long dp[91];
int num;
int main() {
	memset(dp, 0, sizeof(dp));
	dp[1] = 1;
	dp[2] = 1;
	cin >> num;
	if (num < 3)
		cout << dp[num];
	else {
		for (int i = 3; i <= num; i++) {
			for (int j = 1; j < i - 1; j++)
				dp[i] += dp[j];
			dp[i] += 1;
		}
		cout << dp[num];
	}
	system("pause");
	return 0;
}