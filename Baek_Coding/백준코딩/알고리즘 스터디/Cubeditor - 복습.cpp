#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int getPi(string ptn) {
	int len = ptn.size();
	vector<int> v(len, 0);
	int j = 0;
	for (int i = 1; i < len; i++) {
		while (j > 0 && ptn[i] != ptn[j]) {
			j = v[j - 1];
		}
		if (ptn[i] == ptn[j])
			v[i] = ++j;
	}
	sort(v.begin(), v.end());
	return v[len - 1];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str;
	cin >> str;
	int maxi = 0;
	for (int i = 0; i < str.size(); i++) {
		string ss = str.substr(i, str.size());
		int result = getPi(ss);
		maxi = max(maxi, result);
	}
	cout << maxi;
	return 0;
}