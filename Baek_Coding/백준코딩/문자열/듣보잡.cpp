#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;
multiset<string> ms;
set<string> s;
int main() {
	int hear, see;
	string str;
	cin >> hear >> see;
	for (int i = 0; i < hear + see; i++) {
		cin >> str;
		ms.insert(str);
	}
	for (auto it = ms.begin(); it != ms.end(); it++) {
		str = *it;
		if (ms.count(str) != 1) {
			s.insert(str);
		}
	}
	cout << s.size() << endl;
	for (auto it = s.begin(); it != s.end(); it++)
		cout << *it << endl;
	system("pause");
	return 0;
}