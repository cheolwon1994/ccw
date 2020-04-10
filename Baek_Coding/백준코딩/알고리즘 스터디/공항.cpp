#include <iostream>
using namespace std;
int par[100001];
bool finish = false;

int find_parent(int x) {
	if (par[x] == x) return x;
	return par[x] = find_parent(par[x]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int gate, airplane, val, cnt = 0;
	cin >> gate >> airplane;
	for (int i = 1; i <= gate; i++)
		par[i] = i;

	for (int i = 0; i < airplane; i++) {
		cin >> val;
		if (finish) continue;
		int idx = find_parent(val);		//집어 넣을 수 있는곳
		if (idx == 0) 
			finish = true;
		else {
			cnt++;
			par[idx] = idx - 1;
		}
	}
	cout << cnt;
	system("pause");
	return 0;
}