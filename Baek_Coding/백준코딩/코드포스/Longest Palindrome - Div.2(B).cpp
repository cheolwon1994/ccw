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
		if (it != m.end() && it->second==1) {		//�Ųٷ��ΰ��� �����Ѵٸ�
			ansl += str1;
			ansr = str2 + ansr;
			it->second = 0;
			m[str1] = 0;
			continue;
		}
		bool avail = true;			//�ڱ��ڽ��� �縰������� Ȯ��
		for (int i = 0; i < str1.size() / 2; i++) {
			if (str1[i] != str1[str1.size() - 1 - i]) {
				avail = false;
				break;
			}
		}
		if (avail) {		//�Ӹ������ ���
			ansm = str1;
			m[str1] = 0;
		}
		else			//�Ӹ������ �ƴ� ���
			m[str1] = 1;
	}
	cout << ansl.size() + ansm.size()+ ansr.size() << '\n' << ansl + ansm+ ansr << '\n';
	return 0;
}