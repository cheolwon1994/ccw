#include <string>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
int main() {
	int num, len;
	string str1, str2, ansl = "", ansr = "", ansm = "";
	map<string,int> m;
	map<string,int> ::iterator it;
	cin >> num >> len;
	for (int i = 0; i < num; i++) {
		cin >> str1;
		str2 = str1;
		reverse(str2.begin(), str2.end());
		it = m.find(str2);
		if (it != m.end() && it->second==1) {		//거꾸로인것이 존재한다면
			ansl += str1;
			ansr = str2 + ansr;
			it->second = 0;
			m[str1] = 0;
			continue;
		}
		bool avail = true;			//자기자신이 펠린드롬인지 확인
		for (int i = 0; i < str1.size() / 2; i++) {
			if (str1[i] != str1[str1.size() - 1 - i]) {
				avail = false;
				break;
			}
		}
		if (avail) {		//팰린드롬인 경우
			ansm = str1;
			m[str1] = 0;
		}
		else			//팰린드롬이 아닌 경우
			m[str1] = 1;
	}
	cout << ansl.size() + ansm.size()+ ansr.size() << '\n' << ansl + ansm+ ansr << '\n';
	return 0;
}