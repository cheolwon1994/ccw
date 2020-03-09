#include <iostream>
#include <algorithm>
using namespace std;
long long result = -1;
int arr[100000];
int num, blue;

bool binarySearch(int val) {
	int cnt = 1;
	long long tot = 0;
	for (int i = 0; i < num; i++) {
		if (arr[i] > val) 
			return false;		
		tot += arr[i];
		if (tot > val) {
			tot = arr[i];
			cnt++;
		}
	}
	if (cnt <= blue) return true;
	else return false;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	long long sum = 0;
	cin >> num >> blue;
	for (int i = 0; i < num; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	long long low = 0, mid, high = sum;
	while (low <= high) {
		mid = low + (high - low) / 2;
		bool flag = binarySearch(mid);
		if (flag) {
			high = mid - 1;
			result = mid;
		}
		else low = mid + 1;
	}
	cout << result;
	system("pause");
	return 0;
}
