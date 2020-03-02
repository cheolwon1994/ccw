#include <iostream>
#include <math.h>
using namespace std;
int num;
int arr[4] = { 2,3,5,7 };

bool check(int a) {
	int i = 2;
	while (1) {
		if (i <= sqrt(a)) {
			if (a%i == 0) {
				return false;
			}
			else i++;
		}
		else
			return true;
	}
}

void start(int cnt, int sum) {
	if (cnt == num) {
		cout << sum << '\n';
		return;
	}
	for (int i = 1; i < 10; i++) {
		int tt = sum * 10 + i;
		if (check(tt))
			start(cnt + 1, tt);
	}
}

int main() {
	cin >> num;
	for (int i = 0; i < 4; i++)
		start(1, arr[i]);

	system("pause");
	return 0;
}