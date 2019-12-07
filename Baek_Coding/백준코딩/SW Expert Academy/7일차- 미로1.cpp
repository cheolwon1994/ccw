#define _CRT_SEUCRE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <string.h>
using namespace std;
int arr[16][16];
int check[16][16];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int num;
int result;
string str;
struct info {
	int x;
	int y;
};
info tmp;
queue<info> q;

void bfs() {
	int cx, cy, nx, ny;
	int flag = 0;
	while (!q.empty()) {
		cx = q.front().x;
		cy = q.front().y;
		q.pop();
		for (int i = 0; i < 4; i++) {
			nx = cx + dx[i];
			ny = cy + dy[i];
			if (nx >= 0 && ny >= 0 && nx < 16 && ny < 16 && check[ny][nx]!=1) {
				if (arr[ny][nx] == 3) {
					check[ny][nx] = 1;
					flag = 1;
					break;
				}
				if (arr[ny][nx] == 0) {
					check[ny][nx] = 1;
					tmp.y = ny;
					tmp.x = nx;
					q.push(tmp);
				}
			}
		}
		if (flag == 1)
			break;
	}
	if (flag == 1)
		result = 1;
}
int main() {
	for (int t = 1; t < 11; t++) {
		cin >> num;
		for (int i = 0; i < 16; i++) {
			memset(check[i], 0, sizeof(check[i]));
			memset(arr[i], 0, sizeof(arr[i]));
		}
		result = 0;
		for (int i = 0; i < 16; i++) {
			cin >> str;
			for (int j = 0; j < 16; j++) {
				arr[i][j] = str[j] - '0';
				if (arr[i][j] == 2) {
					tmp.y = i;
					tmp.x = j;
					q.push(tmp);
				}
			}
		}
		bfs();
		cout << "#" << t << " " << result << endl;
		while (!q.empty())
			q.pop();
	}

	system("pause");
	return 0;
}