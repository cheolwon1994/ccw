#include <iostream>
#include <algorithm>
using namespace std;
int arr[1000000], dp[1000000], num, idx = 0;

int binary_search(int end, int val) {
	int l = 0, r = end, mid, result = end;
	while (l <= r) {
		mid = l + (r - l) / 2;
		if (dp[mid] >= val) {
			r = mid - 1;
			result = mid;
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
		if (arr[i] > dp[idx]) {
			dp[++idx] = arr[i];
		}
		else {
			int val = binary_search(idx, arr[i]);
			dp[val] = arr[i];
		}
	}
	cout << idx + 1;
	system("pause");
	return 0;
}