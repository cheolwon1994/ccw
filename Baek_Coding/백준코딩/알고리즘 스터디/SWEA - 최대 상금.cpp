#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
using namespace std;
string str;
int change, idx, maxi, tt, f, s, result;


void dfs(int idx, int cnt) {
	char c;
	int maxi, point;
	if (cnt == change) {
		result = max(result, atoi(str.c_str()));
		return;
	}
	if (idx + 1 == str.size() - 1) {
		bool dup = false;
		int a[10] = { 0, };
		for (int i = 0; i < str.size(); i++)
			a[str[i] - '0']++;
		for(int i=0;i<10;i++)
			if (a[i] > 1) {
				dup = true;
				break;
			}
		if(dup)
			result = max(result, atoi(str.c_str()));
		else {
			if ((change - cnt) % 2 == 1) {
				c = str[str.size() - 1];
				str[str.size() - 1] = str[str.size() - 2];
				str[str.size() - 2] = c;
			}
			result = max(result, atoi(str.c_str()));
		}
		return;
	}
	maxi = 0;
	for (int i = idx + 1; i < str.size(); i++) {
		if (maxi < str[i] - '0') {
			point = i;
			maxi = str[i] - '0';
		}
	}
	if (str[idx] - '0' >= maxi)
		dfs(idx + 1, cnt);
	else {
		for (int i = point; i < str.size(); i++) {
			if (str[i] - '0' == maxi) {
				c = str[idx];
				str[idx] = str[i];
				str[i] = c;
				dfs(idx + 1, cnt + 1);
				str[i] = str[idx];
				str[idx] = c;
			}
		}
	}
}

int main() {
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		cin >> str >> change;
		result = 0;
		dfs(0,0);
		cout << "#" << t << " " << result << endl;
	}
	system("pause");
	return 0;
}