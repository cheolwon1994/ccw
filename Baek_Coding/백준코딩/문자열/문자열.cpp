#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string str1, str2;
	cin >> str1 >> str2;
	int dif = str2.size() - str1.size();
	int result = 51;
	for (int i = 0; i <= dif; i++) {
		int tmp = 0;
		for (int j = 0; j < str1.size(); j++) {
			if (str1[j] != str2[j + i])
				tmp++;
		}
		result = min(result, tmp);
	}
	cout << result;
	system("pause");
	return 0;
}