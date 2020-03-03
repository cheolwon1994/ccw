#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> v[32001];
int conn[32001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int problem, edge, start, end;
	cin >> problem >> edge;
	for (int i = 0; i < edge; i++) {
		cin >> start >> end;
		v[start].push_back(end);
		conn[end]++;
	}
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i <= problem; i++)
		if (conn[i] == 0)
			pq.push(i);
	for (int i = 0; i < problem; i++) {
		int cidx = pq.top();
		pq.pop();
		cout << cidx << " ";
		for (int j = 0; j < v[cidx].size(); j++) {
			conn[v[cidx][j]]--;
			if (conn[v[cidx][j]] == 0)
				pq.push(v[cidx][j]);
		}
	}
	system("pause");
	return 0;
}