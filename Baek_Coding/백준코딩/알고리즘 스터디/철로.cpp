#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct info {
	long long s, e;
};
struct cmp {
	bool operator()(info &a, info &b) {
		if (a.e == b.e)
			return a.s > b.s;
		return a.e > b.e;
	}
};
info tmp;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long s, e, limit;
	int num, result = 0;
	cin >> num;
	priority_queue<info, vector<info>, cmp> pq;
	for (int i = 0; i < num; i++) {
		cin >> s >> e;
		//오른쪽 부분이 먼저 입력으로 들어올 수 있다
		tmp.s = min(s, e);
		tmp.e = max(s, e);
		pq.push(tmp);
	}
	cin >> limit;
	priority_queue<long long,vector<long long>, greater<long long>> q;
	while (!pq.empty()) {
		int cs = pq.top().s;
		int ce = pq.top().e;
		pq.pop();
		if (ce - cs <= limit)		//철로의 길이 사이에 위치한다면 우선순위 큐에 시작점 삽입
			q.push(cs);
		while (!q.empty()) {
			if (ce - q.top() <= limit)
				break;
			else
				q.pop();
		}
		int len = q.size();
		result = max(result, len);
	}
	cout << result;
	system("pause");
	return 0;
}