#include <iostream>
#include <algorithm>
using namespace std;
int val[401][401];
int num, test, first, second;
int main() {
	cin >> num >> test;
	for (int i = 0; i < test; i++) {
		cin >> first >> second;
		val[first][second] = -1;
		val[second][first] = 1;
	}
	for (int t = 1; t <= num; t++) {
		for (int i = 1; i <= num; i++) {
			for (int j = 1; j <= num; j++) {
				if (val[i][t] == -1 && val[t][j] == -1) {
					val[i][j] = -1;
					val[j][i] = 1;
				}
			}
		}
	}
	cin >> test;
	for (int i = 0; i < test; i++) {
		cin >> first >> second;
		cout << val[first][second] << endl;
	}
	system("pause");
	return 0;
}