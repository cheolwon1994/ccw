#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int conn[1001];
bool visit[1001];
vector<int> v[1001];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int num, pd, a, val;
	cin >> num >> pd;
	for (int i = 0; i < pd; i++) {
		cin >> a;
		vector<int> t;
		for (int j = 0; j < a; j++) {
			cin >> val;
			t.push_back(val);
		}
		for (int j = 0; j < t.size() - 1; j++) {
			int f = t[j];
			int s = t[j + 1];
			conn[s]++;
			v[f].push_back(s);
		}
	}
	queue<int> q;
	for (int i = 1; i <= num; i++)
		if (conn[i] == 0) {
			q.push(i);
		}
	vector<int> result;
	while (!q.empty()) {
		int idx = q.front();
		q.pop();
		if (visit[idx]) continue;
		visit[idx] = true;
		result.push_back(idx);
		for (int i = 0; i < v[idx].size(); i++) {
			int next = v[idx][i];
			if (!visit[next]) {
				conn[next]--;
				if (conn[next] == 0) 
					q.push(next);				
			}
		}
	}
	if (result.size() != num) cout << 0;
	else {
		for (int i = 0; i < num; i++)
			cout << result[i] << '\n';
	}
	return 0;
}