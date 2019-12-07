#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int num, m, s;
int room[1000000];
long long result = 0;
void cal(int idx) {
	if (idx == num)
		return;
	int max = room[idx];
	if (max <= m) {
		result += 1;
		cal(idx + 1);
	}
	else {
		max -= m;
		result += 1;
		if (max%s == 0) {
			result += max / s;
		}
		else
			result += (max / s) + 1;
		cal(idx + 1);
	}
}

int main() {
	cin >> num;
	for (int i = 0; i < num; i++) 
		cin >> room[i];
	cin >> m >> s;
	cal(0);
	cout << result;
	system("pause");
	return 0;
}