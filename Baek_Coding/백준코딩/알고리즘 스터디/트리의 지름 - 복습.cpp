#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct info {
	int idx, val;
};
info tmp;
vector<info> v[10001];
int dist[10001];
int node, s, e, val, maxi = 0, midx;

void dijkstra(int start) {
	for (int i = 1; i <= node; i++)
		dist[i] = -1;
	queue<info> q;
	tmp.idx = start;
	tmp.val = 0;
	q.push(tmp);
	dist[start] = 0;
	while (!q.empty()) {
		int cidx = q.front().idx;
		int cv = q.front().val;
		q.pop();
		if (cv > maxi) {
			maxi = cv;
			midx = cidx;
		}
		for (int i = 0; i < v[cidx].size(); i++) {
			int next = v[cidx][i].idx;
			if (dist[next] != -1) continue;
			int nv = v[cidx][i].val;
			dist[next] = nv + cv;
			tmp.idx = next;
			tmp.val = nv + cv;
			q.push(tmp);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> node;
	for (int i = 0; i < node - 1; i++) {
		cin >> s >> e >> val;
		tmp.idx = e;
		tmp.val = val;
		v[s].push_back(tmp);
		tmp.idx = s;
		v[e].push_back(tmp);
	}
	dijkstra(1);
	maxi = 0;
	dijkstra(midx);
	cout << maxi;
	system("pause");
	return 0;
}