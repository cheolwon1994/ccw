#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int num;
bool check[10000] = { false, };
struct info {
	int dist, oil;
};
struct cmp {
	bool operator()(info &a, info &b) {
		return a.oil < b.oil;
	}
};
struct cmp2 {
	bool operator()(info &a, info &b) {
		return a.dist > b.dist;
	}
};
info tmp;
priority_queue<info, vector<info>, cmp> pq;
priority_queue<info, vector<info>, cmp2> pq2;

int main() {
	int dist, val, destination, fuel, cur_loc = 0, result = 0;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> dist >> val;
		tmp.dist = dist;
		tmp.oil = val;
		pq2.push(tmp);
	}
	cin >> destination >> fuel;

	while (fuel < destination) {
		//보유한 연료로 갈 수 있는 주유소 다 넣는다
		while (!pq2.empty() && fuel >= pq2.top().dist) {
			tmp.dist = pq2.top().dist;
			tmp.oil = pq2.top().oil;
			pq.push(tmp);
			pq2.pop();
		}
		if (pq.empty()) {
			result = -1;
			break;
		}
		int supp = pq.top().oil;
		pq.pop();
		cur_loc = fuel;
		fuel += supp;
		result++;
	}
	cout << result;
	system("pause");
	return 0;
}