#include <iostream>
using namespace std;
long long money[200000];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int test, l, r, num, con, k, val, result, len;
	long long sum;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		cin >> num >> con >> k;
		//초기화
		sum = 0;
		result = l = 0;
		r = con - 1;
		len = (con == num) ? 0 : con - 1;

		for (int i = 0; i < num; i++) {
			cin >> val;
			money[i] = val;
			if (i < con) sum += val;
			if (i < len) money[i + num] = val;		
		}
		while (r < num + len) {
			if (sum < k) result++;
			r++;
			sum += money[r];
			sum -= money[l];
			l++;
		}
		cout << result << '\n';
	}
	return 0;
}