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
int num, val, edge;
int par[30];
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
	char c;
	while (1) {
		cin >> num;
		if (num == 0) break;
		priority_queue<info, vector<info>, cmp> pq;
		long long result = 0;
		for (int i = 1; i <= num; i++)
			par[i] = i;
		for (int i = 1; i < num; i++) {
			cin >> c >> edge;
			for (int j = 0; j < edge; j++) {
				cin >> c >> val;
				tmp.start = i;
				tmp.end = c - 'A' + 1;
				tmp.val = val;
				pq.push(tmp);
			}
		}
		int cnt = 0;
		while (!pq.empty()) {
			int cs = pq.top().start;
			int ce = pq.top().end;
			int cv = pq.top().val;
			pq.pop();
			int ps = find_parent(cs);
			int pe = find_parent(ce);
			if (ps == pe) continue;
			make_union(cs, ce);
			cnt++;
			result += cv;
			if (cnt == num - 1)
				break;
		}
		cout << result << '\n';
	}
	system("pause");
	return 0;
}