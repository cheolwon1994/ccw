#define MAX 10000000000000
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
struct info {
	long long idx, val;
};
struct cmp {
	bool operator()(info &a, info &b) {
		return a.val > b.val;
	}
};
info tmp;
vector<info> v[100001];
long long dist[100001], maxi = 0, node, edge, k, s, e, val, result;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> node >> edge >> k;
	//√ ±‚»≠
	for (int i = 1; i <= node; i++)
		dist[i] = MAX;
	for (int i = 0; i < edge; i++) {
		cin >> s >> e >> val;
		tmp.idx = s;
		tmp.val = val;
		v[e].push_back(tmp);
	}
	priority_queue<info, vector<info>, cmp> pq;
	for (int i = 0; i < k; i++) {
		cin >> s;
		tmp.idx = s;
		tmp.val = 0;
		pq.push(tmp);
		dist[s] = 0;
	}
	while (!pq.empty()) {
		long long cidx = pq.top().idx;
		long long cv = pq.top().val;
		pq.pop();
		if (dist[cidx] < cv) continue;
		for (int i = 0; i < v[cidx].size(); i++) {
			long long next = v[cidx][i].idx;
			long long nv = v[cidx][i].val;
			if (dist[next] > cv + nv) {
				dist[next] = cv + nv;
				tmp.idx = next;
				tmp.val = cv + nv;
				pq.push(tmp);
			}
		}
	}
	for (int i = 1; i <= node; i++) {
		if (dist[i] > maxi) {
			maxi = dist[i];
			result = i;
		}
	}
	cout << result << '\n' << maxi;
	system("pause");
	return 0;
}