#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> v;
bool alpha[26] = { false, };
int n, k, result = 0;

void dfs(int idx, int cnt) {
	if (cnt == k) {
		int val = 0;
		for (int i = 0; i < v.size(); i++) {
			bool avail = true;
			for (int j = 0; j < v[i].size(); j++) {
				char c = v[i][j];
				if (!alpha[c - 'a']) {
					avail = false;
					break;
				}
			}
			if (avail) val++;
		}
		result = max(result, val);
		return;
	}
	for (int i = idx; i < 26; i++) {
		if (!alpha[i]) {
			alpha[i] = true;
			dfs(i + 1, cnt + 1);
			alpha[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str, ss;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> str;
		ss = str.substr(4, str.size() - 8);
		string temp = "";
		for (int i = 0; i < ss.size(); i++) {
			char c = ss[i];
			if (c == 'a' || c == 'n' || c == 't' || c == 'i' || c == 'c') {

			}
			else 
				temp += c;			
		}
		v.push_back(temp);
	}
	if (k >= 5) {
		alpha['a' - 'a'] = true;
		alpha['c' - 'a'] = true;
		alpha['n' - 'a'] = true;
		alpha['i' - 'a'] = true;
		alpha['t' - 'a'] = true;
		k -= 5;
		dfs(1, 0);
	}
	cout << result;
	return 0;
}