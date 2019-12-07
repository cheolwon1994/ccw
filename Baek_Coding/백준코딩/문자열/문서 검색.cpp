#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
string all, tmp;
int main() {
	getline(cin, all);
	getline(cin, tmp);
	int result = 0;
	for (int i = 0; i < all.size(); i++) {
		bool check = true;
		for (int j = 0; j < tmp.size(); j++) {
			if (all[i + j] != tmp[j]) {
				check = false;
				break;
			}
		}
		if (check) {
			result++;
			i += (tmp.size() - 1);
		}
	}
	cout << result << endl;
	system("pause");
	return 0;
}