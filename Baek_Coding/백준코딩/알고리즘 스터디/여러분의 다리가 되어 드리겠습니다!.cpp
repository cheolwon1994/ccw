#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> v[300001];
int flag[300001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int node, s, e, idx = 0;
	cin >> node;
	for (int i = 0; i < node - 2; i++) {
		cin >> s >> e;
		v[s].push_back(e);
		v[e].push_back(s);
	}
	queue<int> q;
	q.push(1);
	flag[1] = 1;
	while (!q.empty()) {
		int cidx = q.front();
		q.pop();
		for (int i = 0; i < v[cidx].size(); i++) {
			int next = v[cidx][i];
			if (flag[next] == 0) {
				flag[next] = 1;
				q.push(next);
			}
		}
	}
	for (int i = 1; i <= node; i++) {
		if (flag[i] == 0) {
			idx = i;
			break;
		}
	}
	cout << 1 << " " << idx;
	system("pause");
	return 0;
}