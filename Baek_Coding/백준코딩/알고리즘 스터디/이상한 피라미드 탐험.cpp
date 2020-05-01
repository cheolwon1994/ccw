#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
struct info {
	int x, y;
};
info tmp;
int dx[6] = { 1,2,1,-1,-2,-1 };
int dy[6] = { -1,0,1,1,0,-1 };
int start, target, result;
int check[10001];
int arr[300][300];
int numx[10001];
int numy[10001];
void bfs() {
	queue<info> q;
	tmp.x = numx[start];
	tmp.y = numy[start];
	q.push(tmp);
	check[start] = 0;
	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		q.pop();
		if (arr[cy][cx] == target) {
			result = check[arr[cy][cx]];
			break;
		}
		for (int i = 0; i < 6; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && ny >= 0 && nx < 300 && ny < 300 && arr[ny][nx] != 0 && check[arr[ny][nx]] == -1) {
				check[arr[ny][nx]] = check[arr[cy][cx]] + 1;
				tmp.x = nx;
				tmp.y = ny;
				q.push(tmp);
			}
		}
	}
}

void make_arr() {
	int num = 1;
	bool finish = false;
	for (int k = 1;; k++) {
		for (int i = 0; i < 300; i++) {
			for (int j = 150 - i; j <= 150 + i; j += 2) {
				arr[i][j] = num;
				numx[num] = j;
				numy[num] = i;
				num++;
				if (num > 10000) {
					finish = true;
					break;
				}
			}
			if (finish) break;
		}
		if (finish) break;
	}
}

int main() {
	int test;
	cin >> test;
	make_arr();
	for (int t = 1; t <= test; t++) {
		cin >> start >> target;
		int maxi = max(start, target);
		for (int i = 1; i <= maxi; i++)
			check[i] = -1;
		bfs();
		cout << "#" << t << " " << result << '\n';
	}
	system("pause");
	return 0;
}