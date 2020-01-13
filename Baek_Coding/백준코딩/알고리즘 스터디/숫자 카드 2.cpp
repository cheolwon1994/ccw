#define _CRT_SECURE_NO_WARNINGS
#define MAX 10000000
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> arr;
int check[2 * MAX + 1] = { 0, };

int main() {
	int n, m;
	long long low, high, mid, tt, cnt;
	cnt = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &tt);
		tt += MAX;
		if (check[tt] == 0) {
			check[tt]++;
			cnt++;
			arr.push_back(tt);
		}
		else
			check[tt]++;
	}
	sort(arr.begin(), arr.end());
	scanf("%d", &m);
	bool flag;
	for (int i = 0; i < m; i++) {
		scanf("%lld", &tt);
		tt += MAX;
		flag = false;
		low = 0;
		high = cnt - 1;
		while (low <= high) {
			mid = low + (int)((high - low) / 2);
			if (arr[mid] == tt) { flag = true; break; }
			else if (arr[mid] < tt)  low = mid + 1; 
			else high = mid - 1;
		}
		if (!flag)	printf("0 ");
		else if (flag) printf("%d ",check[arr[mid]]);
	}
	system("pause");
	return 0;
}