#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int num, temp;
char c;
int result = 0;
vector<char> v;
string cmp = "aeiou";
void start(string str, int cnt) {
	if (cnt == num) {
		int m = 0;
		int j = 0;
		for (int i = 0; i < cnt; i++) {
			c = str[i];
			for (int k = 0; k <= 5; k++) {
				if (k == 5) { j++; break; }
				if (c == cmp[k]) { m++; break; }
			}
		}
		if(m>0 && j>1)
			cout << str << endl;
		return;
	}
	for (int i = 0; i < temp; i++) {
		if (cnt == 0) 
			start(str+ v[i], cnt + 1);
		else {
			if (str[cnt - 1] < v[i])
				start(str + v[i], cnt + 1);
		}
	}
}

int main() {
	cin >> num >> temp;
	for (int i = 0; i < temp; i++) {
		cin >> c;
		v.push_back(c);
	}
	sort(v.begin(), v.end());
	start("", 0);
	system("pause");
	return 0;
}