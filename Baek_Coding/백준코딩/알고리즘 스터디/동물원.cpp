#define MOD 9901
#include <iostream>
using namespace std;
long long dp[100001][2][2];		//자리수, 뒤에서 2번째 숫자, 뒤에서 1번째 숫자

int main() {
	int num;
	cin >> num;
	if (num == 1) cout << 3;
	else {
		dp[2][0][0] = 1;
		dp[2][0][1] = 2;
		dp[2][1][0] = 2;
		dp[2][1][1] = 2;
		for (int i = 3; i <= num; i++) {
			dp[i][0][0] = (dp[i - 1][0][0] + dp[i - 1][1][0]) % MOD;
			dp[i][0][1] = ((dp[i - 1][0][0] * 2) % MOD + (dp[i - 1][1][0] * 2) % MOD) % MOD;
			dp[i][1][0] = (dp[i - 1][0][1] + dp[i - 1][1][1]) % MOD;
			dp[i][1][1] = (dp[i - 1][1][1] + dp[i - 1][0][1]) % MOD;
		}
		long long result = 0;
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++) {
				result += dp[num][i][j];
				result %= MOD;
			}
		cout << result % MOD;
	}
	system("pause");
	return 0;
}