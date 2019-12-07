#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <string>
int arr[26];
using namespace std;
int main() {
	string str;
	cin >> str;
	for (int i = 0; i < 26; i++)
		arr[i] = -1;
	int tmp;
	for (int i = 0; i < str.size(); i++) {
		tmp = str[i]-'a';
		if (arr[tmp] == -1)
			arr[tmp] = i;
	}
	for (int i = 0; i < 26; i++)
		cout << arr[i] << " ";
	system("pause");
	return 0;
}