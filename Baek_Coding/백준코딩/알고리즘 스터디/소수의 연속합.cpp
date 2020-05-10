#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
int primary[4000001], num;

void cal() {
	for (int i = 2; i <= num; i++)
		primary[i] = i;
	for (int i = 2; i <= sqrt(num); i++) {
		if (primary[i] == 0) continue;
		for (int j = i + i; j <= num; j += i)
			primary[j] = 0;
	}
}

int main() {
	cin >> num;
	if (num < 2)
		cout << 0 << '\n';
	else {
		cal();
		vector<int> v;
		for (int i = 2; i <= num; i++)
			if (primary[i])
				v.push_back(i);
		int r = 0, l = 0, cnt = 0;

		int sum = v[0];
		while (l <= r && r != v.size()) {
			if (sum == num) {
				cnt++;
				if (l == r) {
					r++;
					if (r == v.size()) break;
					sum += v[r];
				}
				else {
					sum -= v[l];
					l++;
				}
			}
			else if (sum > num) {
				if (l == r) break;
				else {
					sum -= v[l];
					l++;
				}
			}
			else if (sum < num) {
				r++;
				if (r == v.size()) break;
				sum += v[r];
			}
		}
		cout << cnt;
	}
	system("pause");
	return 0;
}