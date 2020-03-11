#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
bool erased[50] = { false, };
vector<int> v[50];
int main() {
	int num, tt, target;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> tt;
		if (tt == -1) continue;
		v[tt].push_back(i);
	}
	cin >> target;
	//해당 Node와 그 밑의 Node들의 erased값을 true로 바꾼다
	queue<int> q;
	q.push(target);
	erased[target] = true;
	while (!q.empty()) {
		int cidx = q.front();
		q.pop();
		for (int i = 0; i < v[cidx].size(); i++) {
			int next = v[cidx][i];
			if (!erased[next]) {
				q.push(next);
				erased[next] = true;
			}
		}
	}
	int result = 0;
	for (int i = 0; i < num; i++) {
		bool leaf = true;
		if (!erased[i]) {
			int cnt = 0;
			for (int j = 0; j < v[i].size(); j++) {
				if (erased[v[i][j]]) cnt++;
			}
			if (cnt == v[i].size())
				result++;
		}
	}
	cout << result;
	system("pause");
	return 0;
}