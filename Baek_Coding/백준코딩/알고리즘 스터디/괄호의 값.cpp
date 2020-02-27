#include <iostream>
#include <stack>
#include <string>
using namespace std;
stack<char> s;
string str;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> str;
	int len = str.size();
	int sum = 0;
	int mul = 1;
	bool impossible = false;
	for (int i = 0; i < len; i++) {
		char c = str[i];
		if (c == '(') {
			mul *= 2;
			s.push(c);
		}
		else if (c == '[') {
			mul *= 3;
			s.push(c);
		}
		else if (c == ')' && (s.empty() || s.top() != '(')) {
			impossible = true;
			break;
		}
		else if (c == ']' && (s.empty() || s.top() != '[')) {
			impossible = true;
			break;
		}
		else if (c == ')') {
			if (str[i - 1] == '(')
				sum += mul;
			mul /= 2;
			s.pop();
		}
		else if (c == ']') {
			if (str[i - 1] == '[')
				sum += mul;
			mul /= 3;
			s.pop();
		}
		
	}
	if (!s.empty() || impossible) sum = 0;
	cout << sum;
	system("pause");
	return 0;
}