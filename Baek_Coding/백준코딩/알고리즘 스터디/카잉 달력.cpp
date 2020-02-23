#include <iostream>
#include <algorithm>
using namespace std;

int test, sa, sb, ta, tb;

int gcd(int a, int b) {
	int tmp, n;
	if (a < b) {
		tmp = a;
		a = b;
		b = tmp;
	}
	while (b != 0) {
		n = a % b;
		a = b;
		b = n;
	}
	return a;
}

int main() {
	int tt;
	cin >> test;
	for (int t = 0; t < test; t++) {
		cin >> sa >> sb >> ta >> tb;
		if (sa > sb) {
			tt = sa;
			sa = sb;
			sb = tt;
			tt = ta;
			ta = tb;
			tb = tt;
		}
		int result = -1;
		int maxi = sb / gcd(sa, sb);
		for (int i = 0; i <= maxi; i++) {
			int val = sa * i + ta;
			if (val%sb == tb % sb) {
				result = val;
				break;
			}
		}
		cout << result << '\n';
	}
	system("pause");
	return 0;
}