#define MAX 90001
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int num, result;
int arr[100][100];
int check[100][100];
struct info {
	int x, y;
};
info tmp;
void bfs() {
	queue<info> q;
	tmp.x = 0;
	tmp.y = 0;
	q.push(tmp);
	int cx, cy, cv, nx, ny;
	while (!q.empty()) {
		cx = q.front().x;
		cy = q.front().y;
		cv = check[cy][cx];
		q.pop();
		if (cy == num - 1 && cx == num - 1) 
			continue;		
		for (int i = 0; i < 4; i++) {
			nx = cx + dx[i];
			ny = cy + dy[i];
			if (nx >= 0 && ny >= 0 && nx < num && ny < num) {
				if (check[ny][nx] > check[cy][cx] + arr[ny][nx]) {
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
	string str;
	int test;
	cin >> test;
	for (int t = 1; t <= 10; t++) {
		cin >> num;
		for (int i = 0; i < num; i++) {
			cin >> str;
			for (int j = 0; j < num; j++)
				arr[i][j] = str[j] - '0';
		}
		//ÃÊ±âÈ­
		for (int i = 0; i < num; i++)
			for (int j = 0; j < num; j++)
				check[i][j] = MAX;
		result = 0;
		check[0][0] = 0;

		bfs();
		cout << "#" << t << " " << check[num-1][num-1] << endl;
	}
	system("pause");
	return 0;
}