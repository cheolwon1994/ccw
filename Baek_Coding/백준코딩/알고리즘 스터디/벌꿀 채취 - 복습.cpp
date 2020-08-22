#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct info {
	int r, c, val;
};
struct cmp {
	bool operator()(info& a, info& b) {
		return a.val < b.val;
	}
};
info tmp;
int num, result, c, con, maxi;
int arr[10][10];
bool check[10][10];
priority_queue<info, vector<info>, cmp> pq;

void dfs(int y, int x, int max_x, int sum, int cal) {
	if (x == max_x || x == num) {		//최대 범위를 벗어난 경우
		maxi = max(maxi, cal);
		return;
	}
	if (arr[y][x] + sum <= c)			//채취한 경우
		dfs(y, x + 1, max_x, arr[y][x] + sum, cal + arr[y][x] * arr[y][x]);
	dfs(y, x + 1, max_x, sum, cal);		//채취 안한 경우
}

int main() {
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		cin >> num >> con >> c;
		for (int i = 0; i < num; i++) 
			for (int j = 0; j < num; j++) {
				cin >> arr[i][j];
				check[i][j] = false;
			}
		//초기화
		while (!pq.empty())
			pq.pop();
		result = 0;

		for (int i = 0; i < num; i++)
			for (int j = 0; j <= num - con; j++) {
				maxi = 0;
				dfs(i, j, j + con, 0, 0);
				tmp.c = j;
				tmp.r = i;
				tmp.val = maxi;
				pq.push(tmp);
			}
		int remain = 0;
		while (!pq.empty()) {
			int cx = pq.top().c;
			int cy = pq.top().r;
			int cv = pq.top().val;
			pq.pop();
			bool avail = true;
			for (int i = cx; i < min(cx + con, num); i++) {
				if (check[cy][i]) {
					avail = false;
					break;
				}
			}
			if (avail) {
				result += cv;
				remain++;
				for (int i = cx; i < min(cx + con, num); i++) 
					check[cy][i] = true;									
			}
			if (remain == 2) break;
		}
		cout << "#" << t << " " << result << '\n';
	}
	return 0;
}