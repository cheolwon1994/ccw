#include <iostream>
#include <vector>
#include <string>
using namespace std;
int len, num, val, cnt = 0;
vector<int> v;

void dfs(int idx, string str) {
	if(idx == len) {
		bool avail = true;
		for (int i = 0; i < v.size(); i++) {
			bool temp = false;
			for (int j = 0; j < str.size(); j++) {
				if (str[j] - '0' == v[i]) {
					temp = true;
					break;
				}
			}
			if (!temp) {
				avail = false;
				break;
			}
		}
		if (avail) 
			cnt++;
		return;
	}
	for (int i = 0; i < 10; i++) {
		char c = i + '0';
		dfs(idx + 1, str + c);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> len >> num;
	for (int i = 0; i < num; i++) {
		cin >> val;
		v.push_back(val);
	}
	dfs(0, "");
	cout << cnt;
	return 0;
}