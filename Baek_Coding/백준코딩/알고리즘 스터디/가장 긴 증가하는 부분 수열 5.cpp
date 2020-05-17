#include <iostream>
#include <vector>
using namespace std;
struct info {
	long long idx, val;
};
info ans[1000000];
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
	ans[0].idx = 0;
	ans[0].val = arr[0];
	for (int i = 1; i < num; i++) {
		if (dp[idx] < arr[i]) {
			dp[++idx] = arr[i];
			ans[i].idx = idx;
			ans[i].val = arr[i];
		}
		else {
			long long val = binary_search(arr[i]);
			dp[val] = arr[i];
			ans[i].idx = val;
			ans[i].val = arr[i];
		}
	}
	cout << idx + 1 << '\n';
	long long t = idx;
	vector<long long> v;
	for (int i = num - 1; i >= 0; i--) {
		if (ans[i].idx == t) {
			v.push_back(ans[i].val);
			t--;
		}
	}
	for (int i = v.size() - 1; i >= 0; i--)
		cout << v[i] << " ";
	system("pause");
	return 0;
}