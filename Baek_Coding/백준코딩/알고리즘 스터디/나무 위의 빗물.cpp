#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
vector<int> v[500001];
bool visit[500001] = { false, };
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout.precision(11);
	int num, a, b, cnt = 0;
	double sum;
	cin >> num >> sum;
	for (int i = 0; i < num - 1; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	queue<int> q;
	visit[1] = true;
	q.push(1);
	while (!q.empty()) {
		int cidx = q.front();
		q.pop();
		bool avail = false;
		for (int i = 0; i < v[cidx].size(); i++) {
			int next = v[cidx][i];
			if (visit[next]) continue;
			visit[next] = true;
			q.push(next);
			avail = true;
		}
		if (!avail)	cnt++;
	}
	cout << sum / cnt;
	system("pause");
	return 0;
}