#include <iostream>
#include <set>
#include <string>
using namespace std;
int num;
set<int> s;
int arr[4][4];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

void dfs(int y, int x, int len, int sum) {
	if (len == 7) {
		s.insert(sum);
		return;
	}
	int nx, ny;
	for (int i = 0; i < 4; i++) {
		nx = x + dx[i];
		ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < 4 && ny < 4)
			dfs(ny, nx, len + 1, 10 * sum + arr[ny][nx]);
	}
}

int main() {
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		s.clear();
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				cin >> arr[i][j];
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++) 
				dfs(i, j, 1, arr[i][j]);			
		cout << "#" << t << " " << s.size() << endl;
	}
	system("pause");
	return 0;
}