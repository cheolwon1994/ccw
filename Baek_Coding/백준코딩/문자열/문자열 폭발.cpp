#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stack>
using namespace std;
char s[1000001];
char b[37];
string str;
string bomb;

int main() {
	cin >> str >> bomb;
	int num;
	int blen = bomb.size();
	int top = -1;
	int btop = blen - 1;
	int slen = str.size();

	for (int i = 0; i < slen; i++) {
		s[++top]= str[i];
		if (top -(blen - 1) >= 0) {
			if (s[top] == bomb[btop]) {
				int flag = true;
				for (int j = 1; j < blen; j++) {
					if (s[top-j] != bomb[btop-j]) {
						flag = false;
						break;
					}
				}
				if (flag) {		//´Ù ÀÏÄ¡
					top-=blen;
				}
			}
		}
	}
	if (top > -1) 
		for (int j = 0; j <= top; j++)
			cout << s[j];
	else
		cout << "FRULA";
	system("pause");
	return 0;
}