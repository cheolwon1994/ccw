#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	int num;
	long long result = 0;
	cin >> num;
	for (int i = 0; i < num; i++) {
		int tt;
		cin >> tt;
		pq.push(tt);
	}
	while (!pq.empty()) {
		result += pq.top()*pq.size();
		pq.pop();
	}
	cout << result;
	system("pause");
	return 0;
}