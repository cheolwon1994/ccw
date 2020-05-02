#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int cnt = 0;
struct info {
	long long x, y, z;
	int num;		//몇번 째 행성인지
};
bool cmp(info &a, info &b) {
	if (cnt == 0)	return a.x > b.x;
	else if (cnt == 1) return a.y > b.y;
	else if (cnt == 2) return a.z > b.z;
}
struct info2 {
	long long val;
	int from, to;
};
struct cmp2 {
	bool operator()(info2 &a, info2 &b) {
		return a.val > b.val;
	}
};
info tmp;
info2 tmp2;
info planet[100001];
int par[100001];

int find_parent(int x) {
	if (par[x] == x) return x;
	else
		return par[x] = find_parent(par[x]);
}

void make_union(int x, int y) {
	x = find_parent(x);
	y = find_parent(y);
	if (x < y) par[y] = x;
	else if (x > y) par[x] = y;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int node;
	long long result = 0;
	cin >> node;
	for (int i = 0; i < node; i++) {
		cin >> planet[i].x >> planet[i].y >> planet[i].z;
		planet[i].num = i;
	}
	priority_queue<info2, vector<info2>, cmp2> pq;
	for (int i = 0; i < 3; i++) {
		sort(planet, planet + node, cmp);
		cnt++;
		for (int j = 0; j < node - 1; j++) {
			long long val;			
			if (i == 0)			val = abs(planet[j].x - planet[j + 1].x);
			else if (i == 1)	val = abs(planet[j].y - planet[j + 1].y);
			else if (i == 2)	val = abs(planet[j].z - planet[j + 1].z);
			tmp2.val = val;
			tmp2.from= planet[j].num;
			tmp2.to = planet[j + 1].num;
			pq.push(tmp2);
		}
	}
	for (int i = 0; i < node; i++) 
		par[i] = i;
	
	while (!pq.empty()) {
		int from = pq.top().from;
		int to = pq.top().to;
		long long val = pq.top().val;
		pq.pop();
		int p1 = find_parent(from);
		int p2 = find_parent(to);
		if (p1 == p2) continue;
		make_union(from, to);
		result += val;
	}
	cout << result;
	system("pause");
	return 0;
}