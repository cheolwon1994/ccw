#define MAX 500000000
#include <iostream>
#include <queue>
#include <vector>
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
int node, edge, s, e, val;
vector<info> v[801];
bool visit[3][801];
int dist[3][801];
vector<int> start;

void dijkstra() {
	for (int k = 0; k < 3; k++) {
		for (int i = 0; i <= node; i++) {
			visit[k][i] = false;
			dist[k][i] = MAX;
		}
	}
	for (int k = 0; k < 3; k++) {
		priority_queue<info, vector<info>, cmp> pq;
		dist[k][start[k]] = 0;
		tmp.idx = start[k];
		tmp.val = 0;
		pq.push(tmp);
		while (!pq.empty()) {
			int cidx = pq.top().idx;
			int cv = pq.top().val;
			pq.pop();
			if (visit[k][cidx]) continue;
			visit[k][cidx] = true;
			for (int i = 0; i < v[cidx].size(); i++) {
				int next = v[cidx][i].idx;
				int nv = v[cidx][i].val;
				if (dist[k][next] > cv + nv) {
					dist[k][next] = cv + nv;
					tmp.idx = next;
					tmp.val = cv + nv;
					pq.push(tmp);
				}
			}
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> node >> edge;
	for (int i = 0; i < edge; i++) {
		cin >> s >> e >> val;
		tmp.idx = e;
		tmp.val = val;
		v[s].push_back(tmp);
		tmp.idx = s;
		v[e].push_back(tmp);
	}
	int idx1,idx2;
	cin >> idx1 >> idx2;
	start.push_back(1);
	start.push_back(idx1);
	start.push_back(idx2);
	dijkstra();
	int result = min(dist[0][start[1]] + dist[1][start[2]] + dist[2][node],
		dist[0][start[2]] + dist[2][start[1]] + dist[1][node]);
	if (result >= MAX) result = -1;
	cout << result;
	system("pause");
	return 0;
}