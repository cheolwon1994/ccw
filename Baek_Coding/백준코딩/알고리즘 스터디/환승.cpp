#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
struct info {
	int idx, val;
};
info tmp;
vector<int> hyper[101001];		//1~n: �� node�� ���Ե� hypertube����, n+1~n+query: hypertube�� ���� ����
bool dist[101001] = { false, };
int result = -1;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int node, conn, query, tt;
	cin >> node >> conn >> query;
	for (int i = 0; i < query; i++) {
		for (int j = 0; j < conn; j++) {
			cin >> tt;
			hyper[node + i + 1].push_back(tt);
			hyper[tt].push_back(node + i + 1);
		}
	}
	queue<info> q;
	tmp.idx = 1;
	tmp.val = 1;
	q.push(tmp);
	dist[1] = true;
	while (!q.empty()) {
		int cidx = q.front().idx;
		int cv = q.front().val;
		q.pop();
		if (cidx == node) {
			result = cv;
			break;
		}
		for (int i = 0; i < hyper[cidx].size(); i++) {
			int qry = hyper[cidx][i];
			if (dist[qry]) continue;
			dist[qry] = true;
			if (qry > node) {		//�ͳ��� ����
				tmp.idx = qry;
				tmp.val = cv;
				q.push(tmp);
			}
			else {		//����Ǿ� �ִ� �ͳ� ����
				tmp.idx = qry;
				tmp.val = cv + 1;
				q.push(tmp);
			}
		}
	}
	cout << result;
	system("pause");
	return 0;
}