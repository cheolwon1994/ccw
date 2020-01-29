#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int>> a;
priority_queue<int, vector<int>, less<int>> b;
int main() {
	int num,tt;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> tt;
		a.push(tt);
	}
	for (int i = 0; i < num; i++) {
		cin >> tt;
		b.push(tt);
	}
	int result = 0;
	while (!a.empty() && !b.empty()) {
		result += a.top()*b.top();
		a.pop(); b.pop();
	}
	cout << result;
	system("pause");
	return 0;
}