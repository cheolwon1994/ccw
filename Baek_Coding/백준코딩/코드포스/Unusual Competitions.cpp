#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int num, ans = -1;
	cin >> num;
	string str;
	cin >> str;
	int l = 0, r = 0, cnt = 0, result = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') l++;
		else r++;
	}
	
	if (num % 2 == 1 || l-r!=0) cout << -1;
	else {
		l = 0; r = 0;
		for (int i = 0; i < str.size(); i++) {
			char c = str[i];
			if (c == '(') {
				if (r == 0) {
					l++;
					cnt++;
				}
				else {
					r--;
					cnt++;
					if (r == 0) {
						result += cnt;
						cnt = 0;
					}
				}
			}
			else if (c == ')') {
				if (l == 0) {
					r++;
					cnt++;
				}
				else {
					l--;
					cnt++;
					if (l == 0) {
						cnt = 0;
						l = 0;
						r = 0;
					}
				}
			}
		}
		cout << result;
	}	
	return 0;
}