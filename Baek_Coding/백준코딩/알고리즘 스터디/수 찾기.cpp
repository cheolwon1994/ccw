#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int arr[100001];
int main() {
	int n, m, tt, low, high, mid;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) 
		scanf("%d", &arr[i]);
	sort(arr, arr + n);
	cin >> m;
	bool flag;
	for (int i = 0; i < m; i++) {
		scanf("%d", &tt);
		low = 0;
		high = n - 1;
		flag = false;
		while (low <= high) {
			mid = low + (high - low) / 2;
			if (tt == arr[mid]) { flag = true; break; }
			else if (tt > arr[mid]) low = mid + 1;			
			else high = mid - 1;
		}
		if (flag)	printf("1\n");
		else	printf("0\n");
	}
	system("pause");
	return 0;
}