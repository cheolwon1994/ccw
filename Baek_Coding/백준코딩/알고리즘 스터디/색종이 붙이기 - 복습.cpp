#include <iostream>
#include <algorithm>
using namespace std;
int arr[10][10];
int avail[10][10];		//해당 칸에 가능한 최대 크기의 색종이
bool check[10][10] = { false, };
int paper[6] = { 0,5,5,5,5,5 };
int result = 30;

bool test(int y, int x, int len) {
	for (int i = y; i < y + len; i++)
		for (int j = x; j < x + len; j++)
			if (arr[i][j] != 1 || check[i][j])
				return false;
	return true;
}

void color(bool flag, int y, int x, int len) {
	for (int i = y; i < y + len; i++)
		for (int j = x; j < x + len; j++)
			check[i][j] = flag;
}

void dfs(int y, int x) {
	if (x == 10) {
		y += 1;
		x = 0;
	}
	if (y == 10) {
		bool finish = true;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++)
				if (arr[i][j] == 1 && !check[i][j]) {
					finish = false;
					break;
				}
			if (!finish) break;
		}
		if (finish) 
			result = min(result, 25 - (paper[1] + paper[2] + paper[3] + paper[4] + paper[5]));
		return;
	}
	if (arr[y][x] == 0 || (arr[y][x]==1 && check[y][x])) dfs(y, x + 1);
	else {
		int len = avail[y][x];
		bool can = false;
		for (int k = len; k > 0; k--) {
			if (paper[k] == 0) continue;
			if (test(y, x, k)) {
				can = true;
				paper[k]--;
				color(true, y, x, k);
				dfs(y, x + k);
				paper[k]++;
				color(false, y, x, k);
			}
		}
		if (!can) return;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			cin >> arr[i][j];
	for (int i = 0; i < 10; i++) 
		for (int j = 0; j < 10; j++)
			if (arr[i][j] == 1) {
				int cnt = 5;
				int maxi = min(10 - j, 10 - i);
				cnt = min(maxi, cnt);
				while (cnt > 1) {
					bool fin = true;
					for (int k = i; k < i + cnt; k++) {
						for (int m = j; m < j + cnt; m++)
							if (arr[k][m] != 1) {
								fin = false;
								break;
							}
						if (!fin) break;
					}
					if (fin) break;
					else cnt--;
				}
				avail[i][j] = cnt;
			}
	dfs(0, 0);
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			if (arr[i][j] == 1 && !check[i][j]) {
				int len = avail[i][j];
				for (int k = len; k > 0; k--) {
					if (paper[k] == 0) continue;
					if (test(i, j, k)) {
						color(true, i, j, k);

					}
				}
			}
	if (result == 30) result = -1;
	cout << result;
	return 0;
}