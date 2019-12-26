#define MAX 1000001
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <string>
#include <math.h>
using namespace std;
int bug, target;
bool arr[10];
int result = MAX;

void find(string str) {
	for (int i = 0; i < 10; i++) {
		if (arr[i]) {
			string temp_str = str + to_string(i);
			if (result > abs(target - stoi(temp_str)) + temp_str.size()) 
				result = abs(target - stoi(temp_str)) + temp_str.size();
			if (temp_str.size() < 6)
				find(temp_str);
		}
	}
}

int main() {
	int a, t;
	cin >> target >> a;
	for (int i = 0; i < 10; i++)
		arr[i] = true;
	for (int i = 0; i < a; i++) {
		cin >> t;
		arr[t] = false;
	}
	result = min(result, abs(100 - target));
	if (a < 10) {
		find("");
	}
	cout << result;
	system("pause");
	return 0;
}