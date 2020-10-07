#include <iostream>
#include <algorithm>
using namespace std;
int dp[1000], arr[1000], second[1000];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int num, result = 1;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> arr[i];
		dp[i] = 1;
	}
	for (int i = 1; i < num; i++) {
		int maxi = 0;
		int idx = i;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				if (dp[j] > maxi)
					maxi = dp[j];
			}
		}
		dp[i] = maxi + 1;
		result = max(result, dp[i]);
	}
	cout << result;
	return 0;
}