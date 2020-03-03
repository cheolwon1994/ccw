#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	int sum = 0, mul = 1;
	string str;
	cin >> str;
	stack<char> s;
	for (int i = 0; i < str.size(); i++) {
		char c = str[i];
		if (c == '(') {
			s.push(c);
			mul *= 2;
		}
		else if (c == '[') {
			s.push(c);
			mul *= 3;
		}
		else if(c==')' &&(s.empty() || s.top()!='(')){
			sum = 0;
			break;
		}
		else if (c == ']' && (s.empty() || s.top() != '[')) {
			sum = 0;
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
	if (!s.empty()) sum = 0;
	cout << sum;
	system("pause");
	return 0;
}