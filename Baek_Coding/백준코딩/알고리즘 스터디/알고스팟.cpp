#define MAX 10000
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
struct info {
	int x, y;
};
info tmp;
int arr[100][100];
int check[100][100];
int row, col, cx, cy, nx, ny, cv;

int main() {
	cin >> col >> row;
	string str;
	for (int i = 0; i < row; i++) {
		cin >> str;
		for (int j = 0; j < col; j++)
			arr[i][j]=str[j]-'0';
	}
	for (int i = 0; i < row; i++)
		memset(check[i], MAX, sizeof(check[i]));
	queue<info> q;
	tmp.x = 0;
	tmp.y = 0;
	q.push(tmp);
	check[0][0] = 0;
	int result = MAX;
	while (!q.empty()) {
		cx = q.front().x;
		cy = q.front().y;
		cv = check[cy][cx];
		q.pop();
		if (cy == row - 1 && cx == col - 1) {
			result = min(result, cv);
			continue;
		}
		for (int i = 0; i < 4; i++) {
			nx = cx + dx[i];
			ny = cy + dy[i];
			if (nx >= 0 && ny >= 0 && nx < col && ny < row) {
				if (check[ny][nx] > cv + arr[ny][nx]) {
					check[ny][nx] = cv + arr[ny][nx];
					tmp.x = nx;
					tmp.y = ny;
					q.push(tmp);
				}
			}
		}
	}
	cout << result;
	system("pause");
	return 0;
}