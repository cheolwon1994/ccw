#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

long long arr[500001];
int main() {
	int n, m;
	long long tt, low, high, mid;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) 
		scanf("%lld", &arr[i]);
	sort(arr, arr + n);
	bool flag;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%lld", &tt);
		low = 0;
		high = n - 1;
		flag = false;
		while (low <= high) {
			mid = low + (int)((high - low) / 2);
			if (arr[mid] == tt) { flag = true; break; }
			else if (tt > arr[mid]) low = mid + 1;
			else high = mid - 1;
		}
		if (flag) printf("1 ");
		else printf("0 ");
	}
	system("pause");
	return 0;
}