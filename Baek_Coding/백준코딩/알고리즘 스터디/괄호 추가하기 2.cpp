#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
string str;
int num;
long long result = -987654321;
vector<char> v;


void cal() {
	int idx = 0;
	vector<string> s;
	if (v[idx] != '(') {
		int val = v[idx] - '0';
		s.push_back(to_string(val));
		idx = 1;
	}
	while (idx < v.size()) {
		if (v[idx] == '(') {
			int val = 0;
			if (v[idx + 2] == '+') 
				val = ((v[idx + 1] - '0') + (v[idx + 3] - '0'));			
			else if (v[idx + 2] == '-') 
				val = ((v[idx + 1] - '0') - (v[idx + 3] - '0'));		
			s.push_back(to_string(val));
			idx += 5;
		}
		else if (v[idx] == '+') {
			s.push_back("+");
			idx += 1;
		}
		else if (v[idx] == '-') {
			s.push_back("-");
			idx += 1;
		}
		else if (v[idx] == '*') {
			s.push_back("*");
			idx += 1;
		}
		else {
			int val = v[idx] - '0';
			s.push_back(to_string(val));
			idx += 1;
		}
	}
	/*for (int i = 0; i < s.size(); i++) {
		cout << s[i] << " ";
	}
	cout << endl;*/
	vector<string> ans;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == "*") {
			int val = atoi(ans[ans.size() - 1].c_str());
			val *= atoi(s[i + 1].c_str());
			ans.pop_back();
			ans.push_back(to_string(val));
			i++;
		}
		else
			ans.push_back(s[i]);		
	}
	/*for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";*/
	long long t_result = atol(ans[0].c_str());
	for (int i = 1; i < ans.size(); i++) {
		long long val = atol(ans[i + 1].c_str());
		if (ans[i] == "-") {
			t_result -= val;
			i++;
		}
		else if (ans[i] == "+") {
			t_result += val;
			i++;
		}		
	}
	result = max(result, t_result);
}

void start(int idx) {
	if (idx == num - 1) {
		cal();
		return;
	}
	if (str[idx + 1] == '+' && v[v.size()-1]!=')') {
		char c = v[v.size()-1];
		v.pop_back();
		v.push_back('(');
		v.push_back(c);
		v.push_back('+');
		v.push_back(str[idx + 2]);
		v.push_back(')');
		start(idx + 2);
		v.pop_back();
		v.pop_back();
		v.pop_back();
		v.pop_back();
		v.pop_back();
		v.push_back(c);
	}
	else if (str[idx + 1] == '-' && v[v.size() - 1] != ')') {
		char c = v[v.size() - 1];
		v.pop_back();
		v.push_back('(');
		v.push_back(c);
		v.push_back('-');
		v.push_back(str[idx + 2]);
		v.push_back(')');
		start(idx + 2);
		v.pop_back();
		v.pop_back();
		v.pop_back();
		v.pop_back();
		v.pop_back();
		v.push_back(c);
	}
	v.push_back(str[idx + 1]);
	v.push_back(str[idx + 2]);
	start(idx + 2);
	v.pop_back();
	v.pop_back();
}

int main() {
	cin >> num >> str;
	v.push_back(str[0]);
	start(0);
	cout << result;
	system("pause");
	return 0;
}