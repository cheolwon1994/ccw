#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int arr[500][500], check[500][500], num;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

int dfs(int y, int x) {
	int &ret = check[y][x];
	if (check[y][x]) return ret;
	int temp = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < num && ny<num && arr[ny][nx]>arr[y][x]) {
			temp = max(temp, dfs(ny, nx));
		}
	}
	ret = temp + 1;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> num;
	for (int i = 0; i < num; i++)
		for (int j = 0; j < num; j++)
			cin >> arr[i][j];
	int result = 0;
	for (int i = 0; i < num; i++)
		for (int j = 0; j < num; j++)
			if (check[i][j] == 0) 
				dfs(i, j);				
	for (int i = 0; i < num; i++) 
		for (int j = 0; j < num; j++) 
			result = max(result, check[i][j]);	
	cout << result;
	return 0;
}