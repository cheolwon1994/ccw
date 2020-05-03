#define MAX 987654321
#include <iostream>
#include <vector>
using namespace std;
struct info {
	long long to, val;
};
info tmp;
vector<info> v[501];
long long dist[501];
bool cycle = false;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int node, edge, from, to, result;
	long long val;
	cin >> node >> edge;
	for (int i = 0; i < edge; i++) {
		cin >> from >> to >> val;
		tmp.to = to;
		tmp.val = val;
		v[from].push_back(tmp);
	}
	for (int i = 1; i <= node; i++)
		dist[i] = MAX;
	dist[1] = 0;

	for (int i = 1; i <= node; i++) {
		for (int j = 1; j <= node; j++) {
			from = j;
			for (int k = 0; k < v[from].size(); k++) {
				to = v[from][k].to;
				val = v[from][k].val;
				if (dist[from] != MAX && dist[to] > dist[from] + val) {
					if (i == node)
						cycle = true;
					dist[to] = dist[from] + val;
				}
			}
		}
	}
	if (cycle)
		cout << -1;
	else {
		for (int i = 2; i <= node; i++) {
			if (dist[i] == MAX) cout << -1 << '\n';
			else cout << dist[i] << '\n';
		}
	}
	return 0;
	system("pause");
}