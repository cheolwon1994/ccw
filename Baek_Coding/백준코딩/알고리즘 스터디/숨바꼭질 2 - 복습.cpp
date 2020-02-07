#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
bool check[100001];
struct info{
	int val, idx;
};
info tmp;
int main() {
	int start, target;
	cin >> start >> target;
	queue<info> q;
	tmp.idx = start;
	tmp.val = 0;
	q.push(tmp);
	check[start] = true;
	int cnt = 0;
	int result = 100000;
	while (!cnt) {
		int len = q.size();
		for (int t = 0; t < len; t++) {
			int ci = q.front().idx;
			int cv = q.front().val;
			check[ci] = true;
			q.pop();
			if (ci == target) { cnt++; result = min(result, cv); }
			if (ci - 1 >= 0 && !check[ci - 1]) {
				tmp.idx = ci - 1;
				tmp.val = cv + 1;
				q.push(tmp);
			}
			if (ci + 1 <= 100000 && !check[ci + 1]) {
				tmp.idx = ci + 1;
				tmp.val = cv + 1;
				q.push(tmp);
			}
			if (ci * 2 <= 100000 && !check[2 * ci]) {
				tmp.idx = 2 * ci;
				tmp.val = cv + 1;
				q.push(tmp);
			}
		}
	}
	cout << result << endl << cnt;
	system("pause");
	return 0;
}