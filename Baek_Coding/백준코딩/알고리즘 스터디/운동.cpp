#define MAX 987654321
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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

int main() {
	int test, node, edge, start, end, vv;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		cin >> node >> edge;
		vector<info> v[401];
		int dist[401];
		for (int i = 0; i < edge; i++) {
			cin >> start >> end >> vv;
			tmp.idx = end;
			tmp.val = vv;
			v[start].push_back(tmp);
		}
		int result = MAX;
		for (int i = 1; i <= node; i++) {
			for (int j = 1; j <= node; j++)
				dist[j] = MAX;
			priority_queue<info,vector<info>,cmp> pq;
			tmp.idx = i;
			tmp.val = 0;
			pq.push(tmp);
			while (!pq.empty()) {
				int cidx = pq.top().idx;
				int cv = pq.top().val;
				pq.pop();
				if (cv > result) continue;
				for (int j = 0; j < v[cidx].size(); j++) {
					int next = v[cidx][j].idx;
					int nv = v[cidx][j].val;
					if (dist[next] > cv + nv) {
						dist[next] = cv + nv;
						tmp.idx = next;
						tmp.val = cv + nv;
						pq.push(tmp);
					}
				}
			}
			result = min(result, dist[i]);
		}
		cout << "#" << t << " " << result << '\n';
	}
	system("pause");
	return 0;
}