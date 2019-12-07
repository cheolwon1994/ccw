#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main() {
	int num;
	int result = 0;
	string str,tmp,strl,strr;
	cin >> num >> str;
	int idx = str.find("*");
	strl = str.substr(0,idx);
	strr = str.substr(idx + 1);
	//cout << strl << " " << strr << endl;
	for (int t = 0; t < num; t++) {
		cin >> tmp;
		if (tmp.size() < str.size()-1) {
			cout << "NE" << endl;
			continue;
		}
		int flag = 1;
		if (strl.size() > tmp.size()) {
			cout << "NE" << endl;
			continue;
		}
		else {
			for (int i = 0; i < strl.size(); i++) {
				if (strl[i] != tmp[i]) {
					flag = 0;
					break;
				}
			}
		}
		if (flag == 0) {
			cout << "NE" << endl;
			continue;
		}
		if (strr.size() > tmp.size()) {
			cout << "NE" << endl;
			continue;
		}
		else {
			for (int i = 0; i < strr.size(); i++) {
				if (strr[strr.size() - 1 - i] != tmp[tmp.size() - 1 - i]) {
					flag = 0;
					break;
				}
			}
		}
		if (flag) {
			cout << "DA" << endl;
		}
		else
			cout << "NE" << endl;
	}
	system("pause");
	return 0;
}