#define MAX 987654321
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct info {
	int end, cost;
};
struct cmp {
	bool operator()(info &a, info &b) {
		return a.cost < b.cost;
	}
};
info tmp;
vector <info> arr[101];
int main() {
	int num, test, start, end, val;
	cin >> num >> test;
	for (int t = 0; t < test; t++) {
		cin >> start >> end >> val;
		tmp.end = end;
		tmp.cost = val;
		arr[start].push_back(tmp);
	}
	for (int k = 1; k <= num; k++) {
		int dist[101];
		fill(dist, dist + num + 1, MAX);
		priority_queue<info, vector<info>, cmp> pq;
		dist[k] = 0;
		tmp.cost = 0;
		tmp.end = k;
		pq.push(tmp);
		while (!pq.empty()) {
			int cost = pq.top().cost;
			int start = pq.top().end;
			pq.pop();
			for (int i = 0; i < arr[start].size(); i++) {
				int next = arr[start][i].end;
				int edge_cost = arr[start][i].cost;
				if (dist[next] > dist[start] + edge_cost) {
					dist[next] = dist[start] + edge_cost;
					tmp.cost = dist[next];
					tmp.end = next;
					pq.push(tmp);
				}
			}
		}
		for (int i = 1; i <= num; i++) {
			if (dist[i] == MAX) cout << 0 << " ";
			else cout << dist[i] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}