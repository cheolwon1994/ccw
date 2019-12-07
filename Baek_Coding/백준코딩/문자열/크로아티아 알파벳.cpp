#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <map>

using namespace std;

map <string, int> m;
int result = 0;
int len;
string str, tmp;

void test(int cnt) {
	if (cnt == len)
		return;
	bool flag = false;
	if (len - cnt > 1) {
		if (str[cnt] == 'd') {
			if (len - cnt >= 3) {
				if (str[cnt] == 'd' && str[cnt + 1] == 'z' && str[cnt + 2] == '=') {
					result++;
					flag = true;
					test(cnt + 3);
				}
			}
			if (str[cnt + 1] == '-') {
				result++;
				flag = true;
				test(cnt + 2);
			}
		}
		else if (str[cnt] == 'c') {
			if (str[cnt + 1] == '=') {
				result++;
				flag = true;
				test(cnt + 2);
			}
			else if (str[cnt + 1] == '-') {
				result++;
				flag = true;
				test(cnt + 2);
			}
		}
		else if (str[cnt] == 'l' && str[cnt + 1] == 'j') {
			result++;
			flag = true;
			test(cnt + 2);
		}
		else if (str[cnt] == 'n' && str[cnt + 1] == 'j') {
			result++;
			flag = true;
			test(cnt + 2);
		}
		else if (str[cnt] == 's' && str[cnt + 1] == '=') {
			result++;
			flag = true;
			test(cnt + 2);
		}
		else if (str[cnt] == 'z' && str[cnt + 1] == '=') {
			result++;
			flag = true;
			test(cnt + 2);
		}
	}
	if(!flag){
		result++;
		test(cnt + 1);
	}
}

int main() {
	cin >> str;
	len = str.size();
	test(0);
	cout << result;
	return 0;
}