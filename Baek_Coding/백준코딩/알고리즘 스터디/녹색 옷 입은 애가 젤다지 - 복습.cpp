#define MAX 987654321
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
struct info {
	int x, y, val;
};
struct cmp {
	bool operator()(info &a, info &b) {
		return a.val > b.val;
	}
};
info tmp;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int num;
int arr[125][125];
int check[125][125];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int cnt = 1;
	while (1) {
		cin >> num;
		if (num == 0) break;
		for (int i = 0; i < num; i++)
			for (int j = 0; j < num; j++) {
				cin >> arr[i][j];
				check[i][j] = MAX;
			}
		priority_queue<info, vector<info>, cmp> pq;
		check[0][0] = arr[0][0];
		tmp.val = arr[0][0];
		tmp.x = 0;
		tmp.y = 0;
		pq.push(tmp);
		while (!pq.empty()) {
			int cx = pq.top().x;
			int cy = pq.top().y;
			int cv = pq.top().val;
			pq.pop();
			if (cx == num - 1 && cy == num - 1) {
				cout << "Problem " << cnt++ << ": " << check[cy][cx] << '\n';
				break;
			}
			for (int i = 0; i < 4; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if (nx >= 0 && ny >= 0 && nx < num && ny<num && check[ny][nx]>arr[ny][nx] + cv) {
					check[ny][nx] = arr[ny][nx] + cv;
					tmp.x = nx;
					tmp.y = ny;
					tmp.val = arr[ny][nx] + cv;
					pq.push(tmp);
				}
			}
		}
	}
	return 0;
}