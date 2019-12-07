#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>

using namespace std;
int num[10];
void fill() {
	for (int i = 0; i < 10; i++) {
		if (i == 6 || i == 9) {
			num[6] += 1;
			num[9] += 1;
		}
		else
			num[i] += 1;
	}
}

int main() {
	string str;
	cin >> str;
	int tmp;
	int cnt = 0;
	for (int i = 0; i < str.size(); i++) {
		tmp = str[i] - '0';
		if (tmp == 6 || tmp == 9) {
			if (num[tmp] == 0) {
				cnt++;
				fill();
			}
			num[6] -= 1;
			num[9] -= 1;
		}
		else {
			if (num[tmp] == 0) {
				cnt++;
				fill();
			}
			num[tmp] -= 1;
		}
	}
	cout << cnt;
	system("pause");
	return 0;
}
