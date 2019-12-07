#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int alpha[26];
string str;
int result = 0;


int main() {
	
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		for (int i = 0; i < 26; i++)
			alpha[i] = -1;
		cin >> str;
		char c;
		int flag = 0;
		for (int j = 0; j < str.size(); j++) {
			c = str[j];
			if (alpha[c - 'a'] == -1)
				alpha[c - 'a'] = j;
			else if (alpha[c - 'a'] != -1) {
				if (alpha[c - 'a'] == j-1)
					alpha[c - 'a'] =j;
				else {
					flag = 1;
					break;
				}
			}
		}
		if (flag == 0) 
			result++;
	}
	cout << result;
	system("pause");
	return 0;
}