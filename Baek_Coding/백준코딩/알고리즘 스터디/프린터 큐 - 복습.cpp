#include <iostream>
#include <queue>
using namespace std;
struct info {
	int idx, pri;
};
info tmp;
int main() {
	int test, num, target, tt;
	cin >> test;
	for (int t = 0; t < test; t++) {
		queue<info> q;
		priority_queue<int, vector<int>, less<int>> pq;
		cin >> num >> target;
		for (int i = 0; i < num; i++) {
			cin >> tt;
			tmp.idx = i;
			tmp.pri = tt;
			q.push(tmp);
			pq.push(tt);
		}
		int cnt = 0;
		bool finish = false;
		while (!pq.empty()) {
			int val = pq.top();
			pq.pop();
			while (!q.empty()) {
				int cidx = q.front().idx;
				int cp = q.front().pri;
				q.pop();
				if (val == cp) {
					cnt++;
					if (cidx == target) {
						finish = true;
						break;
					}
					break;
				}
				else {
					tmp.idx = cidx;
					tmp.pri = cp;
					q.push(tmp);
				}
			}
			if (finish) break;
		}
		cout << cnt << '\n';
	}
	system("pause");
	return 0;
}