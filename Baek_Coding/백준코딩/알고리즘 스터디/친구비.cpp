#include <iostream>
using namespace std;
int par[10001], price[10001], node, relation, money;

int find_par(int x) {
	if (par[x] == x) return x;
	return par[x] = find_par(par[x]);
}

void make_union(int a, int b) {
	a = find_par(a);
	b = find_par(b);
	if (a != b) {
		if (price[a] > price[b]) par[a] = b;
		else par[b] = a;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> node >> relation >> money;
	for (int i = 1; i <= node; i++) {
		cin >> price[i];
		par[i] = i;
	}
	int a, b;
	price[0] = 987654321;
	for (int i = 0; i < relation; i++) {
		cin >> a >> b;
		make_union(a, b);
	}
	int result = 0;
	for (int i = 1; i <= node; i++) {
		int p = find_par(i);
		if (p != find_par(0)) {
			result += price[p];
			make_union(0, i);
		}
	}
	if (money >= result) cout << result;
	else cout << "Oh no";
	return 0;
}