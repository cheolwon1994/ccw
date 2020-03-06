#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

struct info {
	int gold, silver, bronze;
};
info tmp;
struct cmp{
	bool operator()(info &a, info &b) {
		if (a.gold == b.gold) {
			if (a.silver == b.silver) 
				return a.bronze < b.bronze;			
			return a.silver < b.silver;
		}
		return a.gold < b.gold;
	}
};
int main() {
	int country, idx, g, s, b, tidx, tg, ts, tb;
	cin >> country >> tidx;
	priority_queue<info, vector<info>, cmp> pq;
	for (int i = 0; i < country; i++) {
		cin >> idx >> g >> s >> b;
		if (idx == tidx) { tg = g; ts = s; tb = b; }
		tmp.bronze = b;
		tmp.silver = s;
		tmp.gold = g;
		pq.push(tmp);
	}
	int cnt = 1;
	while (!pq.empty()) {
		int cg = pq.top().gold;
		int cs = pq.top().silver;
		int cb = pq.top().bronze;
		pq.pop();
		if (tg == cg && ts == cs && tb == cb) 	break;	
		else	cnt++;
	}
	cout << cnt;
	system("pause");
	return 0;
}