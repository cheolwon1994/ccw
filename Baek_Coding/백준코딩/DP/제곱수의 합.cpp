#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int dp[100001];
int num;
int result = 0;

int main() {
	cin >> num;
	for (int i = 1; i < 317; i++)
		dp[i*i] = 1;
	int tmp = 1;
	for (int i = 2; i < 100001; i++) {
		if (dp[i] == 0) {
				dp[i] = 1 + dp[i - tmp * tmp];
				for (int j = tmp-1; j > 0; j--)
					dp[i] = min(dp[i], 1 + dp[i - (tmp - j)*(tmp - j)]);
		}
		else if (dp[i] == 1) 
			tmp +=1;
	}
	cout << dp[num];
	system("pause");
	return 0;
}