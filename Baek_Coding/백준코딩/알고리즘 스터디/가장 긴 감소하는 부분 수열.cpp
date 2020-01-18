#include <iostream>
#include <algorithm>
using namespace std;
int num, result = 0;
int arr[1001];
int dp[1001] = { 1, };

int main() {
	cin >> num;
	for (int i = 0; i < num; i++)
		cin >> arr[i];
	for (int i = 0; i < num; i++) {
		dp[i] = 1;
		for (int j = 0; j <= i; j++) {
			if (arr[j] > arr[i] && dp[j] + 1 > dp[i])
				dp[i] = dp[j] + 1;
		}
	}
	for (int i = 0; i < num; i++) 
		result = max(result, dp[i]);
	cout << result << endl;
	system("pause");
	return 0;
}