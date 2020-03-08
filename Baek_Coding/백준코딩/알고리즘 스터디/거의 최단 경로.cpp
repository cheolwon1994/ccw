#define MAX 987654321
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct info {
	int idx, val, used;
};
info tmp;
struct info2 {
	int start, edgeNum;
};
info2 tmp2;
struct cmp {
	bool operator()(info &a, info &b) {
		return a.val > b.val;
	}
};
long long dist[500];
vector<info> v[500];
vector<info2> memo[500];

int node, edge, start, s, e;

void dijkstra() {
	priority_queue<info, vector<info>, cmp> pq;
	tmp.idx = start;
	tmp.val = 0;
	pq.push(tmp);
	dist[start] = 0;
	tmp2.start = start;
	tmp2.edgeNum = 0;
	memo[start].push_back(tmp2);
	while (!pq.empty()) {
		int cidx = pq.top().idx;
		int cv = pq.top().val;
		pq.pop();
		if (cv > dist[cidx]) continue;
		for (int i = 0; i < v[cidx].size(); i++) {
			if (v[cidx][i].used == 0) {
				int next = v[cidx][i].idx;
				int nv = v[cidx][i].val;
				if (dist[next] > cv + nv) {		//���ο� �ִܰŸ��� ���ŵ� ���
					dist[next] = cv + nv;
					tmp.idx = next;
					tmp.val = cv + nv;
					pq.push(tmp);

					//������ �ִ� ��� �ʱ�ȭ
					memo[next].clear();
					tmp2.start = cidx;
					tmp2.edgeNum = i;
					memo[next].push_back(tmp2);
				}
				else if (dist[next] == cv + nv) {		//���� �Ÿ��� ����� ��� �߰�
					tmp2.start = cidx;
					tmp2.edgeNum = i;
					memo[next].push_back(tmp2);
				}
			}
		}
	}
}

void make_disable(int num) {
	if (num == start) return;
	for (int i = 0; i < memo[num].size(); i++) {
		int from = memo[num][i].start;
		int number = memo[num][i].edgeNum;
		v[from][number].used = 1;
		make_disable(from);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int val, target;
	while (1) {
		cin >> node >> edge;
		if (node + edge == 0) break;
		cin >> start >> target;
		//�ʱ�ȭ
		for (int i = 0; i < node; i++) {
			v[i].clear();
			dist[i] = MAX;
			memo[i].clear();
		}

		for (int i = 0; i < edge; i++) {
			cin >> s >> e >> val;
			tmp.idx = e;
			tmp.val = val;
			tmp.used = 0;
			v[s].push_back(tmp);
		}
		dijkstra();
		if (dist[target] == MAX) {		//target������ �Ÿ��� �������� ���� ���
			cout << -1 << '\n';
			continue;
		}
		make_disable(target);
		int minDist = dist[target], result;
		while (1) {
			//�ʱ�ȭ
			for (int i = 0; i < node; i++) {
				dist[i] = MAX;
				memo[i].clear();
			}
			dijkstra();
			if (dist[target] != minDist) {		//�ִܰ�ΰ� �ƴ� ���(���� �ִ� or ���� ���)
				result = dist[target];
				break;
			}
			make_disable(target);
		}
		if (result == MAX) 	cout << -1 << '\n';
		else cout << result << '\n';		
	}
	system("pause");
	return 0;
}