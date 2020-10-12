#include <iostream>
#include <algorithm>
using namespace std;
int arr[1000], dp[1000];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int len;
	cin >> len;
	for (int i = 0; i < len; i++)
		cin >> arr[i];
	dp[0] = 1;
	int result = 1;
	for (int i = 1; i < len; i++) {
		int cv = arr[i];
		int maxi = 0, idx;
		for (int j = 0; j < i; j++) {
			int pv = arr[j];
			if (pv < cv) {
				if (dp[j] > maxi) {
					maxi = dp[j];
					idx = j;
				}
				else if (dp[j] == maxi) {
					if (arr[idx] > arr[j])
						idx = j;
				}
			}
		}
		dp[i] = maxi + 1;
		result = max(result, dp[i]);
	}
	cout << result;
	return 0;
}