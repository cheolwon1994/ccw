#include <iostream>
using namespace std;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int arr[52][52], num, mirror;

void dfs(int y, int x, int dir) {
	if (y == 0 || x == 0 || y == num + 1 || x == num + 1) {
		cout << y << " " << x << '\n';
		return;
	}
	if (arr[y][x] == 1) {		//°Å¿ï
		int nd = (dir + 1) % 4;
		dfs(y + dy[nd], x + dx[nd], nd);
	}
	else dfs(y + dy[dir], x + dx[dir], dir);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int test, x, y, dir;
	cin >> test;
	for (int t = 0; t < test; t++) {
		cin >> num >> mirror;
		for (int i = 0; i < num + 2; i++)
			for (int j = 0; j < num + 2; j++)
				arr[i][j] = 0;
		for (int i = 0; i < mirror; i++) {
			cin >> y >> x;
			arr[y][x] = 1;
		}
		cin >> y >> x;
		if (y == 0) dfs(y + 1, x, 2);
		else if (y == num + 1) dfs(y - 1, x, 0);
		else if (x == 0) dfs(y, x + 1, 1);
		else if (x == num + 1) dfs(y, x - 1, 3);		
	}
	system("pause");
	return 0;
}