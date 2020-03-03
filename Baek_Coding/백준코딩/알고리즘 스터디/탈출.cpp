#define MAX 987654321
#include <iostream>
#include <queue>
using namespace std;
bool check[100000] = { false, };
struct info {
	int idx, val;
};
info tmp;

int cal(int num) {
	int cnt = 0;
	while (num > 0) {
		num /= 10;
		cnt++;
	}
	return cnt;
}

int main() {
	int start, limit, target;
	cin >> start >> limit >> target;
	queue<info> q;
	tmp.idx = start;
	tmp.val = 0;
	check[start] = true;
	q.push(tmp);
	int result = MAX;
	while (!q.empty()) {
		int cidx = q.front().idx;
		int cv = q.front().val;
		q.pop();
		//cout << cidx << endl;
		if (cidx == target) {
			result = cv;
			break;
		}
		if (cv == limit) continue;
		if (cidx >= 50000) {		//a¸¸ °¡´É
			if (!check[cidx + 1] && cidx+1<100000) {
				check[cidx + 1] = true;
				tmp.idx = cidx + 1;
				tmp.val = cv + 1;
				q.push(tmp);
			}
		}
		else {
			//a
			if (!check[cidx + 1]) {
				check[cidx + 1] = true;
				tmp.idx = cidx + 1;
				tmp.val = cv + 1;
				q.push(tmp);
			}
			//b
			if (cidx != 0) {
				int nidx = 2 * cidx;
				int len = cal(nidx);
				int tt = 1;
				for (int i = 1; i < len; i++)
					tt *= 10;
				nidx -= tt;
				if (!check[nidx]) {
					check[nidx] = true;
					tmp.idx = nidx;
					tmp.val = cv + 1;
					q.push(tmp);
				}
			}
		}
	}
	if (result == MAX) cout << "ANG";
	else cout << result;
	system("pause");
	return 0;
}