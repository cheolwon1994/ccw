#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int getPi(string ptn) {
	int len = ptn.size();
	vector<int> pi(len, 0);
	int j = 0;
	for (int i = 1; i < len; i++) {
		while (j > 0 && ptn[i] != ptn[j]) {
			j = pi[j - 1];
		}
		if (ptn[i] == ptn[j]) 
			pi[i] = ++j;		
	}
	sort(pi.begin(), pi.end());
	return pi[len - 1];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str;
	int maxi = 0;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		string ptn = str.substr(i, str.size());
		int result = getPi(ptn);
		maxi = max(maxi, result);
	}
	cout << maxi;
	system("pause");
	return 0;
}