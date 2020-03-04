#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str;
	cin >> str;
	vector<int> v;
	int l = 0, r = str.size() - 1;
	while (l < r) {
		while (1) {
			if (str[l] == '(') break;
			else l++;
		}
		while (1) {
			if (str[r] == ')') break;
			else r--;
		}
		if (l >= r) break;
		v.push_back(l + 1);
		v.push_back(r + 1);
		l++; r--;
	}
	sort(v.begin(), v.end());
	if (v.empty()) cout << 0;
	else {
		cout << 1 << '\n';
		cout << v.size() << '\n';
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << " ";
	}
	return 0;
}