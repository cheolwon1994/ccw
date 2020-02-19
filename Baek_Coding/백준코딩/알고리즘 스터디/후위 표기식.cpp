#include <iostream>
#include <string>
#include <stack>
using namespace std;
stack<char> s;

int getIcp(char c) {
	switch (c) {
	case '+': 
	case '-':
		return 1;
	case '/':
	case '*':
		return 2;
	case'(':
		return 3;
	default:
		return 0;
	}
}

int getIsp() {
	char c = s.empty() ? ' ' : s.top();
	switch (c) {
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	case '(':
	default:
		return 0;
	}
}

int main() {
	string str,result="";
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		char c = str[i];
		if ('A' <= c && c <= 'Z')
			result += c;
		else if (c == ')') {
			char ch;
			while (s.top() != '(') {
				ch = s.top();
				s.pop();
				result += ch;
			}
			if(s.top()=='(')	s.pop();
		}
		else {
			while (getIcp(c) <= getIsp()) {
				result += s.top();
				s.pop();
			}
			s.push(c);
		}
	}
	while (!s.empty()) {
		result += s.top();
		s.pop();
	}
	cout << result;
	system("pause");
	return 0;
}