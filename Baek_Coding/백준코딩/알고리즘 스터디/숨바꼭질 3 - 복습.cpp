#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
struct info {
	int idx, val;
};
info tmp;
bool check[100001] = { false, };

int main() {
	int start, end;
	cin >> start >> end;
	queue<info> q;
	tmp.idx = start;
	tmp.val = 0;
	q.push(tmp);
	check[start] = true;
	bool finish = false;
	int result = 987654321;
	while (!q.empty()) {
		int cidx = q.front().idx;
		int cv = q.front().val;
		q.pop();
		check[cidx] = true;
		if (cidx == end) {
			result = min(result,cv);
			finish = true;
		}
		if (finish && cv>=result) continue;

		if (cidx - 1 >= 0 && !check[cidx - 1]) {
			tmp.idx = cidx - 1;
			tmp.val = cv + 1;
			q.push(tmp);
		}
		if (cidx + 1 <= 100000 && !check[cidx + 1]) {
			tmp.idx = cidx + 1;
			tmp.val = cv + 1;
			q.push(tmp);
		}
		if (cidx * 2 <= 100000 && !check[2 * cidx]) {
			tmp.idx = cidx * 2;
			tmp.val = cv;
			q.push(tmp);
		}
	}
	cout << result;
	system("pause");
	return 0;
}