#include <iostream>
#include <algorithm>
using namespace std;
long long dp[31];
int num;

int main() {
	cin >> num;
	for (int i = 0; i < 31; i++)
		dp[i] = 0;
	dp[0] = 1;
	dp[2] = 3;
	for (int i = 4; i < 31; i+=2) {
		dp[i] = dp[i - 2] * 3;
		for (int j = 4; j <= i; j += 2)
			dp[i] += dp[i - j] * 2;
	}
	cout << dp[num];
	system("pause");
	return 0;
}