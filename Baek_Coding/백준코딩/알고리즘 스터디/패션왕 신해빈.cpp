#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int test;
	string str1, str2;
	cin >> test;
	for (int t = 0; t < test; t++) {
		int num;
		cin >> num;
		map<string, int> m;
		map<string, int> ::iterator it;
		for (int i = 0; i < num; i++) {
			cin >> str1 >> str2;
			it = m.find(str2);
			if (it == m.end())
				m[str2] = 1;
			else
				it->second += 1;
		}
		int result = 1;
		for (it = m.begin(); it != m.end(); it++)
			result *= (it->second + 1);
		cout << result - 1 << '\n';
	}
	system("pause");
	return 0;
}