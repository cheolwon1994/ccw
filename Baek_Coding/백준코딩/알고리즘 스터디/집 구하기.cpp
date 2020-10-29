#define MAX 98765432100
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct info {
	int idx;
	long long val;
};
struct cmp {
	bool operator()(info &a, info &b) {
		return a.val > b.val;
	}
};
info tmp;
int node, edge, m, s, maxv[2];
vector<info> v[10001];
long long dist[10001][2];
priority_queue<info, vector<info>, cmp> pq;

void dijkstra(int flag) {
	while (!pq.empty()) {
		int cidx = pq.top().idx;
		long long cv = pq.top().val;
		pq.pop();
		if (dist[cidx][flag] < cv) continue;
		for (int i = 0; i < v[cidx].size(); i++) {
			int next = v[cidx][i].idx;
			long long nv = v[cidx][i].val;
			if (nv + cv < dist[next][flag]) {
				dist[next][flag] = nv + cv;
				tmp.idx = next;
				tmp.val = cv + nv;
				pq.push(tmp);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int node, edge, val, idx;
	long long a, b, result = MAX;
	cin >> node >> edge;
	for (int i = 0; i < edge; i++) {
		cin >> a >> b >> val;
		tmp.val = val;
		tmp.idx = b;
		v[a].push_back(tmp);
		tmp.idx = a;
		v[b].push_back(tmp);
	}	
	for (int i = 1; i <= node; i++) {
		dist[i][0] = MAX;
		dist[i][1] = MAX;
	}

	cin >> m >> maxv[0];
	for (int i = 0; i < m; i++) {
		cin >> idx;
		dist[idx][0] = 0;
		tmp.idx = idx;
		tmp.val = 0;
		pq.push(tmp);
	}
	dijkstra(0);
	cin >> s >> maxv[1];
	for (int i = 0; i < s; i++) {
		cin >> idx;
		dist[idx][1] = 0;
		tmp.idx = idx;
		tmp.val = 0;
		pq.push(tmp);
	}
	dijkstra(1);
	for (int i = 1; i <= node; i++) {
		a = dist[i][0];
		b = dist[i][1];
		if (a != 0 && b != 0 && a<=maxv[0] && b<=maxv[1]) {
			result = min(result, a + b);
		}
	}
	(result == MAX) ? (cout << -1) : (cout << result);
	return 0;
}