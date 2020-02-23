#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int type, tt, result = 0;
	long long tot;
	vector<int> v;
	cin >> type >> tot;
	for (int i = 0; i < type; i++) {
		cin >> tt;
		v.push_back(tt);
	}
	int cnt = type - 1;
	while (tot) {
		result += (tot / v[cnt]);
		tot %= v[cnt];
		cnt--;
	}
	cout << result;
	system("pause");
	return 0;
}