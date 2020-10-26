#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct info {
	int idx;
	char c;
};
info tmp;
vector<info> v[501];
char card[1001];
int dp[1001][501];
int num, node, edge, a, b;

int score(int idx, int cnt) {
	if (cnt == num) return 0;
	int &res = dp[cnt][idx];
	if (res != -1) return res;
	res = 0;
	for (int i = 0; i < v[idx].size(); i++) {
		int next = v[idx][i].idx;
		char col = v[idx][i].c;
		res = max(res, score(next, cnt + 1) + (card[cnt] == col ? 10 : 0));
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	char c;
	cin >> num;
	for (int i = 0; i < num; i++)
		cin >> card[i];
	cin >> node >> edge;
	for (int i = 0; i < 1001; i++)
		for (int j = 0; j < 501; j++)
			dp[i][j] = -1;
	for (int i = 0; i < edge; i++) {
		cin >> a >> b >> c;
		tmp.idx = b;
		tmp.c = c;
		v[a].push_back(tmp);
		tmp.idx = a;
		v[b].push_back(tmp);
	}
	cout << score(1, 0);
	return 0;
}