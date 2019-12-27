#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int num;
long long nrank, cnt;
vector<long long> v[11];
int main() {
	cin >> num;
	for (int i = 0; i < 10; i++)
		v[1].push_back(i);
	if (num < 10) {
		cout << num;
		system("pause");
		return 0;
	}
	cnt = 9;
	bool found = false;
	for (int i = 2; i <= 10; i++) {
		for (int j = 1; j < 10; j++) {
			for (int k = 0; k < v[i - 1].size(); k++) {
				int q = v[i - 1][k] / pow(10, i - 2);
				if (j > q) {
					v[i].push_back(j * pow(10, i - 1) + v[i - 1][k]);
					cnt++;
				}
				if (cnt == num) {
					found = true;
					nrank = j * pow(10, i - 1) + v[i - 1][k];
					break;
				}
			}
			if (found)
				break;
		}
		if (found)
			break;
	}
	if (found)
		cout << nrank;
	else
		cout << -1;
	system("pause");
	return 0;
}