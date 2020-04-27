#define MAX 987654321
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
struct info {
	int s, e, val;
};
struct info2 {
	char order;
	int num;
};
info tmp;
info2 tmp2;
int n, m, q, st, en;
int dist[1001];
vector<info> edge[100001];
vector<info2> query[200001];
vector<int> ans;
vector<int> v[1001];

void dijkstra(int ii) {
	queue<int> q;
	q.push(ii);
	while (!q.empty()) {
		int cidx = q.front();
		q.pop();
		for (int i = 0; i < v[cidx].size(); i++) {
			if (dist[v[cidx][i]] > dist[cidx] + 1) {
				dist[v[cidx][i]] = dist[cidx] + 1;
				q.push(v[cidx][i]);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> q;
	for (int i = 1; i <= m; i++) {
		cin >> st >> en;
		tmp.s = st;
		tmp.e = en;
		tmp.val = 1;
		edge[i].push_back(tmp);
	}
	for (int i = 1; i <= q; i++) {
		char c;
		int a;
		cin >> c >> a;
		tmp2.num = a;
		tmp2.order = c;
		query[i].push_back(tmp2);
		if (c == 'U')
			edge[a][0].val = 0;
	}
	for (int i = 1; i <= m; i++) {
		if (edge[i][0].val == 0) continue;
		int start = edge[i][0].s;
		int end = edge[i][0].e;
		v[start].push_back(end);
	}
	for (int i = 1; i <= n; i++)
		dist[i] = MAX;
	dist[1] = 0;
	dijkstra(1);
	for (int i = q ; i > 0; i--) {
		if (query[i][0].order == 'U') {
			int vv = query[i][0].num;
			int start = edge[vv][0].s;
			int end = edge[vv][0].e;
			v[start].push_back(end);
			if (dist[end] <= dist[start] + 1) continue;		//어차피 최단경로 갱신 안되는 경우
			dist[end] = dist[start] + 1;
			dijkstra(end);
		}
		else {
			int temp = dist[query[i][0].num] == MAX ? -1 : dist[query[i][0].num];
			ans.push_back(temp);
		}
	}
	for (int i = ans.size() - 1; i >= 0; i--)
		cout << ans[i] << '\n';
	system("pause");
	return 0;
}