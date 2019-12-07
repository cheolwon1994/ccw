#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int check[1001];
int num, node;
int a, b;
int result = 0;
queue<int> q;
vector<int> v[1001];
int main() {
	cin >> num >> node;
	for (int i = 0; i < node; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int cx;
	for (int i = 1; i <= num; i++) {
		if (check[i] != 1) {
			q.push(i);
			check[i] = 1;
			while (!q.empty()) {
				cx = q.front();
				q.pop();
				for (int j = 0; j < v[cx].size(); j++) {
					if (check[v[cx][j]] != 1) {
						check[v[cx][j]] = 1;
						q.push(v[cx][j]);
					}
				}
			}
			result++;
		}
	}
	cout << result;
	system("pause");
	return 0;
}