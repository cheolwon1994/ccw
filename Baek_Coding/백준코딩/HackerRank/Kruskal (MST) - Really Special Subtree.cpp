struct info {
	int s, e, val;
};
struct cmp {
	bool operator()(info &a, info &b) {
		if (a.val == b.val)
			return a.s + a.e > b.s + b.e;
		return a.val > b.val;
	}
};
info tmp;
int par[3001];
int find_par(int x) {
	if (par[x] == x) return x;
	return par[x] = find_par(par[x]);
}

void make_union(int a, int b) {
	int pa = find_par(a);
	int pb = find_par(b);
	if (pa < pb) 
		par[pb] = pa;	
	else if (pa > pb) 
		par[pa] = pb;	
}

int kruskals(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight) {
	priority_queue<info, vector<info>, cmp> pq;
	//초기화
	for (int i = 1; i <= g_nodes; i++)
		par[i] = i;
	int result = 0;
	for (int i = 0; i < g_from.size(); i++) {
		tmp.s = g_from[i];
		tmp.e = g_to[i];
		tmp.val = g_weight[i];
		pq.push(tmp);
	}
	int cnt = 0;
	while (!pq.empty()) {
		int cs = pq.top().s;
		int ce = pq.top().e;
		int cv = pq.top().val;
		pq.pop();
		int ps = find_par(cs);
		int pe = find_par(ce);
		if (ps == pe) continue;
		make_union(cs, ce);
		result += cv;
		cnt++;
		if (cnt == g_nodes - 1) break;
	}
	return result;
}