#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
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
vector<int> v[501];		//해당 번호가 선행되어야 하는 번호들
int need_pre[501];		//
int need_time[501];		//해당 번호만을 짓는데 걸리는 시간
int tot_time[501];		//해당 번호까지 다 짓는데 걸리는 시간

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int node, val;
	cin >> node;
	for (int i = 1; i <= node; i++) {
		cin >> need_time[i];
		while (1) {
			cin >> val;
			if (val == -1) break;
			v[val].push_back(i);
			need_pre[i]++;
		}
	}
	priority_queue<info, vector<info>, cmp> pq;
	for (int i = 1; i <= node; i++) {
		if (need_pre[i] == 0) {
			tmp.idx = i;
			tmp.val = need_time[i];
			pq.push(tmp);
			tot_time[i] = need_time[i];
		}			
	}
	while (!pq.empty()) {
		int cidx = pq.top().idx;
		int cv = pq.top().val;
		pq.pop();
		for (int i = 0; i < v[cidx].size(); i++) {
			int next = v[cidx][i];
			need_pre[next]--;
			if (need_pre[next] == 0) {
				tmp.idx = next;
				tmp.val = cv + need_time[next];
				pq.push(tmp);
				tot_time[next] = tmp.val;
			}
		}
	}
	for (int i = 1; i <= node; i++)
		cout << tot_time[i] << '\n';
	system("pause");
	return 0;
}