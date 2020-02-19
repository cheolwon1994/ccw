#include <iostream>
#include <algorithm>
using namespace std;
int num, b, s;
int arr[1001][1001];
int dp[1001][1001];

int main() {
	cin >> num;
	int t1, t2, maxi = 0;
	for (int i = 0; i < num; i++) {
		cin >> t1 >> t2;
		b = t1 > t2 ? t1 : t2;
		maxi = max(maxi, b);
		s = t1 < t2 ? t1 : t2;
		arr[s][b] += 1;
	}
	int result = 0;
	for (int i = 1; i <= maxi; i++) {
		for (int j = i; j <= maxi; j++) {
			dp[i][j] = max(dp[i - 1][j],dp[i][j-1]) + arr[i][j];
			result = max(result, dp[i][j]);
		}
	}
	cout << result;
	system("pause");
	return 0;
}