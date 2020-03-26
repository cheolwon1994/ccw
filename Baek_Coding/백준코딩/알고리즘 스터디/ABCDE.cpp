#include <iostream>
#include <vector>
using namespace std;
vector<int> v[2000];
bool visit[2000];
bool avail = false;

void dfs(int idx, int cnt) {
	if (cnt == 4) {
		avail = true;
		return;
	}
	for (int i = 0; i < v[idx].size(); i++) {
		int next = v[idx][i];
		if (!visit[next]) {
			visit[next] = true;
			dfs(next, cnt + 1);
			visit[next] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int node, edge, s, e;
	cin >> node >> edge;
	for (int i = 0; i < edge; i++) {
		cin >> s >> e;
		v[s].push_back(e);
		v[e].push_back(s);
	}	
	for (int i = 0; i < node; i++) {
		for (int j = 0; j < node; j++)
			visit[j] = false;
		visit[i] = true;
		dfs(i, 0);
		if (avail) break;
	}
	if (avail) cout << 1;
	else cout << 0;
	system("pause");
	return 0;
}