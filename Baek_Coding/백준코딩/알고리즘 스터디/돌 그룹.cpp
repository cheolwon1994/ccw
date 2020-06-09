#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
set<long long> s;
bool avail = false;

void dfs(vector<int> v) {
	if (avail) return;
	if (v[0] == v[1] && v[1] == v[2]) {
		avail = true;
		return;
	}
	sort(v.begin(), v.end());
	long long temp = (long long)(v[2] * 1501) + v[0];
	if (s.find(temp) != s.end()) return;
	s.insert(temp);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == j) continue;
			if (v[i] > v[j]) {
				int tt = v[j];
				v[j] += tt;
				v[i] -= tt;
				dfs(v);
			}
		}
	}
}

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if ((a + b + c) % 3 != 0) cout << 0;
	else {
		vector<int> v;
		v.push_back(a);
		v.push_back(b);
		v.push_back(c);
		dfs(v);
		cout << avail ? 1 : 0;
	}
	return 0;
}