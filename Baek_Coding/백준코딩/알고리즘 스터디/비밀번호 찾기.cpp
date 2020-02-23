#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int site, question;
	cin >> site >> question;
	string str1, str2;
	map<string, string> m;
	map<string, string> ::iterator it;
	for (int i = 0; i < site; i++) {
		cin >> str1 >> str2;
		m[str1] = str2;
	}
	
	for (int i = 0; i < question; i++) {
		cin >> str1;
		it = m.find(str1);
		cout << it->second << '\n';
	}
	system("pause");
	return 0;
}