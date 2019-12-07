#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;
int check[20001];
int test, point, edge;
int a, b, cv;

int main() {
	cin >> test;
	for (int t = 0; t < test; t++) {
		memset(check, 0, sizeof(check));
		vector<int> v[20001];
		cin >> point >> edge;
		for (int i = 0; i < edge; i++) {
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		queue<int> q;
		bool flag = true;
		for (int i = 1; i <= point; i++) {
			if (check[i] == 0) {
				q.push(i);
				check[i] = 1;
				while (!q.empty()) {
					int qs = q.size();
					for (int k = 0; k < qs; k++) {
						cv = q.front();
						q.pop();
						for (int j = 0; j < v[cv].size(); j++) {
							if (check[v[cv][j]] == check[cv]) {
								flag = false;
								break;
							}
							else if (check[v[cv][j]] == 0) {
								check[v[cv][j]] = 3 - check[cv];
								q.push(v[cv][j]);
							}
							else if (check[v[cv][j]] != 3 - check[cv]) {
								flag = false;
								break;
							}
						}
						if (!flag)
							break;
					}
					if (!flag)
						break;
				}
				if (!flag)
					break;
			}
		}
		if (!flag)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
	system("pause");
	return 0;
}