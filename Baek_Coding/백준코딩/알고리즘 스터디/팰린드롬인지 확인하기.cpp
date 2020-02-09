#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;
	int tt = str.size() / 2;
	int result = 1;
	for (int i = 0; i < tt; i++) {
		if (str[i] != str[str.size() - 1 - i]) {
			result = 0;
			break;
		}
	}
	cout << result;
	system("pause");
	return 0;
}