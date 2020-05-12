#define MAX 987654321
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
struct info {
	int idx, start;
	long long val;
};
struct cmp {
	bool operator()(info &a, info &b) {
		return a.val > b.val;
	}
};
info tmp;
int node, edge, s, e, val;
long long dist[201];
int pre[201];
vector<info> v[201];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> node >> edge;
	for (int i = 0; i < edge; i++) {
		cin >> s >> e >> val;
		tmp.idx = e;
		tmp.val = val;
		v[s].push_back(tmp);
		tmp.idx = s;
		v[e].push_back(tmp);
	}
	for (int t = 1; t <= node; t++) {
		for (int i = 1; i <= node; i++) {
			dist[i] = MAX;
			pre[i] = 0;
		}
		dist[t] = 0;
		pre[t] = -1;
		priority_queue<info, vector<info>, cmp> pq;
		tmp.idx = t;
		tmp.val = 0;
		pq.push(tmp);
		while (!pq.empty()) {
			int cidx = pq.top().idx;
			int cv = pq.top().val;
			int cs = pq.top().start;
			pq.pop();
			if (dist[cidx] < cv) continue;
			for (int i = 0; i < v[cidx].size(); i++) {
				int next = v[cidx][i].idx;
				int nv = v[cidx][i].val;
				if (dist[next] > cv + nv) {
					if (cidx == t) {
						tmp.start = next;
						pre[next] = next;
					}
					else {
						tmp.start = cs;
						pre[next] = cs;
					}
					dist[next] = cv + nv;
					tmp.idx = next;
					tmp.val = cv + nv;					
					pq.push(tmp);
				}
			}
		}
		for (int i = 1; i <= node; i++) {
			if (pre[i] == -1) cout << '-' << " ";
			else cout << pre[i] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}