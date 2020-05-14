#include <iostream>
#include <algorithm>
using namespace std;
int par[20001];
int dist[20001];
int node;

int find_parent(int x) {
	if (par[x] == x) return x;
	int idx = find_parent(par[x]);
	dist[x] += dist[par[x]];
	return par[x] = idx;
}

void make_union(int a, int b) {
	dist[a] = abs(a - b) % 1000;
	par[a] = b;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int test, a, b;
	cin >> test;
	for (int t = 0; t < test; t++) {
		cin >> node;
		for (int i = 1; i <= node; i++) {
			par[i] = i;
			dist[i] = 0;
		}
		char c;
		while (1) {
			cin >> c;
			if (c == 'O') break;
			else if (c == 'E') {
				cin >> a;
				find_parent(a);
				cout << dist[a] << '\n';
			}
			else if (c == 'I') {
				cin >> a >> b;
				make_union(a, b);
			}
		}
	}
	system("pause");
	return 0;
}