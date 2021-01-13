#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str;
	cin >> str;
	int s = 0;		//스택
	int result = 0;
	for (int i = 0; i < str.size(); i++) {
		char c = str[i];
		if (c == '(') {
			if (str[i + 1] == ')') {
				result += s;
				i++;
			}
			else
				s++;
		}
		else {
			result++;
			s--;
		}
	}
	result += s;
	cout << result;
	return 0;
}