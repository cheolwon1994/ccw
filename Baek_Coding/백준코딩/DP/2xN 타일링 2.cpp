#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int num;
long long dp[1001];
int main() {
	cin >> num;
	dp[1] = 1;
	dp[2] = 3;
	if (num < 3)
		cout << dp[num];
	else {
		for (int i = 3; i <= num; i++)
			dp[i] = (dp[i - 1] + 2 * dp[i - 2])%10007;
		cout << dp[num];
	}
	system("pause");
	return 0;
}