#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
long long dp[1001][10];		//길이,시작 숫자
int num;
long long result = 0;
int main() {
	for (int i = 1; i < 1001; i++)
		memset(dp[i], 0, sizeof(dp[i]));
	for (int i = 0; i < 10; i++)
		dp[1][i] = 1;
	for (int i = 2; i < 1001; i++) 
		for (int j = 9; j >= 0; j--) 
			for (int k = j; k < 10; k++)
				dp[i][j] =(dp[i][j]+dp[i - 1][k])%10007;	
	cin >> num;
	for (int i = 0; i < 10; i++)
		result += dp[num][i];
	cout << result%10007;
	system("pause");
	return 0;
}