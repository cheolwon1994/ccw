#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str;
	int t = 1, result;
	while (1) {
		cin >> str;
		if (str[0] == '-') break;
		result = 0;
		stack<char> s;
		for (int i = 0; i < str.size(); i++) {
			char c = str[i];
			if (c == '}' && !s.empty() && s.top() == '{')
				s.pop();
			else
				s.push(c);
		}
		while (!s.empty()) {
			char c1 = s.top();
			s.pop();
			char c2 = s.top();
			s.pop();
			if (c1 == c2) result++;
			else result += 2;
		}
		cout << t << ". " << result << '\n';
		t++;
	}
	return 0;
}