#include <iostream>
#include <climits>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int N, M, village;
int dist[2][1001];
struct info {
	int target, val;
};
struct cmp {
	bool operator()(info &a, info &b) {
		return a.val > b.val;
	}
};
info tmp;
vector<info> arr[2][1001];

void dijkstra(int start, int dir) {
	priority_queue<info, vector<info>, cmp> pq;
	tmp.target = start;
	tmp.val = 0;
	pq.push(tmp);
	dist[dir][start] = 0;
	while (!pq.empty()) {
		int cost = -pq.top().val;
		int cidx = pq.top().target;
		pq.pop();
		if (dist[dir][cidx] < cost) continue;
		for (int i = 0; i < arr[dir][cidx].size(); i++) {
			int next = arr[dir][cidx][i].target;
			int next_cost = cost + arr[dir][cidx][i].val;
			if (next_cost < dist[dir][next]) {
				dist[dir][next] = next_cost;
				tmp.target = next;
				tmp.val = -dist[dir][next];
				pq.push(tmp);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> village;
	int start, end, val;
	for (int i = 0; i < M; i++) {
		cin >> start >> end >> val;
		tmp.target = end;
		tmp.val = val;
		arr[0][start].push_back(tmp);
		tmp.target = start;
		arr[1][end].push_back(tmp);
	}
	for (int i = 1; i <= N; i++) {
		dist[0][i] = INT_MAX; dist[1][i] = INT_MAX;
	}
	dijkstra(village, 0);
	dijkstra(village, 1);
	int maxi = 0;
	for (int i = 1; i <= N; i++) {
		int tt = dist[0][i] + dist[1][i];
		maxi = max(maxi, tt);
	}
	cout << maxi;
	system("pause");
	return 0;
}