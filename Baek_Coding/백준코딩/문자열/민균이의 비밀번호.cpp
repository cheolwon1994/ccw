#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
multiset<string> ms;

int main() {
	int num;
	cin >> num;
	string str,str_tmp;
	for (int i = 0; i < num; i++) {
		str_tmp = "";
		cin >> str;
		for (int j = str.size() - 1; j >= 0; j--)
			str_tmp += str[j];
		ms.insert(str);
		ms.insert(str_tmp);
	}
	for (auto it = ms.begin(); it != ms.end(); it++) {
		if (ms.count(*it) > 1) {
			str = *it;
			break;
		}
	}
	cout << str.size()<<" " << str[str.size() / 2];
	system("pause");
	return 0;
}