#include <iostream>
#include <algorithm>
using namespace std;
long long arr[200000];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int test;
	cin >> test;
	for (int t = 0; t < test; t++) {
		int num;
		cin >> num;
		for (int i = 0; i < num * 2; i++) 
			cin >> arr[i];
		sort(arr, arr + 2 * num);
		cout << arr[num] - arr[num - 1] << '\n';
	}
	return 0;
}