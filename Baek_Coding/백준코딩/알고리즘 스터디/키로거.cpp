#include <iostream>
#include <string>
#include <list>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int test;
	cin >> test;
	for (int t = 0; t < test; t++) {
		string str;
		cin >> str;
		int idx = 0;
		list<char> li;
		list<char> ::iterator it = li.begin();
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '<') {
				if (it != li.begin()) it--;
			}
			else if (str[i] == '>') {
				if (it != li.end()) it++;
			}
			else if (str[i] == '-') {
				if (it!=li.begin()) {
					li.erase((--it)++);
				}
			}
			else 
				li.insert(it, str[i]);
		}
		for (auto ait = li.begin(); ait != li.end(); ait++)
			cout << *ait;
		cout << endl;
	}
	system("pause");
	return 0;
}