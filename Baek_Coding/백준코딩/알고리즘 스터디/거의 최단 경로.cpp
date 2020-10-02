#define MAX 987654321
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
struct info {
	int idx, val;
	bool used;
};
struct info2 {
	int from, idx;
};
info tmp;
info2 tmp2;
struct cmp {
	bool operator()(info &a, info &b) {
		return a.val > b.val;
	}
};
long long dist[500];
vector<info> v[500];
vector<info2> memo[500];		//최단거리 간선번호 저장
int node, edge, start, s, e, target;
bool visit[500];

void dijkstra(bool second) {
	priority_queue<info, vector<info>, cmp> pq;
	tmp.idx = start;
	tmp.val = 0;
	pq.push(tmp);
	dist[start] = 0;
	while (!pq.empty()) {
		int cidx = pq.top().idx;
		int cv = pq.top().val;
		pq.pop();
		if (cv > dist[cidx]) continue;
		if (cidx == target && second)
			break;
		for (int i = 0; i < v[cidx].size(); i++) {
			if (!v[cidx][i].used) {
				int next = v[cidx][i].idx;
				int nv = v[cidx][i].val;
				if (dist[next] > cv + nv) {		//새로운 최단거리가 갱신될 경우
					dist[next] = cv + nv;
					tmp.idx = next;
					tmp.val = cv + nv;
					pq.push(tmp);

					//기존에 있던 경로 초기화
					memo[next].clear();
					tmp2.from = cidx;
					tmp2.idx = i;
					memo[next].push_back(tmp2);
				}
				else if (dist[next] == cv + nv) {		//같은 거리의 경로일 경우 추가
					tmp2.from = cidx;
					tmp2.idx = i;
					memo[next].push_back(tmp2);
				}
			}
		}
	}
}

void make_disable(int num) {
	queue<int> q;
	for (int i = 0; i < node; i++)
		visit[i] = false;
	visit[num] = true;
	q.push(num);
	while (!q.empty()) {
		int cidx = q.front();
		q.pop();
		if (cidx == start) continue;
		for (int i = 0; i < memo[cidx].size(); i++) {
			int from = memo[cidx][i].from;
			int idx = memo[cidx][i].idx;
			v[from][idx].used = true;
			if (!visit[from]) {
				visit[from] = true;
				q.push(from);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int val;
	while (1) {
		cin >> node >> edge;
		if (node + edge == 0) break;
		cin >> start >> target;
		//초기화
		for (int i = 0; i < node; i++) {
			v[i].clear();
			dist[i] = MAX;
			memo[i].clear();
		}

		for (int i = 0; i < edge; i++) {
			cin >> s >> e >> val;
			tmp.idx = e;
			tmp.val = val;
			tmp.used = false;
			v[s].push_back(tmp);
		}
		dijkstra(false);
		if (dist[target] == MAX) {		//target까지의 거리가 존재하지 않을 경우
			cout << -1 << '\n';
			continue;
		}
		make_disable(target);
		int minDist = dist[target], result = -1;

		for (int i = 0; i < node; i++) {
			dist[i] = MAX;
			memo[i].clear();
		}
		dijkstra(true);
		if (dist[target] != minDist) 		//최단경로가 아닌 경우(거의 최단 or 없는 경로)
			result = dist[target];		
		
		if (result == MAX) 	cout << -1 << '\n';
		else cout << result << '\n';
	}
	return 0;
}
