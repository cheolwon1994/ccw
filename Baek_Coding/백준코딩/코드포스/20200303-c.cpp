#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int test, num, mod, tt;
	cin >> num >> mod;
	vector<int> v;
	bool zero = false;
	int result = 1;
	bool check[1001] = { false, };
	for (int i = 0; i < num; i++) {
		cin >> tt;
		int val = tt % mod;
		if (!check[val]) {
			v.push_back(tt);
			check[val] = true;
		}
		else {
			zero = true;
		}
	}
	if (mod == 1 || zero) result = 0;
	else {
		for (int i = 0; i < v.size() - 1; i++) {
			for (int j = i + 1; j < v.size(); j++) {
				int val = abs(v[i] - v[j]);
				val %= mod;
				result *= val;
				result %= mod;
				if (result == 0) break;
			}
			if (result == 0) break;
		}
	}
	cout << result;
	return 0;
}