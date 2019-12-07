#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
int arr[26];

int main() {
	string str;
	cin >> str;
	int tmp;
	for (int i = 0; i < str.size(); i++) {
		tmp = str[i];
		if (97 <= tmp && tmp <= 122)
			arr[tmp - 'a']++;
		else
			arr[tmp - 'A']++;
	}
	int max = 0;
	int idx = 0;
	int dup = 1;
	for (int i = 0; i < 26; i++) {
		if (max < arr[i]) {
			idx = i;
			max = arr[i];
			dup = 1;
		}
		else if (max == arr[i])
			dup++;
	}
	if (dup > 1)
		cout << "?" << endl;
	else
		printf("%c\n", idx + 'A');
	system("pause");
	return 0;
}