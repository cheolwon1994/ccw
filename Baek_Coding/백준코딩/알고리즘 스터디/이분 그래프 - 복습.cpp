#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v[20001];
int visit[20001];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int test, node, edge, start, end;
	cin >> test;
	for (int t = 0; t < test; t++) {
		cin >> node >> edge;
		for (int i = 1; i <= node; i++) {
			v[i].clear();
			visit[i] = -1;
		}
		for (int i = 0; i < edge; i++) {
			cin >> start >> end;
			v[start].push_back(end);
			v[end].push_back(start);
		}
		bool avail = true;
		for (int k = 1; k <= node; k++) {
			if (visit[k] != -1) continue;
			queue<int> q;
			q.push(k);
			visit[k] = k;
			while (!q.empty()) {
				int cidx = q.front();
				q.pop();
				for (int i = 0; i < v[cidx].size(); i++) {
					int next = v[cidx][i];
					if (visit[next] == -1) {		//아직 방문 안한 경우
						visit[next] = 3 - visit[cidx];
						q.push(next);
					}
					else if (visit[next] == visit[cidx]) {		//나랑 같은 집합인데 한번 더 연결하려는 경우 -> 이분그래프 실패
						avail = false;
						break;
					}
				}
				if (!avail) break;
			}
			if (!avail) break;
		}
		if (avail) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	system("pause");
	return 0;
}