#include <iostream>
using namespace std;
long long x, y, z, ans, mod;
int main() {
	cin >> x >> y;
	z = (100 * y) / x;
	if (z >= 99) cout << -1;
	else {
		ans = (z + 1)*x - 100 * y;
		mod = 99 - z;
		if (ans%mod == 0) cout << ans / mod;
		else cout << ans / mod + 1;
	}
	system("pause");
	return 0;
}