#define MAX 987654321
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
vector<info> v[1001];
int dist[1001];
bool visit[1001] = { false, };
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int node, edge, s, e, val, start, dest;
	cin >> node >> edge;
	for (int i = 0; i < edge; i++) {
		cin >> s >> e >> val;
		tmp.idx = e;
		tmp.val = val;
		v[s].push_back(tmp);
	}
	cin >> start >> dest;
	for (int i = 1; i <= node; i++)
		dist[i] = MAX;
	priority_queue<info, vector<info>, cmp> pq;
	tmp.idx = start;
	tmp.val = 0;
	pq.push(tmp);
	long long result;

	while (!pq.empty()) {
		int cidx = pq.top().idx;
		int cv = pq.top().val;
		pq.pop();
		if (cidx == dest) {
			result = cv;
			break;
		}
		if (visit[cidx]) continue;
		visit[cidx] = true;
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
	cout << result;
	system("pause");
	return 0;
}