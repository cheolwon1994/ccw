#include <iostream>
#include <string>
using namespace std;

int main() {
	int num, result = 0;
	string str;
	cin >> num >> str;
	for (int i = 0; i < num; i++) {
		if (str[i] == 'S') result++;
		else if (str[i] == 'L') { result++, i++; }
	}
	result += 1;
	if (result >= num) result = num;
	cout << result;
	system("pause");
	return 0;
}