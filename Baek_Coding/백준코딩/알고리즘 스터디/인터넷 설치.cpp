#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
struct info {
	int idx, val;
};
struct cmp {
	bool operator()(info &a, info &b) {
		return a.val > b.val;
	}
};
info tmp;
int node, edge, p;
vector<info> v[1001];
int dist[1001];

bool dijkstra(int mid) {
	priority_queue<info, vector<info>, cmp> pq;
	tmp.idx = 1;
	tmp.val = 0;
	pq.push(tmp);
	for (int i = 1; i <= node; i++)
		dist[i] = 987654321;
	dist[1] = 0;
	while (!pq.empty()) {
		int cidx = pq.top().idx;
		int cv = pq.top().val;
		pq.pop();
		if (dist[cidx] < cv) continue;
		for (int i=0; i<v[cidx].size(); i++) {
			int next = v[cidx][i].idx;
			int nv = cv + (v[cidx][i].val > mid);
			if (nv < dist[next]) {
				dist[next] = nv;
				tmp.idx = next;
				tmp.val = nv;
				pq.push(tmp);
			}
		}
	}
	return dist[node] <= p;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int l = 0, r, mid, a, b, val, result = -1;
	cin >> node >> edge >> p;
	for (int i = 0; i < edge; i++) {
		cin >> a >> b >> val;
		tmp.val = val;
		tmp.idx = b;
		v[a].push_back(tmp);
		tmp.idx = a;
		v[b].push_back(tmp);
		r = max(r, val);
	}
	while (l <= r) {
		mid = l + (r - l) / 2;
		if (dijkstra(mid)) {
			r = mid - 1;
			result = mid;
		}
		else
			l = mid + 1;
	}
	cout << result;
	return 0;
}