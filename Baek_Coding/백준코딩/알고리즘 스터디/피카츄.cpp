#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
	bool avail = true;
	string str, s;
	cin >> str;
	int idx = 0;
	while (idx < str.size()) {
		if (str[idx] == 'p') {
			s = str.substr(idx, 2);
			if ("pi" == s) 
				idx += s.size();
			else{
				avail = false;
				break;
			}
		}
		else if (str[idx] == 'k') {
			s = str.substr(idx, 2);
			if ("ka" == s)
				idx += s.size();
			else {
				avail = false;
				break;
			}
		}
		else if (str[idx] == 'c') {
			s = str.substr(idx, 3);
			if ("chu" == s)
				idx += s.size();
			else {
				avail = false;
				break;
			}
		}
		else {
			avail = false;
			break;
		}
	}
	if (avail) cout << "YES";
	else cout << "NO";
	system("pause");
	return 0;
}