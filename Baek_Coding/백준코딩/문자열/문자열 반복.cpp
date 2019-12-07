#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int test, num;
	cin >> test;
	string str;
	for (int k = 0; k < test; k++) {
		cin >> num >> str;
		for (int i = 0; i < str.size(); i++)
			for (int j = 0; j < num; j++)
				cout << str[i];
		cout << endl;
	}
	system("pause");
	return 0;
}