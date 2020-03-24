#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> v[100001];
int parent[100001];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int node, s, e;
	cin >> node;
	for (int i = 0; i < node - 1; i++) {
		cin >> s >> e;
		v[s].push_back(e);
		v[e].push_back(s);
	}
	for (int i = 1; i <= node; i++)
		parent[i] = -1;
	queue<int> q;
	q.push(1);
	parent[1] = 1;
	while (!q.empty()) {
		int cidx = q.front();
		q.pop();
		for (int i = 0; i < v[cidx].size(); i++) {
			int next = v[cidx][i];
			if (parent[next] == -1) {
				parent[next] = cidx;
				q.push(next);
			}
		}
	}
	for (int i = 2; i <= node; i++)
		cout << parent[i] << '\n';
	system("pause");
	return 0;
}