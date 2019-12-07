#define CRT_NO_SECURE_WARNINGS
#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <string>
#include <string.h>

using namespace std;
int row, l, r;
int arr[51][51];
int dup[51][51];
int check[51][51];
int x[4] = { 0,1,0,-1 };
int y[4] = { -1,0,1,0 };
int result = 0;

struct info {
	int x;
	int y;
	int cnt;
};
info tmp;

//같은 구역을 찾아주고, 인구수 분할
void bfs(queue<info> q) {
	vector <info> v;
	int nx, ny, cx, cy, ct;
	while (!q.empty()) {
		cx = q.front().x;
		cy = q.front().y;
		ct = q.front().cnt;
		tmp.x = cx;
		tmp.y = cy;
		tmp.cnt = ct;
		v.push_back(tmp);
		q.pop();
		for (int i = 0; i < 4; i++) {
			nx = cx + x[i];
			ny = cy + y[i];
			if (nx >= 1 && ny >= 1 && nx <= row && ny <= row) {
				if (check[ny][nx] == -1) {		//안거쳐간 배열이어야 함
					int temp = abs(arr[ny][nx] - arr[cy][cx]);
					if (l <= temp && temp <= r) {
						tmp.x = nx;
						tmp.y = ny;
						tmp.cnt = ct;
						check[ny][nx] = ct;
						q.push(tmp);
					}
				}
			}
		}
	}
	int sum = 0;
	int pop = 0;
	for (int i = 0; i < v.size(); i++) 
		sum += arr[v[i].y][v[i].x];
	pop = sum / v.size();
	for (int i = 0; i < v.size(); i++)
		dup[v[i].y][v[i].x] = pop;
}

int available() {
	bool test = false;
	for (int i = 1; i <= row; i++)
		memset(check[i], -1, sizeof(check[i]));		//-1: 미확인, 0: 확인했지만 연결되는곳 x, 1이상: 같은 구역 존재
	for (int i = 1; i <= row; i++)
		memset(dup[i], -1, sizeof(dup[i]));
	int cnt = 1;
	int nx, ny;
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= row; j++) {
			bool test = false;
			if (check[i][j] == -1) {
				for (int k = 0; k < 4; k++) {
					nx = j + x[k];
					ny = i + y[k];
					if (nx >= 1 && ny >= 1 && nx <= row && ny <= row && check[i][j] == -1) {
						int temp = abs(arr[ny][nx] - arr[i][j]);
						if (l <= temp && temp <= r) {
							test = true;
							queue<info> q;
							tmp.x = j;
							tmp.y = i;
							tmp.cnt = cnt;
							q.push(tmp);
							check[i][j] = cnt;
							bfs(q);
							cnt++;
						}
					}
				}
				if (!test) {
					check[i][j] = 0;
					dup[i][j] = arr[i][j];
				}
			}
		}
	}
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= row; j++)
			arr[i][j] = dup[i][j];
	return cnt;
}
int main() {
	cin >> row >> l >> r;
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= row; j++)
			cin >> arr[i][j];
	int temp = 0;
	while (1) {
		 temp = available();
		 if (temp == 1)
			 break;
		 else
			 result += 1;
	}
	cout << result;
	system("PAUSE");
	return 0;
}