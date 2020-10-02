#include <iostream>
#include <string>
using namespace std;
bool avail;

void brute_force(string ss) {
	if (avail) return;
	if (ss == "") {
		avail = true;
		return;
	}
	for (int i = 0; i < ss.size(); i++) {
		if (i + 1 < ss.size() && ss[i] == ss[i + 1]) {
			int len = 2;
			while (1) {
				if (i + len == ss.size()) break;
				if (ss[i] == ss[i + len])
					len++;
				else break;
			}
			string str1 = ss.substr(0, i);
			string str2 = ss.substr(i + len);
			brute_force(str1 + str2);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int test;
	cin >> test;
	string str;
	while (test) {
		cin >> str;
		avail = false;
		brute_force(str);
		test--;
		if (avail) cout << 1;
		else cout << 0;
		cout << '\n';
	}
	return 0;
}