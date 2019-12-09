#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <string.h>

using namespace std;
vector<int> v[10001];
int check[10001];
int point, edge;
int result = 0;
deque<int> dq;
vector<int> ans;

int main() {
	cin >> point >> edge;
	int first, second;
	for (int i = 0; i < edge; i++) {
		cin >> second >> first;
		v[first].push_back(second);
	}
	int len, tmp, test;
	for (int i = 1; i <= point; i++) {
		dq.push_back(i);
		memset(check, 0, sizeof(check));
		check[i] = 1;
		test = 0;
		while (!dq.empty()) {
			len = dq.size();
			test += len;
			for (int j = 0; j < len; j++) {
				tmp = dq[j];
				for (int k = 0; k < v[tmp].size(); k++) {
					if (check[v[tmp][k]] != 1) {
						check[v[tmp][k]] = 1;
						dq.push_back(v[tmp][k]);
					}
				}
			}
			for(int j=0;j<len;j++)
				dq.pop_front();
		}
		if (result < test) {
			ans.clear();
			ans.push_back(i);
			result = test;
		}
		else if (result == test) 
			ans.push_back(i);
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	system("pause");
	return 0;
}