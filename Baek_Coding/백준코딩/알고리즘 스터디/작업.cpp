#define MAX 987654321
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v[10001];
int result[10001];
int val[10001];
struct info {
	int idx, val;
};
info tmp;
int main() {
	int num, ntime, m, tt;
	cin >> num;
	queue<info> q;
	for (int i = 1; i <= num; i++) {
		cin >> ntime >> m;
		val[i] = ntime;
		if (m == 0) {
			tmp.idx = i;
			tmp.val = ntime;
			q.push(tmp);
			result[i] = ntime;
		}
		for (int j = 0; j < m; j++) {
			cin >> tt;
			v[tt].push_back(i);
		}
	}

	int ans = 0;
	while (!q.empty()) {
		int cidx = q.front().idx;
		int cv = q.front().val;
		q.pop();
		for (int i = 0; i < v[cidx].size(); i++) {
			int next = v[cidx][i];
			if (result[next] < result[cidx] + val[next]) {
				result[next] = result[cidx] + val[next];
				tmp.idx = next;
				tmp.val = result[next];
				q.push(tmp);
			}
		}
	}
	for (int i = 1; i <= num; i++)
		ans = max(ans, result[i]);
	cout << ans;
	system("pause");
	return 0;
}