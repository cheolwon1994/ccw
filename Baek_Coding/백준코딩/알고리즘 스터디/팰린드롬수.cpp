#include <string>
#include <iostream>
using namespace std;
string str;

int main() {
	while (1) {
		cin >> str;
		if (str == "0")
			break;
		int len = str.size();
		string result = "yes";
		for (int i = 0; i < len / 2; i++) {
			if (str[i] != str[len - 1 - i]) {
				result = "no";
				break;
			}
		}
		cout << result << endl;
	}
	system("pause");
	return 0;
}