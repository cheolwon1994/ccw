#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
string ans="";
vector <string> v;
int main() {
	int num, len;
	string tmp;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	len = v[0].size();

	for (int i = 0; i < len; i++) {
		int flag = 0;
		char c = v[0][i];
		for (int j = 1; j < num; j++) {
			if (v[j][i] != c) {
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			ans += '?';
		else
			ans += c;
	}
	cout << ans;
	system("pause");
	return 0;
}