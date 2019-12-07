#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>

using namespace std;
int main() {
	int tot = 0;
	int num;
	cin >> num;
	int tmp;
	for (int i = 0; i < num; i++) {
		scanf("%1d", &tmp);
		tot += tmp;
	}
	cout << tot;
	system("pause");
	return 0;
}