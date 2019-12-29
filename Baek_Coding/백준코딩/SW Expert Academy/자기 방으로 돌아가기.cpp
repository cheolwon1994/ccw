#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int arr[201];

int main() {
	int test, num, f, s;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		memset(arr, 0, sizeof(arr));
		cin >> num;
		for (int j = 0; j < num; j++) {
			cin >> f >> s;
			if (f > s) {
				int tmp = s;
				s = f;
				f = tmp;
			}
			f = (f + 1) / 2;
			s = (s + 1) / 2;
			for (int k = f; k <= s; k++)
				arr[k] += 1;
		}
		int result = 0;
		for (int j = 1; j <= 200; j++)
			result = max(result, arr[j]);
		cout << "#" << t << " " << result << endl;
	}
	system("pause");
	return 0;
}