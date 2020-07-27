#define MAX 987654321
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct info {
	int idx, val;
};
struct cmp {
	bool operator()(info& a, info& b) {
		return a.val > b.val;
	}
};
info tmp;
int node, edge, p, s, e, val,result[2],dist[5001];
vector<info> v[5001];

int dijkstra(int start, int dest) {
	int d = 0;
	for (int i = 1; i <= node; i++)
		dist[i] = MAX;
	dist[start] = 0;
	priority_queue<info, vector<info>, cmp> pq;
	tmp.idx = start;
	tmp.val = 0;
	pq.push(tmp);

	while (!pq.empty()) {
		int cidx = pq.top().idx;
		int cv = pq.top().val;
		pq.pop();
		if (cidx == dest) {
			d = cv;
			break;
		}
		for (int i = 0; i < v[cidx].size(); i++) {
			int next = v[cidx][i].idx;
			int nv = v[cidx][i].val;
			if (dist[next] > dist[cidx] + nv) {
				dist[next] = dist[cidx] + nv;
				tmp.idx = next;
				tmp.val = dist[cidx] + nv;
				pq.push(tmp);
			}
		}
	}
	return d;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> node >> edge >> p;
	for (int i = 0; i < edge; i++) {
		cin >> s >> e >> val;
		tmp.val = val;
		tmp.idx = s;
		v[e].push_back(tmp);
		tmp.idx = e;
		v[s].push_back(tmp);
	}
	result[0] = dijkstra(1, node);
	result[1] = dijkstra(1, p) + dijkstra(p, node);
	cout << (result[0] == result[1] ? "SAVE HIM" : "GOOD BYE");
	return 0;
}