#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <vector>
using namespace std;
map<char, char> m;

void make_map() {
	m['A'] = 'A';
	m['E'] = '3';
	m['3'] = 'E';
	m['H'] = 'H';
	m['I'] = 'I';
	m['M'] = 'M';
	m['O'] = 'O';
	m['S'] = '2';
	m['2'] = 'S';
	m['T'] = 'T';
	m['U'] = 'U';
	m['V'] = 'V';
	m['W'] = 'W';
	m['X'] = 'X';
	m['Y'] = 'Y';
	m['Z'] = '5';
	m['5'] = 'Z';
	m['b'] = 'd';
	m['d'] = 'b';
	m['i'] = 'i';
	m['l'] = 'l';
	m['m'] = 'm';
	m['n'] = 'n';
	m['o'] = 'o';
	m['p'] = 'q';
	m['q'] = 'p';
	m['r'] = '7';
	m['7'] = 'r';
	m['u'] = 'u';
	m['v'] = 'v';
	m['w'] = 'w';
	m['x'] = 'x';
	m['0'] = '0';
	m['1'] = '1';
	m['8'] = '8';
}

bool isSmallAlpha(char c) {
	if('a' <= c && c <= 'z') return true;
	return false;
}

bool isBigAlpha(char c) {
	if ('A' <= c && c <= 'Z') return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str, sr = "", sl = "";
	cin >> str;
	make_map();
	bool avail = true;
	int len = str.size();
	for (int i = 0; i < (len+1) / 2; i++) {
		char l = str[i];
		char r = str[len - 1 - i];
		vector<char> ll, rr;
		ll.push_back(l);
		if (isSmallAlpha(l))
			ll.push_back(l - 'a' + 'A');
		else if (isBigAlpha(l))
			ll.push_back(l - 'A' + 'a');

		rr.push_back(r);
		if (isSmallAlpha(r))
			rr.push_back(r - 'a' + 'A');
		else if (isBigAlpha(r))
			rr.push_back(r - 'A' + 'a');
		bool matched = false;
		for (int j = 0; j < ll.size(); j++) {
			char c = ll[j];
			if (m.find(c) != m.end()) {
				char cc = m[c];
				for (int k = 0; k < rr.size(); k++) {
					if (cc == rr[k]) {
						matched = true;
						sl += c;
						if (i != len - 1 - i)
							sr = cc + sr;
						break;
					}
				}
			}
			if (matched) break;
		}
		if (!matched) {
			avail = false;
			break;
		}
	}
	avail ? cout << sl + sr : cout << -1;
	return 0;
}