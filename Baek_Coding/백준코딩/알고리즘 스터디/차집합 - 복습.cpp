#include <iostream>
#include <set>
#include <vector>
using namespace std;

set<int> a, b;
vector<int> v;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, val;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> val;
		a.insert(val);
	}
	for (int i = 0; i < m; i++) {
		cin >> val;
		b.insert(val);
	}
	for (auto it = a.begin(); it != a.end(); it++) 
		if (b.find(*it) == b.end()) {
			v.push_back(*it);
		}
	cout << v.size() << '\n';
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	return 0;
}