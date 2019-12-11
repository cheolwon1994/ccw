#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;
char arr[1000][1000];
int y[1000];
int x[1000];
int test, num;
int main() {
	cin >> test;
	string str;
	int result;
	for (int t = 1; t <= test; t++) {
		cin >> num;
		result = 0;
		for (int i = 0; i < num; i++) {
			memset(y, 0, sizeof(y));
			memset(x, 0, sizeof(x));
		}
		for (int i = 0; i < num; i++) {
			cin >> str;
			for (int j = 0; j < num; j++) {
				arr[i][j] = str[j];
				if (arr[i][j] == 'B') {
					x[j] += 1;
					y[i] += 1;
				}
			}
		}
		for (int i = 0; i < num; i++) {
			for (int j = 0; j < num; j++) {
				if ((y[i] + x[j]) % 2 != 0 && arr[i][j] == 'W')
					result++;
				else if ((y[i] + x[j]) % 2 == 0 && arr[i][j] == 'B')
					result++;
			}
		}
		cout << "#" << t << " " << result << endl;
	}
	system("pause");
	return 0;
}