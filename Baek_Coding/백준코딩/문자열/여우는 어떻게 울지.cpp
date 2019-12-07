#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

string str;
int num;
struct info {
	string str;
	int val;
};
info tmp;
int main() {
	cin >> num;
	getline(cin, str);
	for (int t = 0; t < num; t++) {
		vector<info> v;
		getline(cin, str);
		istringstream ss(str);
		string buffer;
		while (getline(ss, buffer, ' ')) {
			tmp.str = buffer.c_str();
			tmp.val = 1;
			v.push_back(tmp);
		}
		vector<info> comp;
		while (1) {
			getline(cin, str);
			istringstream ss(str);
			string buffer;
			bool flag = false;
			bool finish = false;
			while (getline(ss, buffer, ' ')) {
				if (!strcmp(buffer.c_str(),"what")) {
					finish = true;
					break;
				}
				if (flag) {
					tmp.str = buffer.c_str();
					tmp.val = 1;
					comp.push_back(tmp);
					break;
				}
				if (!strcmp(buffer.c_str(), "goes"))
					flag = true;
			}
			if (finish)
				break;
		}

		for (int i = 0; i < v.size(); i++) {
			for (int j = 0; j <= comp.size(); j++) {
				if (j == comp.size()) {
					cout << v[i].str << " ";
					break;
				}
				if (v[i].str == comp[j].str)
					break;
			}
		}
	}
	system("pause");
	return 0;
}