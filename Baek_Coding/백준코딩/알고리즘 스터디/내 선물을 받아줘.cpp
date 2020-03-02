#include <iostream>
#include <algorithm>
using namespace std;
int check[1001][1001];
char arr[1001][1001];
int row, col;

int dfs(int y, int x, int cnt) {
	if (check[y][x]) return check[y][x];
	check[y][x] = cnt;
	char c = arr[y][x];
	if (c == 'S') 	check[y][x] = dfs(y + 1, x, cnt);
	else if (c == 'W') check[y][x] = dfs(y, x - 1, cnt);
	else if (c == 'E') check[y][x] = dfs(y, x + 1, cnt);
	else check[y][x] = dfs(y - 1, x, cnt);
	return check[y][x];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> row >> col;
	int cnt = 0;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) 
			cin >> arr[i][j];
		
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) {
			if (check[i][j]==0) {
				check[i][j] = dfs(i, j, cnt + 1);
				cnt = max(cnt, check[i][j]);
			}
		}
	cout << cnt;
	system("pause");
	return 0;
}