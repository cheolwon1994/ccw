#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int num, test;
int dp[11];

int main() {
	cin >> test;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i < 11; i++)
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	for (int i = 0; i < test; i++) {
		cin >> num;
		cout << dp[num] << endl;
	}
	system("pause");
	return 0;
}