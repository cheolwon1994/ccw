#include <iostream>
#include <string>
using namespace std;
int num;
bool finish = false;

void start(string str, int cnt) {
	if (finish) return;
	if (cnt == num) {
		cout << str;
		finish = true;
		return;
	}
	if (cnt == 0) {
		start(str + "1", cnt + 1);
		start(str + "2", cnt + 1);
		start(str + "3", cnt + 1);
	}
	for (int k = 1; k < 4; k++) {
		int len = cnt / 2;
		string ss;
		if (k == 1) ss = "1";
		else if (k == 2) ss = "2";
		else if (k == 3) ss = "3";
		if (cnt % 2 == 1) len += 1;
		bool avail = true;
		for (int i = 0; i <len; i++) {
			string s1 = "", s2 = "";
			for (int j = cnt-1-(2*i); j <cnt-i; j++) 
				s1 += str[j];			
			for (int j = cnt-i; j < cnt; j++) 
				s2 += str[j];
			s2 += ss;
			if (s1 == s2) {
				avail = false;
				break;
			}
		}
		if (avail) {
			start(str + ss, cnt + 1);
		}
	}
}

int main() {
	cin >> num;
	start("", 0);
	system("pause");
	return 0;
}