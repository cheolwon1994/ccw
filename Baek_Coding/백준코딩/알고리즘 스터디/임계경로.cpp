#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct info {
	int idx, val, cnt;
};
struct cmp {
	bool operator()(info &a, info &b) {
		return a.val < b.val;
	}
};
info tmp;
vector<info> v[10001];		//정방향 도로
vector<info> rev[10001];	//역방향 도로
long long dist[10001];
bool visit[10001] = { false, };

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int node, edge, s, e, val, result = 0, start, target;
	cin >> node >> edge;
	for (int i = 0; i < edge; i++) {
		cin >> s >> e >> val;
		tmp.idx = e;
		tmp.val = val;
		v[s].push_back(tmp);
		tmp.idx = s;
		rev[e].push_back(tmp);
	}
	for (int i = 1; i <= node; i++)
		dist[i] = -1;
	cin >> start >> target;
	priority_queue<info,vector<info>,cmp> pq;
	tmp.idx = start;
	tmp.val = 0;
	dist[start] = 0;
	pq.push(tmp);
	//최장거리 다익스트라
	while (!pq.empty()) {
		int cidx = pq.top().idx;
		int cv = pq.top().val;
		pq.pop();
		if (dist[cidx] > cv) continue;
		/*if (visit[cidx]) continue;
		visit[cidx] = true;*/
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
	//역방향도로 시작
	for (int i = 1; i <= node; i++) {
		cout << dist[i] << " ";
		visit[i] = false;
	}
	system("pause");
	queue<int> q;
	q.push(target);
	visit[target] = true;
	while (!q.empty()) {
		int cidx = q.front();
		q.pop();	
		for (int i = 0; i < rev[cidx].size(); i++) {
			int next = rev[cidx][i].idx;
			int nv = rev[cidx][i].val;
			if (dist[next] + nv == dist[cidx]) {
				result++;
				if (!visit[next]) {
					q.push(next);
					visit[next] = true;
				}
			}
		}
	}
	cout << dist[target] << '\n' << result;
	system("pause");
	return 0;
}