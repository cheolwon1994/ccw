#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <string.h>
using namespace std;

int alpha[26];		//어떤 글자를 가르치는지 표시
int result = 0;
int test, num, tmp, len;
vector<string> v;

void find(int start, int cnt) {
	if (cnt == num - 5) {
		int temp = 0;
		for (int i = 0; i < test; i++) {
			int flag = true;
			for (int j = 0; j < v[i].size(); j++) {
				if (alpha[v[i][j]-'a'] != 1) {
					flag = false;
					break;
				}
			}
			if (flag)
				temp++;
		}
		result = max(result, temp);
		return;
	}
	for (int i = start; i < 26; i++) {
		if (alpha[i] != 1) {
			alpha[i] = 1;
			find(i+1,cnt + 1);
			alpha[i] = 0;
		}
	}
}
int main() {
	char c;
	string str,str_tmp;
	cin >> test >> num;
	if (num < 5) {
		cout << 0;
		return 0;
	}
	for (int t = 0; t < test; t++) {
		cin >> str;
		len = str.size();
		str_tmp = str.substr(4, len-8);
		v.push_back(str_tmp);
	}
	alpha['a' - 'a'] = 1;
	alpha['c' - 'a'] = 1;
	alpha['i' - 'a'] = 1;
	alpha['n' - 'a'] = 1;
	alpha['t' - 'a'] = 1;
	find(0,0);
	cout << result << endl;
	system("pause");
	return 0;
}