#include <iostream>
#include <string>
#include <vector>
using namespace std;
int result;
vector<int> v;
int pi[1000001];
string pattern, origin;

void getPi(string str) {
	int len = str.size();
	for (int i = 1, j = 0; i < len; i++) {
		while (j > 0 && str[i] != str[j]) {
			j = pi[j - 1];
		}
		if (str[i] == str[j])
			pi[i] = ++j;
	}
}

void kmp(string org, string ptn) {
	getPi(pattern);
	for (int i = 0, j = 0; i < org.size(); i++) {
		while (j > 0 && org[i] != ptn[j]) {
			j = pi[j - 1];
		}
		if (org[i] == ptn[j]) {
			if (j == ptn.size() - 1) {
				result++;
				v.push_back(i - j + 1);
				j = pi[j];
			}
			else {
				j++;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	getline(cin, origin);
	getline(cin, pattern);
	kmp(origin, pattern);
	cout << result << '\n';
	for (int i : v)
		cout << i << '\n';
	return 0;
}