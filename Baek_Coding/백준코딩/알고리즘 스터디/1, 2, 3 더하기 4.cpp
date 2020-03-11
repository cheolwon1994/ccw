#include <iostream>
using namespace std;

int main() {
	int num, test;
	long long result;
	cin >> test;
	for (int t = 0; t < test; t++) {
		cin >> num;
		result = 0;
		int q = num / 3, remain;
		for (int i = 0; i <= q; i++) {
			remain = num - 3 * i;
			result += ((remain / 2) + 1);
		}
		cout << result << '\n';
	}
	system("pause");
	return 0;
}