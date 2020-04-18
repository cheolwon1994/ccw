#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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
vector<info> v[100001];
bool visit[100001] = { false, };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int node, edge, s, e, val, maxi = 0;
	cin >> node >> edge;
	for (int i = 0; i < edge; i++) {
		cin >> s >> e >> val;
		tmp.val = val;
		tmp.idx = e;
		v[s].push_back(tmp);
		tmp.idx = s;
		v[e].push_back(tmp);
	}
	queue<int> q;
	priority_queue<info, vector<info>, cmp> pq;
	q.push(1);
	long long result = 0;
	while (!q.empty()) {
		int cidx = q.front();
		q.pop();
		visit[cidx] = true;
		for (int i = 0; i < v[cidx].size(); i++) {
			int next = v[cidx][i].idx;
			int nv = v[cidx][i].val;
			if (!visit[next]) {
				tmp.idx = next;
				tmp.val = nv;
				pq.push(tmp);
			}
		}
		while (!pq.empty()) {
			int next = pq.top().idx;
			int nv = pq.top().val;
			pq.pop();
			if (visit[next]) continue;
			visit[next] = true;
			result += nv;
			maxi = max(maxi, nv);
			q.push(next);
			break;
		}
	}
	cout << result - maxi;
	system("pause");
	return 0;
}