#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
int num, reach, tmp;
set<int> s;
vector<int> v;
long long dp[100001];
int main() {
	cin >> num >> reach;
	for (int i = 1; i < 100000; i++)
		dp[i] = 100001;
	for (int i = 0; i < num; i++) {
		cin >> tmp;
		s.insert(tmp);
	}
	for (auto it = s.begin(); it != s.end(); it++) {
		dp[*it] = 1;
		v.push_back(*it);
	}
	for (int i = v[0]+1; i < 100001; i++) {
		if (dp[i] != 1) {
			for (int j = 0; j < v.size(); j++) {
				if (v[j] <= i) {
					dp[i] = min(dp[i], 1 + dp[i - v[j]]);
				}
				else
					break;
			}
		}
	}
	if (dp[reach] == 100001)
		cout << -1;
	else
		cout << dp[reach];
	system("pause");
	return 0;
}