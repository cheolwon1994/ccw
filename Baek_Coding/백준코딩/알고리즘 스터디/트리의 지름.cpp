#define MAX 987654321
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
struct info {
	int idx, val;
};
info tmp;
vector<info> v[100001];
int dist[100001], result = 0, maxleaf = 0, maxi, node;
void dijkstra(int start) {
	for (int i = 1; i <= node; i++) 
		dist[i] = MAX;	
	queue<info> q;
	tmp.idx = start;
	tmp.val = 0;
	q.push(tmp);
	dist[start] = 0;
	maxi = 0;
	while(!q.empty()) {
		int cidx = q.front().idx;
		int cv = q.front().val;
		q.pop();
		for (int i = 0; i < v[cidx].size(); i++) {
			int next = v[cidx][i].idx;
			int nv = v[cidx][i].val;
			if (dist[next] > cv + nv) {
				dist[next] = cv + nv;
				tmp.idx = next;
				tmp.val = cv + nv;
				q.push(tmp);
				if (cv + nv > maxi) {
					maxi = cv + nv;
					maxleaf = next;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, start, val;
	cin >> node;
	for (int i = 1; i <= node; i++) {
		cin >> n;
		while (1) {
			cin >> start;
			if (start == -1) break;
			cin >> val;
			tmp.idx = start;
			tmp.val = val;
			v[n].push_back(tmp);
			tmp.idx = n;
			v[start].push_back(tmp);
		}
	}
	dijkstra(1);
	dijkstra(maxleaf);
	cout << maxi;
	system("pause");
	return 0;
}