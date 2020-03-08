#define MAX 987654321
#include <iostream>
#include <queue>
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
vector<info> v[20001];
int dist[20001];
bool visit[20001] = { false, };
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int node, edge, start,s,e,val;
	cin >> node >> edge >> start;
	for (int i = 0; i < edge; i++) {
		cin >> s >> e >> val;
		tmp.idx = e;
		tmp.val = val;
		v[s].push_back(tmp);
	}
	for (int i = 1; i <= node; i++)
		dist[i] = MAX;
	dist[start] = 0;
	priority_queue<info,vector<info>,cmp> pq;
	tmp.idx = start;
	tmp.val = 0;
	pq.push(tmp);
	while (!pq.empty()) {
		int cidx = pq.top().idx;
		int cv = pq.top().val;
		pq.pop();
		if (visit[cidx]) continue;
		visit[cidx] = true;
		for (int i = 0; i < v[cidx].size(); i++) {		
			int next = v[cidx][i].idx;
			int nv = v[cidx][i].val;
			if (visit[next]) continue;
			if (dist[next] > dist[cidx] + nv) {
				dist[next] = dist[cidx] + nv;
				tmp.idx = next;
				tmp.val = dist[next];
				pq.push(tmp);
			}
		}
	}
	for (int i = 1; i <= node; i++) {
		if (dist[i] == MAX) cout << "INF" << '\n';
		else cout << dist[i] << '\n';
	}
	system("pause");
	return 0;
}