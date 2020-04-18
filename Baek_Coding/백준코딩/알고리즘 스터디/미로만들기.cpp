#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;
struct info {
	int x, y, val;
};
info tmp;
int result = 3000, num, arr[50][50], check[50][50];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

int main() {
	cin >> num;
	string str;
	for (int i = 0; i < num; i++) {
		cin >> str;
		for (int j = 0; j < num; j++) {
			arr[i][j] = str[j] - '0';
			check[i][j] = 3000;
		}
	}
	queue<info> q;
	tmp.x = 0;
	tmp.y = 0;
	tmp.val = 0;
	q.push(tmp);
	check[0][0] = 0;
	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		int cv = q.front().val;
		q.pop();
		if (cx == num - 1 && cy == num - 1) {
			result = min(result, cv);
			continue;
		}
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && ny >= 0 && nx < num && ny < num) {
				if (arr[ny][nx] == 1 && check[ny][nx] > cv) {
					check[ny][nx] = cv;
					tmp.x = nx;
					tmp.y = ny;
					tmp.val = cv;
					q.push(tmp);
				}
				if (arr[ny][nx] == 0 && check[ny][nx] > cv + 1) {
					check[ny][nx] = cv + 1;
					tmp.x = nx;
					tmp.y = ny;
					tmp.val = cv + 1;
					q.push(tmp);
				}
			}
		}
	}
	cout << result;
	system("pause");
	return 0;
}