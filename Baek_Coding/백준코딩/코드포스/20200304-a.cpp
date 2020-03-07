#include <iostream>
using namespace std;
int arr[1000];
int main() {
	int test, num, maxi, result;
	cin >> test;
	for (int t = 0; t < test; t++) {
		cin >> num >> maxi;
		long long sum = 0;
		for (int i = 0; i < num; i++) {
			cin >> arr[i];
			sum += arr[i];
			if (sum >= maxi) 
				result = maxi;			
		}
		if (sum < maxi)
			result = sum;
		cout << result << endl;
	}
	return 0;
}