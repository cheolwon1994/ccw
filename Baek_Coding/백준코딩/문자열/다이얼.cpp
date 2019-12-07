#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;
	int num;
	int tot = 0;
	for (int i = 0; i < str.size(); i++) {
		num = str[i] - 'A';
		if (num >= 24)
			num = 10;
		else if (15 <= num && num <= 18)
			num = 8;
		else if (18 < num &&num <= 21)
			num = 9;
		else
			num = num / 3 + 3;
		tot += num;
	}
	cout << tot;	
	system("pause");
	return 0;
}