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
vector<info> v[1001];		//정방향 그래프
vector<info> rev[1001];		//역방향 그래프
vector<int> route;			//경로 지정
bool visit[1001] = { false, };
int dist[1001];
int node, edge, s, e, val, start, dest, result;
bool finish = false;

void dijkstra() {
	for (int i = 1; i <= node; i++)
		dist[i] = MAX;
	priority_queue<info, vector<info>, cmp> pq;
	dist[start] = 0;
	tmp.idx = start;
	tmp.val = 0;
	pq.push(tmp);
	while (!pq.empty()) {
		int cidx = pq.top().idx;
		int cv = pq.top().val;
		pq.pop();
		if (cidx == dest) {
			result = cv;
			break;
		}
		if (visit[cidx]) continue;
		visit[cidx] = true;
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
}

void dfs(int idx) {
	if (finish) return;
	if (idx == start) {
		finish = true;
		return;
	}
	for (int i = 0; i < rev[idx].size(); i++) {
		int next = rev[idx][i].idx;
		int nv = rev[idx][i].val;
		if (visit[next] && dist[next]+nv==dist[idx]) {
			route.push_back(next);
			dfs(next);
			if (finish) break;
			route.pop_back();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> node >> edge;
	for (int i = 0; i < edge; i++) {
		cin >> s >> e >> val;
		tmp.idx = e;
		tmp.val = val;
		v[s].push_back(tmp);
		tmp.idx = s;
		rev[e].push_back(tmp);
	}
	cin >> start >> dest;
	dijkstra();

	//경로 찾기
	route.push_back(dest);
	dfs(dest);
	cout << result << '\n';
	cout << route.size() << '\n';
	for (int i = route.size() - 1; i >= 0; i--)
		cout << route[i] << " ";
	system("pause");
	return 0;
}