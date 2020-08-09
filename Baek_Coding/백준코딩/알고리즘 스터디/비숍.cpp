#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct info {
	int x, y;
};
info tmp;
int arr[10][10], num, result[2];
vector<info> v;

void dfs(int y, int x, char c, int sum) {
	if (x >= num) {
		y += 1;
		if (c == 'W') {
			if (y % 2 == 0) x = 0;
			else x = 1;
		}
		else {
			if (y % 2 == 0) x = 1;
			else x = 0;
		}
	}
	if (y == num) {
		if (c == 'W') result[0] = max(result[0], sum);
		else if (c == 'B') result[1] = max(result[1], sum);
		return;
	}
	if (arr[y][x] == 0) dfs(y, x + 2, c, sum);
	else {
		bool avail = true;
		for (int i = 0; i < v.size(); i++) {
			int cx = v[i].x;
			int cy = v[i].y;
			if ((cx - cy == x - y) || (cx + cy == x + y)) {
				avail = false;
				break;
			}
		}
		if (avail) {
			tmp.x = x;
			tmp.y = y;
			v.push_back(tmp);
			dfs(y, x + 2, c, sum + 1);
			v.pop_back();
		}
		dfs(y, x + 2, c, sum);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> num;
	for (int i = 0; i < num; i++) 
		for (int j = 0; j < num; j++)
			cin >> arr[i][j];
	dfs(0, 0, 'W', 0);
	v.clear();
	dfs(0, 1, 'B', 0);
	cout << result[0] + result[1];
	return 0;
}