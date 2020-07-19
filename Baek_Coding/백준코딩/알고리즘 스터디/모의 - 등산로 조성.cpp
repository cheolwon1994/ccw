#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct info {
	int x, y;
};
info tmp;
int arr[8][8], num, k, result;
bool check[8][8];
vector<info> v;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

void dfs(int y, int x, int height, int len, bool dig) {
	result = max(result, len);
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < num && ny < num && !check[ny][nx]) {
			if (arr[ny][nx] < height) {
				check[ny][nx] = true;
				dfs(ny, nx, arr[ny][nx], len + 1, dig);
				check[ny][nx] = false;
			}
			else if (!dig && height > arr[ny][nx] - k) {
				for (int j = 1; j <= k; j++) {
					if (height > arr[ny][nx] - j) {
						check[ny][nx] = true;
						dfs(ny, nx, arr[ny][nx] - j, len + 1, true);
						check[ny][nx] = false;
					}
				}
			}
		}
	}
}

int main() {
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		cin >> num >> k;
		//√ ±‚»≠
		v.clear();
		result = 1;
		int maxi = -1;

		for (int i = 0; i < num; i++)
			for (int j = 0; j < num; j++) {
				cin >> arr[i][j];
				maxi = max(maxi, arr[i][j]);
			}
		for (int i = 0; i < num; i++)
			for (int j = 0; j < num; j++)
				if (arr[i][j] == maxi) {
					tmp.x = j;
					tmp.y = i;
					v.push_back(tmp);
				}
		for (int i = 0; i < v.size(); i++) {
			for (int j = 0; j < num; j++)
				for (int m = 0; m < num; m++)
					check[j][m] = false;
			check[v[i].y][v[i].x] = true;
			dfs(v[i].y, v[i].x, maxi, 1, false);
		}	
		cout << "#" << t << " " << result << '\n';
	}
	return 0;
}