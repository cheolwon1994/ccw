#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

struct info {
	int from, to, val;
};
struct cmp {
	bool operator()(info &a, info &b) {
		return a.val > b.val;
	}
};
info tmp;
int node, edge, s, e, val;
int par[10001];

int find_par(int x) {
	if (par[x] == x) return x;
	return par[x] = find_par(par[x]);
}

void make_union(int a, int b) {
	int pa = find_par(a);
	int pb = find_par(b);
	if (pa > pb) par[pa] = pb;
	else if (pa < pb) par[pb] = pa;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> node >> edge;
	//크루스칼 시작
	int cnt = 0, result = 0;
	priority_queue<info, vector<info>, cmp> pq;
	for (int i = 1; i <= node; i++)
		par[i] = i;
	for (int i = 0; i < edge; i++) {
		cin >> s >> e >> val;
		tmp.from = s;
		tmp.to = e;
		tmp.val = val;
		pq.push(tmp);
	}
	while (!pq.empty()) {
		int cf = pq.top().from;
		int ce = pq.top().to;
		int cv = pq.top().val;
		pq.pop();
		int pcf = find_par(cf);
		int pcd = find_par(ce);
		if (pcf == pcd) continue;
		make_union(cf, ce);
		cnt++;
		result += cv;
		if (cnt == node - 1) break;
	}
	cout << result;
	//크루스칼 끝
	return 0;
}