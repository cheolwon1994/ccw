#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int arr[20][20];

int main() {
	int num;
	cin >> num;
	for (int i = 0; i < num; i++)
		for (int j = 0; j < num; j++)
			cin >> arr[i][j];
	vector<int> vv;
	for (int i = 0; i < num / 2; i++)
		vv.push_back(0);
	for (int i = 0; i < num / 2; i++)
		vv.push_back(1);
	vector<int> a, b;
	int result = 987654321;
	do {
		a.clear();
		b.clear();
		for (int i = 0; i < vv.size(); i++) {
			if (vv[i] == 0) a.push_back(i);
			else b.push_back(i);
		}
		int a_sum = 0, b_sum = 0;
		for (int i = 0; i < a.size(); i++) {
			for (int j = 0; j < a.size(); j++) {
				if (i == j) continue;
				a_sum += arr[a[i]][a[j]];
			}
		}
		for (int i = 0; i < b.size(); i++) {
			for (int j = 0; j < b.size(); j++) {
				if (i == j) continue;
				b_sum += arr[b[i]][b[j]];
			}
		}
		result = min(result, abs(a_sum - b_sum));
	} while (next_permutation(vv.begin(), vv.end()));
	cout << result;
	system("pause");
	return 0;
}