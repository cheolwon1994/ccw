#include <iostream>
#include <vector>
using namespace std;
int par[100001], node, a, b;
vector<int> v[100001];

void dfs(int idx) {
	for (int i = 0; i < v[idx].size(); i++) {
		int next = v[idx][i];
		if (par[next] == -1) {
			par[next] = idx;
			dfs(next);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> node;
	for (int i = 1; i <= node; i++) 
		par[i] = -1;
	for (int i = 1; i < node ; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	par[1] = 1;
	dfs(1);
	for (int i = 2; i <= node; i++)
		cout << par[i] << '\n';
	return 0;
}