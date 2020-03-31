#include <iostream>
using namespace std;
char arr[500][500];
int visit[500][500];		//-1: 방문 x, 0: 못나간다, 1: 나간다
int row, col, result = 0;

int dfs(int y, int x) {
	if (visit[y][x] != -1) return visit[y][x];		//나가거나 나가지 못하는 경우
	char c = arr[y][x];
	int temp = 0;
	visit[y][x] = 0;
	if (c == 'U') {
		if (y == 0) 	temp = 1;
		else	temp = dfs(y - 1, x);
	}
	else if (c == 'D') {
		if (y == row - 1) 	temp = 1;		
		else	temp = dfs(y + 1, x);
	}
	else if (c == 'L') {
		if (x == 0) temp = 1;		
		else	temp = dfs(y, x - 1);
	}
	else if (c == 'R') {
		if (x == col - 1) 	temp = 1;		
		else	temp = dfs(y, x + 1);
	}
	visit[y][x] = temp;
	return temp;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> row >> col;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) {
			cin >> arr[i][j];
			visit[i][j] = -1;
		}

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) 
			if (visit[i][j] == -1) 
				dfs(i, j);

	for (int i = 0; i < row; i++) 
		for (int j = 0; j < col; j++)
			if (visit[i][j] == 1)
				result++;
	cout << result;
	system("pause");
	return 0;
}