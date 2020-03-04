#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int test, tt, num;
	cin >> test;
	for (int t = 0; t < test; t++) {
		cin >> num;
		vector<int> brace;
		vector<int> neck;
		for (int i = 0; i < num; i++) {
			cin >> tt;
			neck.push_back(tt);
		}
		for (int i = 0; i < num; i++) {
			cin >> tt;
			brace.push_back(tt);
		}
		sort(neck.begin(), neck.end());
		sort(brace.begin(), brace.end());
		for (int i = 0; i < num; i++)
			cout << neck[i] << " ";
		cout << '\n';
		for (int i = 0; i < num; i++)
			cout << brace[i] << " ";
		cout << '\n';
	}
	return 0;
}