#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
struct info {
	int idx, val;
};
info tmp;
struct cmp {
	bool operator()(info &a, info &b) {
		return a.val > b.val;
	}
};
vector<info> v[1001];
vector<info> ans;
int dist[1001];
bool visit[1001] = { false, };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int node, edge, s1, e, val;
	cin >> node >> edge;
	for (int i = 0; i < edge; i++) {
		cin >> s1 >> e >> val;
		tmp.idx = e;
		tmp.val = val;
		v[s1].push_back(tmp);
		tmp.idx = s1;
		v[e].push_back(tmp);
	}
	priority_queue<info, vector<info>, cmp> pq;
	for (int i = 1; i <= node; i++)
		dist[i] = 1000000;
	tmp.idx = 1;
	tmp.val = 0;
	pq.push(tmp);
	dist[1] = 0;
	//최단 경로 갱신
	while (!pq.empty()) {
		int cidx = pq.top().idx;
		int cv = pq.top().val;
		pq.pop();
		if (dist[cidx] < cv) continue;
		for (int i = 0; i < v[cidx].size(); i++) {
			int next = v[cidx][i].idx;
			int nv = v[cidx][i].val;
			if (dist[next] > cv + nv) {
				dist[next] = cv + nv;
				tmp.idx = next;
				tmp.val = cv + nv;
				pq.push(tmp);
			}
		}
	}
	//최단 경로 갱신할때 이용한 간선 저장
	queue<int> q;
	q.push(1);
	visit[1] = true;
	set<int> s;
	while (!q.empty()) {
		int cidx = q.front();
		q.pop();
		for (int i = 0; i < v[cidx].size(); i++) {
			int next = v[cidx][i].idx;
			int nv = v[cidx][i].val;
			if (dist[cidx] + nv == dist[next] && !visit[next]) {
				//이미 포함된 간선인지 확인
				int tt = cidx * 1001 + next;
				if (s.find(tt) != s.end()) continue;
				tt = next * 1001 + cidx;
				if (s.find(tt) != s.end()) continue;
				q.push(next);
				s.insert(tt);
				visit[next] = true;
				tmp.idx = cidx;
				tmp.val = next;
				ans.push_back(tmp);
			}
		}
	}
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) 
		cout << ans[i].idx << " " << ans[i].val << '\n';	
	system("pause");
	return 0;
}