#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;
int par[101];

int find_par(int x) {
	if (par[x] == x) return x;
	else
		return par[x] = find_par(par[x]);
}

void make_union(int a, int b) {
	a = find_par(a);
	b = find_par(b);
	if (a < b)
		par[b] = a;
	else if (a > b)
		par[a] = b;
}

struct info {
	int start, end;
	float val;
};

struct cmp {
	bool operator()(info &a, info &b) {
		return a.val > b.val;
	}
};

info tmp;
float a[101], b[101];
int main() {
	int num;
	cin >> num;
	for (int i = 1; i <= num; i++)
		par[i] = i;
	priority_queue<info, vector<info>, cmp> pq;
	for (int i = 1; i <= num; i++) {
		cin >> a[i] >> b[i];
	}
	for (int i = 1; i < num; i++) {
		for (int j = i + 1; j <= num; j++) {
			float val = (a[i] - a[j])*(a[i] - a[j]) + (b[i] - b[j])*(b[i] - b[j]);
			val = sqrt(val);
			val = roundf(val * 100) / 100;
			tmp.start = i;
			tmp.end = j;
			tmp.val = val;
			pq.push(tmp);
		}
	}
	float result = 0;
	while (!pq.empty()) {
		int s = pq.top().start;
		int e = pq.top().end;
		float v = pq.top().val;
		pq.pop();
		if (find_par(s) == find_par(e)) continue;		//이미 연결된 경우
		else {
			make_union(s, e);
			result += v;
		}
	}
	cout << result;
	system("pause");
	return 0;
}