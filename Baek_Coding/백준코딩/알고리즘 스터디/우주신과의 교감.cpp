#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
using namespace std;
struct info {
	int s, e;
	double val;
};
struct cmp {
	bool operator()(info &a, info &b) {
		return a.val > b.val;
	}
};
info tmp;

double x[1001], y[1001];
int node, edge;
int par[1001];
double result = 0;

double cal(int a, int b) {
	double dx = fabs(x[a] - x[b]);
	double dy = fabs(y[a] - y[b]);
	double dist = hypot(dx, dy);
	return dist;
}

int find_parent(int x) {
	if (par[x] == x) return x;
	return par[x] = find_parent(par[x]);
}

void make_union(int a, int b) {
	a = find_parent(a);
	b = find_parent(b);
	if (a > b) par[a] = b;
	else if (a < b) par[b] = a;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int a, b;
	priority_queue<info, vector<info>, cmp> pq;
	cin >> node >> edge;
	for (int i = 1; i <= node; i++)
		par[i] = i;
	for (int i = 1; i <= node; i++) 
		cin >> x[i] >> y[i];	
	for (int i = 0; i < edge; i++) {
		cin >> a >> b;
		make_union(a, b);
	}
	for (int i = 1; i < node; i++) {
		for (int j = i + 1; j <= node; j++) {
			tmp.s = i;
			tmp.e = j;
			tmp.val = cal(i, j);
			pq.push(tmp);
		}
	}
	while (!pq.empty()) {
		int s = pq.top().s;
		int e = pq.top().e;
		double d = pq.top().val;
		pq.pop();
		int ps = find_parent(s);
		int pe = find_parent(e);
		if (ps == pe) continue;
		make_union(s, e);
		result += d;
	}
	cout << fixed;
	cout.precision(2);
	cout <<result;
	system("pause");
	return 0;
}