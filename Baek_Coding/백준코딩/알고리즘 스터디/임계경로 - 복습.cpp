#define MAX 987654321
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
struct info {
	int idx, val;
};
struct cmp {
	bool operator()(info &a, info &b) {
		return a.val < b.val;
	}
};
info tmp;
vector<info> v[10001];			//Á¤
vector<info> rev[10001];		//¿ª
int dist[10001];
bool visit[10001] = { false, };
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int node, edge, s, e, val, start, destination;
	cin >> node >> edge;
	for (int i = 0; i < edge; i++) {
		cin >> s >> e >> val;
		tmp.val = val;
		tmp.idx = e;
		v[s].push_back(tmp);
		tmp.idx = s;
		rev[e].push_back(tmp);
	}
	cin >> start >> destination;
	for (int i = 1; i <= node; i++)
		dist[i] = -1;
	dist[start] = 0;
	priority_queue<info, vector<info>, cmp> pq;
	tmp.idx = start;
	tmp.val = 0;
	pq.push(tmp);
	while (!pq.empty()) {
		int cidx = pq.top().idx;
		int cv = pq.top().val;
		pq.pop();
		if (dist[cidx] > cv) continue;
		for (int i = 0; i < v[cidx].size(); i++) {
			int next = v[cidx][i].idx;
			int nv = v[cidx][i].val;
			if (dist[next] < cv + nv) {
				dist[next] = cv + nv;
				tmp.idx = next;
				tmp.val = cv + nv;
				pq.push(tmp);
			}
		}
	}
	queue<int> q;
	int result = 0;
	q.push(destination);
	while (!q.empty()) {
		int cidx = q.front();
		q.pop();
		if (cidx == start) continue;
		for (int i = 0; i < rev[cidx].size(); i++) {
			int next = rev[cidx][i].idx;
			int nv = rev[cidx][i].val;
			if (dist[next] + nv == dist[cidx]) {
				result++;
				if (!visit[next]) {
					visit[next] = true;
					q.push(next);
				}
			}
		}
	}
	cout << dist[destination] << '\n' << result;
	system("pause");
	return 0;
}