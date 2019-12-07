#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int alpha[26];
int main() {
	string str;
	while (!cin.eof()) {
		getline(cin, str);
		for (int i = 0; i < str.size(); i++) {
			if (str[i] != ' ') {
				alpha[str[i] - 'a']++;
			}
		}
	}
	int maxi = 0;
	for (int i = 0; i < 26; i++) 
		maxi = max(maxi, alpha[i]);
	for (int i = 0; i < 26; i++)
		if (alpha[i] == maxi) {
			char c = i + 'a';
			cout << c;
		}
	system("pause");
	return 0;
}