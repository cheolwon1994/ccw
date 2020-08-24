#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <climits>
using namespace std;
struct info {
	int idx, val;
};
struct cmp {
	bool operator()(info &a, info &b) {
		return a.val > b.val;
	}
};
info tmp;
int node, edge, party, s, e, val;
vector<info> v[1001][2];
int result[1001][2];

void dijkstra(int cnt) {
	priority_queue<info, vector<info>, cmp> pq;
	tmp.idx = party;
	tmp.val = 0;
	pq.push(tmp);
	result[party][cnt] = 0;
	while (!pq.empty()) {
		int cidx = pq.top().idx;
		int cv = pq.top().val;
		pq.pop();
		if (result[cidx][cnt] < cv) continue;
		for (int i = 0; i < v[cidx][cnt].size(); i++) {
			int next = v[cidx][cnt][i].idx;
			int nv = v[cidx][cnt][i].val;
			if (result[next][cnt] > cv + nv) {
				result[next][cnt] = cv + nv;
				tmp.idx = next;
				tmp.val = cv + nv;
				pq.push(tmp);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> node >> edge >> party;
	for (int i = 0; i < edge; i++) {
		cin >> s >> e >> val;		
		tmp.idx = e;
		tmp.val = val;
		v[s][0].push_back(tmp);
		tmp.idx = s;
		v[e][1].push_back(tmp);
	}
	for (int i = 1; i <= node; i++) {
		result[i][0] = INT_MAX;
		result[i][1] = INT_MAX;
	}
	dijkstra(0);
	dijkstra(1);
	int maxi = 0;
	for (int i = 1; i <= node; i++) 
		maxi = max(maxi, result[i][0] + result[i][1]);
	cout << maxi;
	return 0;
}