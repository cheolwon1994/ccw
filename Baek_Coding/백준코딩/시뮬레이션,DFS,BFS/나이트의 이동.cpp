#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
int dx[8] = { 1,2,2,1,-1,-2,-2,-1 };
int dy[8] = { -2,-1,1,2,2,1,-1,-2 };
struct info {
	int y;
	int x;
	int val;
};
int test, num, x, y, dest_x, dest_y, cx, cy, cv, nx, ny;
int arr[300][300];
int check[300][300];
int result = 0;

int main() {
	cin >> test;
	for (int t = 0; t < test; t++) {
		cin >> num;
		for (int i = 0; i < num; i++)
			memset(check[i], 0, sizeof(check[i]));
		queue<info> q;
		cin >> y >> x >> dest_y >> dest_x;
		q.push({ y,x,0 });
		check[y][x] = 1;
		while (!q.empty()) {
			cx = q.front().x;
			cy = q.front().y;
			cv = q.front().val;
			q.pop();
			if (cx == dest_x && cy == dest_y) {
				result = cv;
				break;
			}
			for (int i = 0; i < 8; i++) {
				nx = cx + dx[i];
				ny = cy + dy[i];
				if (nx >= 0 && ny >= 0 && nx < num && ny < num && check[ny][nx]!=1) {
					check[ny][nx] = 1;
					q.push({ ny,nx,cv + 1 });
				}
			}
		}
		cout << result << endl;
	}
	system("pause");
	return 0;
}