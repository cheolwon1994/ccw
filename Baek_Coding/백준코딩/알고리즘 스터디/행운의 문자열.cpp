#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<char> v;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++)
		v.push_back(str[i]);
	sort(v.begin(), v.end());
	int result = 0;
	do {
		bool avail = true;
		for (int i = 0; i < v.size() - 1; i++) {
			if (v[i] == v[i + 1]) {
				avail = false;
				break;
			}
		}
		if (avail)
			result++;
	} while (next_permutation(v.begin(), v.end()));
	cout << result;
	return 0;
}