#include <iostream>
#include <queue>
#include <algorithm>
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
int node, edge, s, e, val;
vector<info> v[10001];
bool visited[10001] = { false, };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> node >> edge;
	//프림 끝
	int cnt = 1, result = 0;
	for (int i = 0; i < edge; i++) {
		cin >> s >> e >> val;
		tmp.idx = e;
		tmp.val = val;
		v[s].push_back(tmp);
		tmp.idx = s;
		v[e].push_back(tmp);
	}
	queue<int> q;
	priority_queue<info, vector<info>, cmp> pq;
	visited[1] = true;
	q.push(1);
	while (cnt != node) {
		int cidx = q.front();
		q.pop();
		for (int i = 0; i < v[cidx].size(); i++) {
			int next = v[cidx][i].idx;
			int nv = v[cidx][i].val;
			tmp.idx = next;
			tmp.val = nv;
			pq.push(tmp);
		}
		while (!pq.empty()) {
			cidx = pq.top().idx;
			int nv = pq.top().val;
			pq.pop();
			if (visited[cidx]) continue;		//이미 연결된 Node
			visited[cidx] = true;
			result += nv;
			cnt++;
			q.push(cidx);
			break;
		}
	}
	cout << result;
	//프림 끝
	return 0;
}