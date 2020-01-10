#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;
map<string,bool> m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int num;
	cin >> num;
	string str1, str2;
	for (int i = 0; i < num; i++) {
		cin >> str1 >> str2;
		if (str2 == "enter")
			m[str1] = true;
		else
			m[str1] = false;
	}
	map<string, bool> ::reverse_iterator iter;
	for (iter = m.rbegin(); iter != m.rend(); ++iter) 
		if (iter->second == 1)
			cout << iter->first << "\n";
	system("pause");
	return 0;
}
