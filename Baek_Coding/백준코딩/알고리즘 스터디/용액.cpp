#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
long long arr[100000];
long long result[2];
long long ans = 2000000001;

int main() {
	int num;
	cin >> num;
	long long tt, low, high, mid, f;
	bool flag, finish = false;
	for (int i = 0; i < num; i++)
		scanf("%lld", &arr[i]);
	for (int i = 0; i < num; i++) {
		f = arr[i];
		low = i + 1;
		high = num - 1;
		flag = false;
		while (low <= high) {
			mid = low + (int)(high - low) / 2;
			if (f + arr[mid] == 0) {
				finish = true;
				result[0] = f;
				result[1] = arr[mid];
				break;
			}
			else if (f + arr[mid] < 0) {
				if (ans > abs(f + arr[mid])) {
					ans = abs(f + arr[mid]);
					result[0] = f;
					result[1] = arr[mid];
				}
				low = mid + 1;
			}
			else if (f + arr[mid] > 0) {
				if (ans > f + arr[mid]) {
					ans = f + arr[mid];
					result[0] = f;
					result[1] = arr[mid];
				}
				high = mid - 1;
			}
		}
		if (finish)
			break;
	}
	cout << result[0] << " " << result[1];
	system("pause");
	return 0;
}