#include <iostream>
#include <string>
using namespace std;

long long power(int x, int y) {
	if (y == 0) return 1;
	else if (y == 1) return x;
	else if (y % 2 == 0) {
		long long tt = power(x, y / 2);
		return (tt * tt) % 1234567891;
	}
	else {
		long long tt = power(x, y-1);
		return (x * tt) % 1234567891;
	}
}
int main() {
	int len;
	string str;
	cin >> len >> str;
	long long result = 0;
	for (int i = 0; i < len; i++) {
		int a = str[i] - 'a';
		result = (result + (a+1) * power(31, i)) % 1234567891;
	}
	cout << result % 1234567891;
}