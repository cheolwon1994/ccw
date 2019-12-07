#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int arr[1001];
int dp[1001];
int num;
long long result;
int main() {
	cin >> num;
	arr[0] = 0;
	for (int i = 1; i <= num; i++)
		cin >> arr[i];
	memset(dp, 0, sizeof(dp));
	dp[1] = arr[1];
	for (int i = 2; i <= num; i++) {
		for (int j = 0; j <= i; j++) {
			dp[i] = max(dp[i],dp[i - j] + arr[j]);
		}
	}
	cout << dp[num];
	system("pause");
	return 0;
}