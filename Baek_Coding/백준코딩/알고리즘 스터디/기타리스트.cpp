#include <iostream>
using namespace std;
int arr[101];
bool dp[101][1001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, s, maxi, result = -1;
	cin >> n >> s >> maxi;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	dp[0][s] = true;
	for (int i = 0; i < n; i++) {
		int val = arr[i + 1];
		for (int j = maxi; j >= 0; j--) {
			if (dp[i][j]) {
				if (j + val <= maxi)
					dp[i + 1][j + val] = true;
				if (j - val >= 0)
					dp[i + 1][j - val] = true;
			}
		}
		
	}
	for (int i = maxi; i >= 0; i--) {
		if (dp[n][i]) {
			result = i;
			break;
		}
	}
	cout << result;
	return 0;
}