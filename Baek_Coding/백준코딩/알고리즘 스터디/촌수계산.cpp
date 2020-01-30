#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
bool arr[101][101];
bool check[101];
int main() {
	int num, relation, t1, t2, f, s, idx;
	cin >> num >> t1 >> t2 >> relation;
	for (int i = 0; i < relation; i++) {
		cin >> f >> s;
		arr[f][s] = true;
		arr[s][f] = true;
	}
	queue<int> q;
	q.push(t1);
	check[t1] = true;
	int cnt = 0;
	bool find = false;
	while (!q.empty()) {
		int len = q.size();
		for (int k = 0; k < len; k++) {
			idx = q.front();
			q.pop();
			if (idx == t2) {
				find = true;
				break;
			}
			for (int i = 1; i <= num; i++) {
				if (arr[idx][i] && !check[i]) {
					check[i] = true;
					q.push(i);
				}
			}
		}
		if (find)
			break;
		cnt++;
	}
	if (find)	cout << cnt;
	else	cout << -1;
	system("pause");
	return 0;
}