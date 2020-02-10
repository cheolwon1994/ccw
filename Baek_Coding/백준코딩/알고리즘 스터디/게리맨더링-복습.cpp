#define MAX 987654321
#include <iostream>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
int pop[11];
int num;
bool check[11][11];
vector<int> a;
vector<int> b;
bool flag[11];
int result = MAX;
void start() {
	//a
	bool avail = true;
	if (a.size() > 1) {
		int cnt = 0;
		queue<int> q;
		bool test[11] = { false, };
		q.push(a[0]);
		while (!q.empty()) {
			int cidx = q.front();
			q.pop();
			cnt++;
			test[cidx] = true;
			for (int i = 1; i <= num; i++) {
				if (i == cidx) continue;
				if (flag[i] && !test[i] && check[cidx][i]) {
					q.push(i);
					test[i] = true;
				}
			}
		}
		if (cnt != a.size()) avail = false;
	}
	//b
	if (avail) {
		if (b.size() > 1) {
			int cnt = 0;
			queue<int> q;
			bool test[11] = { false, };
			q.push(b[0]);
			while (!q.empty()) {
				int cidx = q.front();
				q.pop();
				cnt++;
				test[cidx] = true;
				for (int i = 1; i <= num; i++) {
					if (i == cidx) continue;
					if (!flag[i] && !test[i] && check[cidx][i]) {
						q.push(i);
						test[i] = true;
					}
				}
			}
			if (cnt != b.size()) avail = false;
		}
	}
	if (avail) {
		int a_sum = 0;
		int b_sum = 0;
		for (int i = 1; i <= num; i++) {
			if (flag[i]) a_sum += pop[i];
			else b_sum += pop[i];
		}
		result = min(result, abs(a_sum - b_sum));
	}
}

void dfs(int cnt, int idx) {
	if (cnt > num) return;
	if (2<=cnt && cnt <= num) {
		b.clear();
		for (int i = 1; i <= num; i++) {
			if (!flag[i])
				b.push_back(i);
		}
		start();
	}
	for (int i = idx; i <= num; i++) {
		if (!flag[i]) {
			flag[i] = true;
			a.push_back(i);
			dfs(cnt + 1,i);
			a.pop_back();
			flag[i] = false;
		}
	}
}

int main() {
	cin >> num;
	for (int i = 1; i <= num; i++)
		cin >> pop[i];
	for (int i = 1; i <= num; i++) {
		int tt;
		cin >> tt;
		for (int j = 0; j < tt; j++) {
			int t;
			cin >> t;
			check[i][t] = true;
		}
	}
	dfs(1,1);
	if (result == MAX) cout << -1;
	else	cout << result;
	system("pause");
	return 0;
}