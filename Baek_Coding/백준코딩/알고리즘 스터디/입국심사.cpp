#include <iostream>
#include <algorithm>
using namespace std;
long long arr[100000];
int num, people;
long long low, high, mid, result;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> num >> people;
	low = 0;
	high = 0;
	for (int i = 0; i < num; i++) {
		cin >> arr[i];
		high = max(high, arr[i]);
	}
	high *= people;
	while (low <= high) {
		long long sum = 0;
		mid = low + (high - low) / 2;
		for (int i = 0; i < num; i++)
			sum += mid / arr[i];
		if (sum < people)
			low = mid + 1;
		else {
			result = mid;
			high = mid - 1;
		}
	}	
	cout << result;
	system("PAUSE");
	return 0;
}