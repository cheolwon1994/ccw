#include <iostream>
#include <queue>
#include <set>
using namespace std;
struct info {
	long long idx;
	int val;
};
info tmp;
int main() {
	long long start, target, result = -1;
	cin >> start >> target;
	if (start <= target) {
		queue<info> q;
		set<long long> s;
		tmp.idx = start;
		tmp.val = 0;
		q.push(tmp);
		s.insert(start);
		while (!q.empty()) {
			long long cidx = q.front().idx;
			int cv = q.front().val;
			q.pop();
			if (cidx == target) {
				result = cv + 1;
				break;
			}
			if (cidx * 2 <= target && s.find(cidx * 2)==s.end()) {
				tmp.idx = 2 * cidx;
				tmp.val = cv + 1;
				q.push(tmp);
				s.insert(cidx * 2);
			}
			if (cidx * 10 + 1 <= target && s.find(cidx * 10+1) == s.end()) {
				tmp.idx = cidx * 10 + 1;
				tmp.val = cv + 1;
				q.push(tmp);
				s.insert(cidx * 10 + 1);
			}
		}
	}
	cout << result;
	system("pause");
	return 0;
}