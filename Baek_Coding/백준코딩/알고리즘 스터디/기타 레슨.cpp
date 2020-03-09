#include <iostream>
#include <algorithm>
using namespace std;
long long result = -1;
int arr[100000];
int num, blue;
bool cal(long long val) {
	long long temp = 0, t_result = 0;
	int idx = 0, cnt = 1;
	while (idx < num) {
		if (t_result + arr[idx] <= val) {
			t_result += arr[idx];
			idx++;
		}
		else {
			temp = max(temp, t_result);
			t_result = 0;
			cnt++;
		}
	}
	temp = max(temp, t_result);
	if (cnt <= blue) {
		if (cnt == blue) {
			result = min(result, temp);
		}
		return false;
	}
	else
		return true;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	long long sum = 0;
	cin >> num >> blue;
	for (int i = 0; i < num; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	long long low = 0, mid, high = sum;
	while (low <= high) {
		mid = low + (high - low) / 2;
		int cnt = 0;
		long long tot = 0;
		for (int i = 0; i < num; i++) {
			tot += arr[i];
			if (tot > mid) {
				tot = arr[i];
				cnt++;
			}
			else if (tot <= mid && i == num - 1) {
				cnt++;
				tot = 0;
			}
		}
		if (tot > 0) cnt++;
		if (cnt <= blue) high = mid - 1;
		else low = mid + 1;
	}
	long long temp = 0;
	for (int i = 0; i < num; i++) {
		temp += arr[i];
		if (temp > low) {
			result = max(result, temp - arr[i]);
			temp = arr[i];
		}
	}
	result = max(result, temp);
	cout << result;
	system("pause");
	return 0;
}