#include <iostream>
#include <string>
using namespace std;

int main() {
	string str, ptn;
	getline(cin, str);
	getline(cin, ptn);
	int cnt = 0;
	for (int i = 0; i <= str.size(); i++) {
		if (i + ptn.size() > str.size()) break;
		if (str[i] == ptn[0]) {
			bool avail = true;
			for (int j = 1; j < ptn.size(); j++) {
				if (ptn[j] != str[i + j]) {
					avail = false;
					break;
				}
			}
			if (avail) {
				cnt++;
				i += (ptn.size() - 1);
			}
		}
	}
	cout << cnt;
	system("pause");
	return 0;
}