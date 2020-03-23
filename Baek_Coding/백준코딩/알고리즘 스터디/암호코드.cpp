#define MOD 1000000
#include <iostream>
#include <string>
using namespace std;
long long dp[5001];
int main() {
	string str;
	cin >> str;
	dp[0] = 1;
	dp[1] = 1;
	if (str[0]-'0' == 0) cout << 0;
	else {
		for (int i = 2; i <= str.size(); i++) {
			if (str[i - 1] - '0' > 0)
				dp[i] = dp[i - 1] % MOD;
			int x = (str[i - 2] - '0') * 10 + str[i-1] - '0';
			if (10 <= x && x <= 26) 
				dp[i] = (dp[i] + dp[i - 2]) % MOD;		
		}
		cout << dp[str.size()];
	}
	system("pause");
	return 0;
}