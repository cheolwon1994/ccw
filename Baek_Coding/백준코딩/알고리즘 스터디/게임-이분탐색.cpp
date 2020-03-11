#define MAX 9876543210
#include <iostream>
using namespace std;

long long x, y, low = 0, mid, high = 2000000000, z, ans = MAX;
bool cal(long long val) {
	long long temp = (y + val) * 100;
	temp /= (x + val);
	if (temp != z) return true;
	return false;
}

int main() {
	cin >> x >> y;
	z = (100 * y) / x;
	while (low <= high) {
		mid = low + (high - low) / 2;
		bool res = cal(mid);
		if (res) {
			high = mid - 1;
			ans = mid;
		}
		else low = mid + 1;
	}
	if (ans == MAX) cout << -1;
	else cout << ans;
	return 0;
}