#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, int> m;
map<int, string> m2;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int num, question;
	cin >> num >> question;
	string str;
	for (int i = 0; i < num; i++) {
		cin >> str;
		m.insert(make_pair(str,i+1));
		m2.insert(make_pair(i+1, str));
	}
	for (int i = 0; i < question; i++) {
		cin >> str;
		if ('A' <= str[0] && str[0] <= 'Z')		cout << m.find(str)->second << '\n';
		else 	cout << m2.find(atoi(str.c_str()))->second << '\n';
	}
	system("pause");
	return 0;
}