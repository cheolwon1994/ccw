#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
long long a[500000];
long long b[500000];
vector <long long> v;
int main() {
	int n, m;
	long long tt, low, high, mid;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &tt);
		a[i] = tt;
	}
	for (int i = 0; i < m; i++) {
		scanf("%lld", &tt);
		b[i] = tt;
	}
	sort(a, a + n);
	sort(b, b + m);
	bool flag;
	for (int i = 0; i < n; i++) {
		flag = false;
		tt = a[i];
		low = 0;
		high = m - 1;
		while (low <= high) {
			mid = low + (int)((high - low) / 2);
			if (b[mid] == tt) { flag = true; break; }
			else if (tt > b[mid]) low = mid + 1;
			else high = mid - 1;
		}
		if (!flag) v.push_back(tt);
	}
	printf("%d\n", v.size());
	for (int i = 0; i < v.size(); i++)
		printf("%lld ", v[i]);
	system("pause");
	return 0;
}