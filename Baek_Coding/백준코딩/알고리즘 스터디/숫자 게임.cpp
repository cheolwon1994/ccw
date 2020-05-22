#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int result;
int check[100000];
int cal(string s, vector<int> v);

void dfs(int sum, int tot, string ss, vector<int> v) {
	if (sum == tot) {
		if (v.size() == 1) return;
		check[stoi(ss)] = max(check[stoi(ss)], cal(ss, v));
		return;
	}
	for (int i = 1; i <= tot - sum; i++) {
		v.push_back(i);
		dfs(sum + i, tot, ss, v);
		v.pop_back();
	}
}

int cal(string s, vector<int> v) {
	int tmp = 1, cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		int len = v[i];
		string ss = s.substr(cnt, len);
		int val = stoi(ss);
		tmp *= val;
		cnt += len;
	}
	if (check[tmp] == -1) {
		string st = to_string(tmp);
		vector<int> vv;
		dfs(0, st.size(), st, vv);
	}
	return check[tmp] + 1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int test;
	cin >> test;
	for (int i = 0; i < 100000; i++)
		check[i] = -1;
	for (int i = 0; i < 10; i++)
		check[i] = 0;
	for (int t = 1; t <= test; t++) {
		result = 0;
		string str;
		cin >> str;
		vector<int> v;
		dfs(0, str.size(), str, v);
		cout << "#" << t << " " << check[stoi(str)] << '\n';
	}
	system("pause");
	return 0;
}