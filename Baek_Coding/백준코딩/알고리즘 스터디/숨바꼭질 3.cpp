#define MAX 100001
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int check[MAX];
struct info {
	int idx, mv;
};
info tmp;

int main() {
	int start, end, cidx, cmv;
	cin >> start >> end;
	tmp.idx = start;
	tmp.mv = 0;
	queue<info> q;
	q.push(tmp);
	int cnt = 0;
	bool finish = false;
	int result = MAX;
	while (!q.empty()) {
		int len = q.size();
		for (int i = 0; i < len; i++) {
			cidx = q.front().idx;
			cmv = q.front().mv;
			q.pop();
			check[cidx] = 1;
			if (cidx == end) { finish = true; result = min(result, cmv); continue; }
			if (cidx + 1 < MAX && check[cidx + 1] == 0) {
				tmp.idx = cidx + 1;
				tmp.mv = cmv + 1;
				if(!finish)
					q.push(tmp);
			}
			if (cidx - 1 >= 0 && check[cidx - 1] == 0) {
				tmp.idx = cidx - 1;
				tmp.mv = cmv + 1;
				if(!finish)
					q.push(tmp);
			}
			if (cidx * 2 < MAX && check[2 * cidx] == 0) {
				tmp.idx = cidx * 2;
				tmp.mv = cmv;
				if(!finish)
					q.push(tmp);
			}
		}
	}
	cout << result;
	system("pause");
	return 0;
}