#define MAX 987654321
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
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
vector<info> v[20001];
int dist[20001];
bool visit[20001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int node, edge, start, target;
	cin >> node >> edge;
	for (int i = 0; i < edge; i++) {
		cin >> start >> target;
		tmp.idx = start;
		tmp.val = 1;
		v[target].push_back(tmp);
		tmp.idx = target;
		v[start].push_back(tmp);
	}
	for (int i = 1; i <= node; i++)
		dist[i] = MAX;
	dist[1] = 0;
	priority_queue<info, vector<info>, cmp> pq;
	tmp.idx = 1;
	tmp.val = 0;
	pq.push(tmp);
	while (!pq.empty()) {
		int cidx = pq.top().idx;
		int cv = pq.top().val;
		pq.pop();
		if (visit[cidx]) continue;
		visit[cidx] = true;
		for (int i = 0; i < v[cidx].size(); i++) {
			int next = v[cidx][i].idx;
			int nv = v[cidx][i].val;
			if (!visit[next] && dist[next]>dist[cidx]+nv) {
				dist[next] = dist[cidx] + nv;
				tmp.idx = next;
				tmp.val = cv + nv;
				pq.push(tmp);
			}
		}
	}
	int maxi = dist[2], idx = 2, cnt = 1;
	for (int i = 3; i <= node; i++) {
		if (dist[i] > maxi) {
			maxi = dist[i];
			idx = i;
			cnt = 1;
		}
		else if (dist[i] == maxi) cnt++;
	}
	cout << idx << " " << maxi << " " << cnt;
	system("pause");
	return 0;
}