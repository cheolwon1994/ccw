#include <iostream>
using namespace std;
long long arr[1000000], dp[1000000], idx = 0, num;

long long binary_search(long long val) {
	long long l = 0, r = idx, mid, result = idx;
	while (l <= r) {
		mid = l + (r - l) / 2;
		if (dp[mid] >= val) {
			result = mid;
			r = mid - 1;
		}
		else
			l = mid + 1;
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> num;
	for (int i = 0; i < num; i++)
		cin >> arr[i];
	dp[0] = arr[0];
	for (int i = 1; i < num; i++) {
		if (dp[idx] < arr[i]) {
			dp[++idx] = arr[i];
		}
		else {
			long long v = binary_search(arr[i]);
			dp[v] = arr[i];
		}
	}
	cout << idx + 1;
	system("pause");
	return 0;
}