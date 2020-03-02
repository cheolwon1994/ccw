#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;
char arr[50][50];
bool check[50][50];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int row, col;
struct info {
	int x, y, val;
};
info tmp;
int result = 0;
vector<info> v;
int main() {
	string str;
	int cx, cy, cv, nx, ny;
	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> arr[i][j];
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
		for (int k = 0; k < row; k++)
			for (int j = 0; j < col; j++)
				check[k][j] = false;
		tmp.x = v[i].x;
		tmp.y = v[i].y;
		tmp.val = 0;
		check[tmp.y][tmp.x] = true;
		q.push(tmp);
		int t_result = 0;
		while (!q.empty()) {
			cx = q.front().x;
			cy = q.front().y;
			cv = q.front().val;
			q.pop();
			t_result = max(t_result, cv);
			for (int j = 0; j < 4; j++) {
				nx = cx + dx[j];
				ny = cy + dy[j];
				if (nx >= 0 && ny >= 0 && nx < col && ny < row && !check[ny][nx] && arr[ny][nx]=='L') {
					tmp.x = nx;
					tmp.y = ny;
					tmp.val = cv + 1;
					q.push(tmp);
					check[ny][nx] = true;					
				}
			}
		}
		result = max(result, t_result);
	}
	cout << result;
	system("pause");
	return 0;
}