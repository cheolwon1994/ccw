#include <iostream>
#include <math.h>
using namespace std;
long long result = 0;
long long num;

int main() {
	cin >> num;
	long long tmp = num;
	int len = 1;
	while (tmp > 0) {
		if (tmp / 10 > 0) {
			tmp /= 10;
			len++;
		}
		else
			break;
	}
	for (int i = 1; i < len; i++)
		result += 9 * pow(10, i - 1)*i;
	result += (num - pow(10, len - 1)+1)*len;
	cout << result;
	system("pause");
	return 0;
}