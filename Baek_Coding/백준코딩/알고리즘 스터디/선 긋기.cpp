#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct info {
	int s, e;
};
struct cmp {
	bool operator()(info &a, info &b) {
		if (a.s == b.s)
			return a.e > b.e;
		return a.s > b.s;
	}
};
info tmp;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, a, b;
	cin >> n;
	priority_queue<info, vector<info>, cmp> pq;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		tmp.s = min(a, b);
		tmp.e = max(a, b);
		pq.push(tmp);
	}
	int len = 0;
	int mini = -1000000001;
	int l = mini, r = mini;
	while (!pq.empty()) {
		int cs = pq.top().s;
		int ce = pq.top().e;
		pq.pop();
		if (l == mini) {
			l = cs;
			r = ce;
			continue;
		}
		if (cs > r) {		//안겹칠 때
			len += (r - l);
			r = ce;
			l = cs;
		}
		else
			r = max(r, ce);
	}
	cout << len + (r - l);
	return 0;
}