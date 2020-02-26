#define MAX -987654321
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
struct info {
	int idx, val;
};
info tmp;
struct cmp {
	bool operator()(info &a, info &b) {
		return a.val < b.val;
	}
};
int profit[100];
vector<info> v[100];
long long dist[100];
int num, start, target, edge;
bool gee[100];
bool visit[100];

void bellman_ford() {
	bool update = true;
	int cnt = 0;
	while (update && cnt != num) {
		update = false;
		for (int i = 0; i < num; i++) {
			for (int j = 0; j < v[i].size(); j++) {
				int next = v[i][j].idx;
				int next_val = v[i][j].val;
				if (dist[i]!=MAX && dist[next] < dist[i] + profit[next] - next_val) {
					dist[next] = dist[i] + profit[next] - next_val;
					update = true;
					if (cnt == num - 1)
						gee[i] = true;
				}
			}
		}
		cnt++;
	}
	bool loop = false;
	queue<int>q;
	for (int i = 0; i < num; i++)
		if (gee[i])
			q.push(i);
	while (!q.empty()) {
		int cidx = q.front();
		q.pop();
		if (visit[cidx]) continue;
		visit[cidx] = true;
		for (int i = 0; i < v[cidx].size(); i++) {
			if (v[cidx][i].idx == target) {
				loop = true;
				break;
			}
			if (!visit[v[cidx][i].idx]) 
				q.push(v[cidx][i].idx);			
		}
		if (loop)
			break;
	}
	if (dist[target] == MAX) cout << "gg";
	else if (loop) cout << "Gee";
	else cout << dist[target];
}

int main() {
	cin >> num >> start >> target >> edge;
	int s, e, val;
	for (int i = 0; i < edge; i++) {
		cin >> s >> e >> val;
		tmp.idx = e;
		tmp.val = val;
		v[s].push_back(tmp);		
	}
	for (int i = 0; i < num; i++)
		cin >> profit[i];
	for (int i = 0; i < num; i++)
		dist[i] = MAX;
	dist[start] = profit[start];

	bellman_ford();
	system("pause");
	return 0;
}