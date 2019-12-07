#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
long long dp[1001];
int num;

int main() {
	cin >> num;
	dp[1] = 1;
	dp[2] = 2;
	if (num < 3) 
		cout << dp[num];
	else {
		for (int i = 3; i <= num; i++)
			dp[i] = (dp[i - 1] + dp[i - 2])%10007;
		cout << dp[num]%10007;
	}
	system("pause");
	return 0;
}