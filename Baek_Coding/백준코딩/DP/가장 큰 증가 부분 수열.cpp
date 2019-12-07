#include <iostream>
#include <algorithm>
using namespace std;
int arr[1000];
int dp[1000];
int num;
long long maxi = 0;

int main() {
	cin >> num;
	for (int i = 0; i < num; i++)
		cin >> arr[i];
	dp[0] = arr[0];
	maxi = arr[0];
	for (int i = 1; i < num; i++) {
		dp[i] = arr[i];
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && dp[i] < dp[j] + arr[i]) 
				dp[i] = dp[j] + arr[i];
		}
		if (maxi < dp[i])
			maxi = dp[i];
	}
	cout << maxi;
	system("pause");
	return 0;
}