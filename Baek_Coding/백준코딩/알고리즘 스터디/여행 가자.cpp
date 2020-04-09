#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> v[201];
bool need_visit[201] = { false, };
bool visit[201] = { false, };

int main() {
	int node, m, val, tt = -1;
	cin >> node >> m;
	for (int i = 1; i <= node; i++) {
		for (int j = 1; j <= node; j++) {
			cin >> val;
			if (val == 1) {
				v[i].push_back(j);
				v[j].push_back(i);
			}
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> val;
		if (tt == -1) tt = val;
		need_visit[val] = true;
	}
	queue<int> q;
	q.push(tt);
	visit[tt] = true;
	need_visit[tt] = false;
	while (!q.empty()) {
		int cidx = q.front();
		q.pop();
		for (int i = 0; i < v[cidx].size(); i++) {
			int next = v[cidx][i];
			if (!visit[next]) {
				visit[next] = true;
				q.push(next);
				if (need_visit[next])	need_visit[next] = false;
			}
		}
	}
	bool avail = true;
	for (int i = 1; i <= node; i++) {
		if (need_visit[i]) {
			avail = false;
			break;
		}
	}
	if (avail) cout << "YES";
	else cout <<"NO";
	system("pause");
	return 0;
}