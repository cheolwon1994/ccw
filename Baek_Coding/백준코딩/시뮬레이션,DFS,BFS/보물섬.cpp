#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;
char arr[50][50];
int check[50][50];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int row, col;
struct info {
	int x;
	int y;
	int val;
};
info tmp;
int dist = 0;
int result = 0;
vector<info> v;
int main() {
	string str;
	int cx, cy, cv, nx, ny;
	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		cin >> str;
		for (int j = 0; j < col; j++) {
			arr[i][j] = str[j];
			if (arr[i][j] == 'L') {
				tmp.x = j;
				tmp.y = i;
				tmp.val = 0;
				v.push_back(tmp);
			}
		}
	}
	for (int i = 0; i < v.size(); i++) {
		queue<info> q;
		dist = 0;
		for (int j = 0; j < row; j++)
			memset(check[j], 0, sizeof(check[j]));
		tmp.x = v[i].x;
		tmp.y = v[i].y;
		tmp.val = 0;
		q.push(tmp);
		while (!q.empty()) {
			cx = q.front().x;
			cy = q.front().y;
			cv = q.front().val;
			q.pop();
			for (int j = 0; j < 4; j++) {
				nx = cx + dx[j];
				ny = cy + dy[j];
				if (nx >= 0 && ny >= 0 && nx < col && ny < row && check[ny][nx] != 1) {
					if (arr[ny][nx] == 'L') {
						tmp.x = nx;
						tmp.y = ny;
						tmp.val = cv + 1;
						q.push(tmp);
						check[ny][nx] = 1;
						dist = max(dist, cv + 1);
					}
				}
			}
		}
		result = max(result, dist);
	}
	cout << result;
	system("pause");
	return 0;
}