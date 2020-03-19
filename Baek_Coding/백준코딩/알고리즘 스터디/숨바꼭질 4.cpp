#define MAX 100001
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int dp[MAX];
int before[MAX];
struct info {
	int val, idx;
};
info tmp;
int main() {
	int start, target;
	cin >> start >> target;
	for (int i = 0; i < MAX; i++) {
		dp[i] = MAX;
		before[i] = -1;
	}
	before[start] = start;
	dp[start] = 0;
	queue<info> q;
	tmp.idx = start;
	tmp.val = 0;
	q.push(tmp);
	int result = 0;
	while (!q.empty()) {
		int cidx = q.front().idx;
		int cv = q.front().val;
		q.pop();
		if (cidx == target) {
			result = cv;
			break;
		}
		if (cidx - 1 >= 0 && dp[cidx - 1] > cv + 1) {
			dp[cidx-1] = cv + 1;
			tmp.idx = cidx - 1;
			tmp.val = cv + 1;
			before[cidx - 1] = cidx;			
			q.push(tmp);
		}
		if (cidx + 1 <= MAX - 1 && dp[cidx + 1] > cv + 1) {
			dp[cidx+1] = cv + 1;
			tmp.idx = cidx + 1;
			tmp.val = cv + 1;
			before[cidx + 1] = cidx;
			q.push(tmp);
		}
		if (cidx * 2 <= MAX - 1 && dp[cidx * 2] > cv + 1) {
			dp[cidx * 2] = cv + 1;
			tmp.idx = cidx * 2;
			tmp.val = cv + 1;
			before[cidx * 2] = cidx;
			q.push(tmp);
		}
	}
	cout << result << '\n';
	int t = target;
	vector<int> ans;
	while (1) {
		ans.push_back(t);
		if (t == start) break;	
		t = before[t];
	}
	for (int i = ans.size() - 1; i >= 0; i--)
		cout << ans[i] << " ";
	system("pause");
	return 0;
}