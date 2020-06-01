#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct info {
	int idx, val;
};
info tmp;
vector<info> v[100001];
bool check[100001];
int node, edge, start, dest, s, e, val;

bool cal(int mid) {
	for (int i = 1; i <= node; i++)
		check[i] = false;
	queue<int> q;
	q.push(start);
	check[start] = true;

	while (!q.empty()) {
		int cidx = q.front();
		q.pop();
		if (cidx == dest) return true;
		for (int i = 0; i < v[cidx].size(); i++) {
			int next = v[cidx][i].idx;
			if (check[next]) continue;
			int nv = v[cidx][i].val;
			if (nv >= mid) {
				q.push(next);
				check[next] = true;
			}
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> node >> edge >> start >> dest;
	for (int i = 0; i < edge; i++) {
		cin >> s >> e >> val;
		tmp.idx = e;
		tmp.val = val;
		v[s].push_back(tmp);
		tmp.idx = s;
		v[e].push_back(tmp);
	}
	int l = 0, r = 1000001, m, result = 0;
	while (l <= r) {
		m = l + (r - l) / 2;
		if (cal(m)) {
			result = m;
			l = m + 1;
		}
		else
			r = m - 1;
	}
	cout << result;
	system("pause");
	return 0;
}