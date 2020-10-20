#include <iostream>
#include <algorithm>
using namespace std;
int n, k, result = 0;
int w[100], v[100];
int dp[100][100001];

int knapsack(int idx, int remain) {
	if (idx == n) return 0;
	int ret = dp[idx][remain];
	if (ret != -1) return ret;
	//챙긴다
	if (remain >= w[idx])
		ret = knapsack(idx + 1, remain - w[idx]) + v[idx];
	//안챙긴다
	ret = max(ret, knapsack(idx+1, remain));
	return dp[idx][remain] = ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> w[i] >> v[i];
		for (int j = 0; j <= k; j++)
			dp[i][j] = -1;
	}
	result = knapsack(0, k);
	cout << result;
	return 0;
}