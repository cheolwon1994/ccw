#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str, result = "";
	int num;
	char c, c2, tp;
	cin >> str >> num;
	stack<char> r;
	deque<char> dq;
	for (int i = 0; i < str.size(); i++)
		dq.push_back(str[i]);
	for (int i = 0; i < num; i++) {
		cin >> c;
		if (c == 'L') {
			if (dq.empty()) continue;
			else {
				tp = dq[dq.size() - 1];
				dq.pop_back();
				r.push(tp);
			}
		}
		else if (c == 'D') {
			if (r.empty()) continue;
			else {
				tp = r.top();
				r.pop();
				dq.push_back(tp);
			}
		}
		else if (c == 'B') {
			if (dq.empty()) continue;
			else 	dq.pop_back();			
		}
		else {
			cin >> c2;
			dq.push_back(c2);
		}
	}
	for (int i = 0; i < dq.size(); i++)
		result += dq[i];
	while (!r.empty()) {
		result += r.top();
		r.pop();
	}

	cout << result;
	return 0;
}