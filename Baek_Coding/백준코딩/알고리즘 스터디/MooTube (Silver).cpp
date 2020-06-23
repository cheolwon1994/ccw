#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct info {
	int idx, val;
};
info tmp;
vector<info> v[5001];
bool visit[5001];
int node, query, from, to, val, usado, start, result;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> node >> query;
	for (int i = 0; i < node-1; i++) {
		cin >> from >> to >> val;
		tmp.idx = to;
		tmp.val = val;
		v[from].push_back(tmp);
		tmp.idx = from;
		v[to].push_back(tmp);
	}
	for (int i = 0; i < query; i++) {
		cin >> usado >> start;
		//√ ±‚»≠
		for (int j = 1; j <= node; j++)
			visit[j] = false;
		result = 0;
		visit[start] = true;
		queue<int> q;
		q.push(start);
		while (!q.empty()) {
			int cidx = q.front();
			q.pop();
			for (int j = 0; j < v[cidx].size(); j++) {
				int next = v[cidx][j].idx;
				if (visit[next]) continue;
				int nv = v[cidx][j].val;
				if (nv >= usado) {
					visit[next] = true;
					result++;
					q.push(next);
				}
			}
		}
		cout << result << '\n';
	}
	return 0;
}