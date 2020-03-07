#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
vector<int> v[50001];
int tree[17][50001], depth[50001];
int num;

int find_LCA(int child, int parent) {
	int diff = depth[child] - depth[parent];
	for (int i = 16; i >= 0; i--) {
		int tt = pow(2, i);
		if (tt <= diff) {
			child = tree[i][child];
			diff -= tt;
		}
	}
	if (child == parent) return child;
	int tt = depth[child] - 1;
	while (tt > 0) {
		if (tree[0][child] == tree[0][parent])
			break;
		child = tree[0][child];
		parent = tree[0][parent];
		tt--;
	}
	return tree[0][child];
}

void make_tree() {
	queue<int> q;
	q.push(1);
	tree[0][1] = 1;
	depth[1] = 1;
	while (!q.empty()) {
		int cidx = q.front();
		q.pop();
		for (int i = 0; i < v[cidx].size(); i++) {
			int next = v[cidx][i];
			if (depth[next] == 0) {
				tree[0][next] = cidx;
				depth[next] = depth[cidx] + 1;
				q.push(next);
			}
		}
	}
}

void find_parent() {
	for (int i = 1; i < 17; i++) {
		for (int j = 1; j <= num; j++)
			tree[i][j] = tree[i - 1][tree[i - 1][j]];
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int a, b, query;
	cin >> num;
	for (int i = 0; i < num-1; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	make_tree();
	find_parent();
	cin >> query;
	int result;
	for (int i = 0; i < query; i++) {
		cin >> a >> b;
		result = depth[a] > depth[b] ? find_LCA(a, b) : find_LCA(b, a);
		cout << result << '\n';
	}
	system("pause");
	return 0;
}