#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <vector>
using namespace std;

int main() {
	int test, num;
	string str, t_str;
	cin >> test;
	for (int t = 0; t < test; t++) {
		cin >> num;
		bool result = true;
		vector<string> ss;
		set<string> s;
		set<string>::iterator it;
		for (int i = 0; i < num; i++) {
			cin >> str;
			ss.push_back(str);
		}
		sort(ss.begin(), ss.end());
		for(int i=0;i<num;i++){
			str = ss[i];
			for (int j = 0; j < str.size(); j++) {
				t_str =str.substr(0,j+1);
				it = s.find(t_str);
				if (it != s.end()) {
					result = false;
					break;
				}
			}
			if (result)
				s.insert(str);
			else
				break;
		}
		if (result) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	system("pause");
	return 0;
}