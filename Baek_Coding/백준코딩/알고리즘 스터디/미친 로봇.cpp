#include <iostream>
using namespace std;
int num;
double result = 0;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
double percent[4];
bool check[30][30] = { false, };

void dfs(int y, int x, int idx, long double prob) {
	if (idx == num) {
		result += prob;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (!check[y + dy[i]][x + dx[i]]) {
			check[y + dy[i]][x + dx[i]] = true;
			dfs(y+dy[i], x+dx[i], idx + 1,prob*percent[i]);
			check[y+dy[i]][x+dx[i]] = false;
		}
	}
}

int main() {
	cin >> num;
	int tt;
	for (int i = 0; i < 4; i++) {
		cin >> tt;
		percent[i] = (double)tt / 100;
	}
	check[14][14] = true;
	dfs(14,14,0,1);
	cout.precision(11); cout << fixed;
	cout << result;
	system("pause");
	return 0;
}