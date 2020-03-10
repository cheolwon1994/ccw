#include <iostream>
using namespace std;
int open[101];

int main() {
	int test, num, result;
	cin >> test;
	for (int t = 0; t < test; t++) {
		cin >> num;
		result = 0;
		for (int i = 1; i <= num; i++)
			open[i] = -1;
		for (int k = 1; k <= num; k++) 
			for (int j = k; j <= num; j += k) 
				open[j] = -open[j];
		for (int i = 1; i <= num; i++)
			if (open[i] == 1) result++;
		cout << result << '\n';
	}
	system("pause");
	return 0;
}