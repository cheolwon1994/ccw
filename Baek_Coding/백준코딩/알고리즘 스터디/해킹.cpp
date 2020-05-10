#define MAX 987654321
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
struct info {
	int idx, val;
};
info tmp;
struct cmp {
	bool operator()(info &a, info &b) {
		return a.val > b.val;
	}
};
vector<info> v[10001];
int dist[10001], node, edge, start, s, e, val, test, cnt, result;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> test;
	for (int t = 0; t < test; t++) {
		cin >> node >> edge >> start;
		for (int i = 1; i <= node; i++) {
			v[i].clear();
			dist[i] = MAX;
		}
		for (int i = 0; i < edge; i++) {
			cin >> e >> s >> val;
			tmp.idx = e;
			tmp.val = val;
			v[s].push_back(tmp);
		}
		dist[start] = 0;
		result = -1;
		cnt = 0;
		priority_queue<info, vector<info>, cmp> pq;
		tmp.idx = start;
		tmp.val = 0;
		pq.push(tmp);
		while (!pq.empty()) {
			int cidx = pq.top().idx;
			int cv = pq.top().val;
			pq.pop();
			if (dist[cidx] < cv) continue;
			for (int i = 0; i < v[cidx].size(); i++) {
				int next = v[cidx][i].idx;
				int nv = v[cidx][i].val;
				if (dist[next] > cv + nv) {
					dist[next] = cv + nv;
					tmp.idx = next;
					tmp.val = cv + nv;
					pq.push(tmp);
				}
			}
		}
		for (int i = 1; i <= node; i++) {
			if (dist[i] != MAX) {
				cnt++;
				result = max(result, dist[i]);
			}
		}
		cout << cnt << " " << result << '\n';
	}
	system("pause");
	return 0;
}