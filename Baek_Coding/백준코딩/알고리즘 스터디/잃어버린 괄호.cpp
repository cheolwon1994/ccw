#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
vector<char> op;
vector<int> num;

int main() {
	string str;
	cin >> str;
	int idx = 0;
	for (int i = 0; i <= str.size(); i++) {
		if (str[i] == '+' || str[i] == '-' ||i==str.size()) {
			op.push_back(str[i]);
			string ss="";
			for (int j = idx; j < i; j++) 
				ss += str[j];			
			num.push_back(atoi(ss.c_str()));
			idx = i + 1;
		}
	}
	int result = num[0];
	bool minus = false;
	for (int i = 0; i < op.size(); i++) {
		if (op[i] == '+') {
			if (!minus)
				result += num[i + 1];
			else
				result -= num[i + 1];
		}
		else if (op[i] == '-') {
			if(!minus) minus = true;
			result -= num[i + 1];
		}
	}
	cout << result;
	system("pause");
	return 0;
}