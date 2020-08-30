#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int num, result, sx, sy;
int arr[20][20];
bool desert[101], check[20][20];

int dx[4] = { 1,1,-1,-1 };
int dy[4] = { -1,1,1,-1 };
int order[4][4] = { {1,0,3,2},{1,2,3,0},{2,1,0,3},{2,3,0,1} };

void dfs(int y, int x, int cnt, int dir, int d_idx) {
	int nx = x + dx[order[dir][d_idx]];
	int ny = y + dy[order[dir][d_idx]];
	//진행방향 그대로 진행
	if (nx >= 0 && ny >= 0 && nx < num && ny < num) {
		if (nx == sx && ny == sy) {
			result = max(result, cnt);
			return;
		}
		else if (!desert[arr[ny][nx]] && !check[ny][nx]) {
			check[ny][nx] = true;
			desert[arr[ny][nx]] = true;
			dfs(ny, nx, cnt + 1, dir, d_idx);
			check[ny][nx] = false;
			desert[arr[ny][nx]] = false;
		}
	}
	//꺽을 예정
	if (d_idx != 3) {
		nx = x + dx[order[dir][d_idx+1]];
		ny = y + dy[order[dir][d_idx+1]];
		if (nx >= 0 && ny >= 0 && nx < num && ny < num) {
			if (nx == sx && ny == sy) {
				result = max(result, cnt);
				return;
			}
			else if (!desert[arr[ny][nx]] && !check[ny][nx]) {
				check[ny][nx] = true;
				desert[arr[ny][nx]] = true;
				dfs(ny, nx, cnt + 1, dir, d_idx + 1);
				check[ny][nx] = false;
				desert[arr[ny][nx]] = false;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		//초기화
		result = -1;

		cin >> num;
		for (int i = 0; i < num; i++)
			for (int j = 0; j < num; j++)
				cin >> arr[i][j];
		for (int i = 0; i < num; i++) {
			for (int j = 0; j < num; j++) {
				if (i == num - 1) continue;
				if (j == 0 && j == num - 1) continue;
				for (int k = 1; k < 101; k++)
					desert[k] = false;
				for (int k = 0; k < 20; k++)
					for (int m = 0; m < 20; m++)
						check[k][m] = false;
				desert[arr[i][j]] = true;
				check[i][j] = true;
				sx = j;
				sy = i;
				for (int k = 0; k < 4; k++)
					dfs(i, j, 1, k, 0);
			}
		}
		cout << "#" << t << " " << result << '\n';
	}
	return 0;
}