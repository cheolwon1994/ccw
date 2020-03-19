#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> v[501];
bool visit[501] = { false, };
int main() {
	int node, num, s, e;
	cin >> node >> num;
	for (int i = 0; i < num; i++) {
		cin >> s >> e;
		v[s].push_back(e);
		v[e].push_back(s);
	}
	int result = 0;
	queue<int> q;
	visit[1] = true;
	for (int i = 0; i < v[1].size(); i++) {
		q.push(v[1][i]);
		visit[v[1][i]] = true;
		result++;
	}
	while (!q.empty()) {
		int cidx = q.front();
		q.pop();
		for (int i = 0; i < v[cidx].size(); i++) {
			int next = v[cidx][i];
			if (visit[next]) continue;
			visit[next] = true;
			result++;
		}
	}
	cout << result;
	system("pause");
	return 0;
}