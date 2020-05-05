#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
struct info {
	int idx, val;
};
info tmp;
struct cmp {
	bool operator()(info &a, info &b) {
		return a.val > b.val;
	}
};
int arr[1001];	//해당 건물만을 짓는데 걸리는 시간
int pre[1001];		//해당 건물을 짓기 위해 선행으로 지어져야 하는 건물의 수
vector<int> v[1001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int test, result, node, edge, s, e, target;
	cin >> test;
	for (int t = 0; t < test; t++) {
		cin >> node >> edge;
		result = 0;
		for (int i = 1; i <= node; i++) {
			cin >> arr[i];
			v[i].clear();
			pre[i] = 0;
		}
		for (int i = 0; i < edge; i++) {
			cin >> s >> e;
			v[s].push_back(e);
			pre[e]++;
		}
		cin >> target;
		if (pre[target] == 0) {
			cout << arr[target] << '\n';
			continue;
		}
		priority_queue<info, vector<info>, cmp> pq;
		for (int i = 1; i <= node; i++) {
			if (pre[i] == 0) {
				tmp.idx = i;
				tmp.val = arr[i];
				pq.push(tmp);
			}
		}
		while (!pq.empty()) {
			int cidx = pq.top().idx;
			int cv = pq.top().val;
			pq.pop();
			for (int i = 0; i < v[cidx].size(); i++) {
				int next = v[cidx][i];
				pre[next]--;
				if (pre[next] == 0) {
					int nv = cv + arr[next];
					if (next == target) {
						result = nv;
						break;
					}
					tmp.idx = next;
					tmp.val = nv;
					pq.push(tmp);
				}
			}
		}
		cout << result << '\n';
	}
	system("pause");
	return 0;
}