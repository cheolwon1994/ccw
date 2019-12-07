#define CRT_NO_SECURE_WARNINGS
#define MAX 987654321
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <queue>

using namespace std;
int result = MAX;
int temp;
int arr[101][101];
int check[101][101];

struct info {
	int x;
	int y;
};
info tmp;
queue<info> q;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

void bfs() {
	int nx, ny, cx, cy;
	while (!q.empty()) {
		cx = q.front().x;
		cy = q.front().y;
		q.pop();
		for (int i = 0; i < 4; i++) {
			nx = cx + dx[i];
			ny = cy + dy[i];
			if (nx > 0 && ny > 0 && nx <= temp && ny <= temp) {
				if (check[ny][nx] != -1) {
					if (check[ny][nx] < check[cy][cx] + arr[ny][nx])
						continue;
					else if (check[ny][nx] > check[cy][cx] + arr[ny][nx]) {
						check[ny][nx] = check[cy][cx] + arr[ny][nx];
						tmp.x = nx;
						tmp.y = ny;
						q.push(tmp);
					}
				}
				else {
					check[ny][nx] = check[cy][cx] + arr[ny][nx];
					tmp.x = nx;
					tmp.y = ny;
					q.push(tmp);
				}
			}
		}
	}
}

int main() {
	int test;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		result = MAX;
		for (int j = 0; j < 101; j++)
			memset(check[j], -1, sizeof(check[j]));
		cin >> temp;
		string str;
		for (int j = 1; j <= temp; j++) {
			cin >> str;
			for (int k = 0; k < temp; k++)
				arr[j][k + 1] = str[k] - '0';
		}
		tmp.x = 1;
		tmp.y = 1;
		q.push(tmp);
		check[1][1] = 0;
		bfs();
		cout << "#" << i << " " << check[temp][temp] << endl;
	}
	system("PAUSE");
	return 0;
}