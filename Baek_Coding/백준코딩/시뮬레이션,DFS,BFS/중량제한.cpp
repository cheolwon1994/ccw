#define MAX 1000000000
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;
int island, num, first, second, weight, l, r, mid, cidx, cv;
struct info {
	int idx;
	int weight;
};
vector<info> v[100001];
int check[100001];
int result = 0;
int ans = 0;
bool bfs(int cur_val) {
	queue<int> q;
	q.push(first);
	check[first] = 1;
	bool flag = false;
	while (!q.empty()) {
		cv = q.front();
		q.pop();
		if (cv == second) {
			flag = true;
			break;
		}
		for (int i = 0; i < v[cv].size(); i++) {
			if (v[cv][i].weight >= cur_val && check[v[cv][i].idx] != 1) {
				check[v[cv][i].idx] = 1;
				q.push(v[cv][i].idx);
			}
		}
	}
	return flag;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> island >> num;
	for (int i = 0; i < num; i++) {
		cin >> first >> second >> weight;
		v[first].push_back({ second,weight });
		v[second].push_back({ first,weight });
	}
	cin >> first >> second;
	l = 1;
	r = MAX;
	while (l <= r) {
		memset(check, 0, sizeof(check));
		mid = l + (r - l) / 2;
		if (bfs(mid))
			l = mid + 1;
		else
			r = mid - 1;
	}
	cout << r;
	system("pause");
	return 0;
}