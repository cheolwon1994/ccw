#include <iostream>
#include <string>
using namespace std;
string str,ans;
int result = 0;
void start(int idx, int tot) {
	if (idx > str.size())
		return;
	if (idx == str.size()) {
		result = tot;
		return;
	}
	if (str[idx] == ans[0]) {
		bool avail = true;
		for (int i = 1; i < ans.size(); i++) {
			if (str[idx + i] != ans[i]) {
				avail = false;
				break;
			}
		}
		if (avail)	start(idx + ans.size(), tot + 1);
		else  start(idx + 1, tot);
	}
	else  start(idx + 1, tot);
}

int main() {

	getline(cin, str);
	getline(cin, ans);
	start(0,0);
	cout << result;
	system("pause");
	return 0;
}