#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
char first[3],second[3];

int main() {
	string str;
	cin >> str;
	for (int i = 0; i < 3; i++)
		first[i] = str[2 - i];
	cin >> str;
	for (int i = 0; i < 3; i++)
		second[i] = str[2 - i];
	
	for (int i = 0; i < 3; i++) {
		if (first[i] > second[i]) {
			for (int j = 0; j < 3; j++)
				cout << first[j];
			break;
		}
		else if (first[i] < second[i]) {
			for (int j = 0; j < 3; j++)
				cout << second[j];
			break;
		}
		else
			continue;
	}	
	system("pause");
	return 0;
}