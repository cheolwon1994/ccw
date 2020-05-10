#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int row, col, result = 0, cnt = 1;
char arr[1000][1000];
int check[1000][1000];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

int dfs(int y, int x) {
	if (check[y][x] != -1) return check[y][x];
	int ret = check[y][x];
	check[y][x] = cnt;
	int dir;
	if (arr[y][x] == 'U') dir = 0;
	else if (arr[y][x] == 'R') dir = 1;
	else if (arr[y][x] == 'D') dir = 2;
	else if (arr[y][x] == 'L') dir = 3;
	int nx = x + dx[dir];
	int ny = y + dy[dir];
	ret = dfs(ny, nx);
	check[y][x] = ret;
	return check[y][x];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> row >> col;
	for(int i=0;i<row;i++)
		for (int j = 0; j < col; j++) {
			cin >> arr[i][j];
			check[i][j] = -1;
		}
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) {
			if (check[i][j] == -1) {
				dfs(i, j);
				cnt++;
			}
		}
	set<int> s;
	for (int i = 0; i < row; i++) 
		for (int j = 0; j < col; j++) 
			s.insert(check[i][j]);			
	cout << s.size();
	system("pause");
	return 0;
}