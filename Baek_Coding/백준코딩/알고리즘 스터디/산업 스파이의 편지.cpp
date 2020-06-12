#define MAX 10000000
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdlib.h>
#include <set>
#include <math.h>
using namespace std;
int num[MAX], len;
bool check[7];
vector<int> v, ans;
set<int> s;
string str;

void cal() {
	for (int i = 2; i < MAX; i++) 
		num[i] = i;
	for (int i = 2; i <= sqrt(MAX); i++) {
		if (num[i] == 0) continue;
		for (int j = i + i; j < MAX; j += i)
			num[j] = 0;
	}
}

void dfs(int idx, int len) {
	if (idx==len) {
		string ss = "";
		for (int i = 0; i < idx; i++)
			ss += (ans[i]+'0');
		int val = stoi(ss);
		if (num[val] != 0)
			s.insert(val);
		return;
	}

	for (int i = 0; i < str.size(); i++) {
		if (check[i]) continue;
		ans.push_back(v[i]);
		check[i] = true;
		dfs(idx + 1, len);
		ans.pop_back();
		check[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cal();
	int test;
	cin >> test;
	for (int t = 0; t < test; t++) {
		v.clear();
		s.clear();
		cin >> str;
		len = str.size();
		for (int j = 0; j < len; j++) {
			check[j] = false;
			int val = str[j] - '0';
			v.push_back(val);
		}
		for (int j = 1; j <= len; j++) {
			ans.clear();
			dfs(0, j);
		}
		cout << s.size() << '\n';
	}
	return 0;
}