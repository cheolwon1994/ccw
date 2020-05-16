#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct info {
	int start, end, val;
};
struct cmp {
	bool operator()(info &a, info &b) {
		return a.val > b.val;
	}
};
info tmp;
int node, edge, s, e, val;
int par[1001], arr[1001][1001];
bool check[1001] = { false, };
vector<info> v;

int find_parent(int x){
	if (par[x] == x) return x;
	return par[x] = find_parent(par[x]);
}

void make_union(int a, int b) {
	a = find_parent(a);
	b = find_parent(b);
	if (a < b) par[b] = a;
	else if (a > b) par[a] = b;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> node >> edge;
	for (int i = 1; i <= node; i++)
		par[i] = i;
	int cnt = 0;
	for (int i = 0; i < edge; i++) {
		cin >> s >> e;
		if (find_parent(s) != find_parent(e)) {
			make_union(s, e);
			cnt++;
		}
	}
	priority_queue<info, vector<info>, cmp> pq;
	for (int i = 1; i <= node; i++) {
		for (int j = 1; j <= node; j++) {
			cin >> arr[i][j];
			if (i>1 && i < j) {
				tmp.start = i;
				tmp.end = j;
				tmp.val = arr[i][j];
				pq.push(tmp);
			}
		}
	}
	long long result = 0;
	if (cnt == node - 2) {
		cout << result << " " << v.size();
	}
	else {
		while (!pq.empty()) {
			int cs = pq.top().start;
			int ce = pq.top().end;
			int cv = pq.top().val;
			pq.pop();
			int ps = find_parent(cs);
			int pe = find_parent(ce);
			if (ps == pe) continue;
			cnt++;
			make_union(cs, ce);
			result += cv;
			tmp.start = cs;
			tmp.end = ce;
			v.push_back(tmp);
			if (cnt == node - 2) break;
		}
		cout << result << " " << v.size() << '\n';
		for (int i = 0; i < v.size(); i++) {
			cout << v[i].start << " " << v[i].end << '\n';
		}
	}
	system("pause");
	return 0;
}