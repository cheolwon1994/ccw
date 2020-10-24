#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str;
	cin >> str;
	int cnt = 0;		//연속된 P의 개수
	bool avail = true;
	for (int i = 0; i < str.size(); i++) {
		char c = str[i];
		if (c == 'P') 
			cnt++;
		else {
			if (cnt < 2 || i == str.size() - 1 || str[i + 1] == 'A') {
				avail = false;
				break;
			}
			else
				cnt -= 2;
		}
	}
	if (cnt != 1) avail = false;
	avail ? (cout << "PPAP") : (cout << "NP");
	return 0;
}