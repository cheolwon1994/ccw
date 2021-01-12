#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> v[1001];
bool check[1001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int test;
	cin >> test;
	for (int t = 0; t < test; t++) {
		int node, edge, a, b;
		cin >> node>> edge;
		for (int i = 1; i <= node; i++) {
			v[i].clear();
			check[i] = false;
		}
		for (int i = 0; i < edge; i++) {
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		int result = 0;
		queue<int> q;
		q.push(1);
		check[1] = true;
		while (!q.empty()) {
			int cidx = q.front();
			q.pop();
			for (int i = 0; i < v[cidx].size(); i++) {
				int next = v[cidx][i];
				if (!check[next]) {
					check[next] = true;
					result++;
					q.push(next);
				}
			}
		}
		cout << result << '\n';
	}
	return 0;
}