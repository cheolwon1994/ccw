#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	int num, val;
	long long result = 0;
	cin >> num;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < num; i++) {
		cin >> val;
		pq.push(val);
	}
	while (pq.size() > 1) {
		int a = pq.top();
		pq.pop();
		a+= pq.top();
		pq.pop();
		result += a;
		pq.push(a);
	}
	cout << result;
	system("pause");
	return 0;
}