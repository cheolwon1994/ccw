#define MAX 987654321
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct info {
	int s, e, val;
};
struct cmp {
	bool operator()(info &a,info &b){
		return a.val < b.val;
	}
};
info tmp;
int node, edge, s, e, val,start,destination;
int par[1001];

int find_par(int x) {
	if (par[x] == x) return x;
	return par[x] = find_par(par[x]);
}

void make_union(int a, int b) {
	a = find_par(a);
	b = find_par(b);
	if (a < b) par[b] = a;
	else if (a > b) par[a] = b;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> node >> edge >> start >> destination;
	priority_queue<info, vector<info>, cmp> pq;
	for (int i = 0; i < edge; i++) {
		cin >> s >> e >> val;
		tmp.val = val;
		tmp.e = e;
		tmp.s = s;
		pq.push(tmp);
	}
	for (int i = 0; i < node; i++)
		par[i] = i;
	int result;
	while (!pq.empty()) {
		int cs = pq.top().s;
		int ce = pq.top().e;
		int cv = pq.top().val;
		pq.pop();
		if (find_par(start) == find_par(destination)) break;
		int ps = find_par(cs);
		int pe = find_par(ce);
		if (ps == pe) continue;
		make_union(cs, ce);
		result = cv;
	}
	cout << result;
	system("pause");
	return 0;
}