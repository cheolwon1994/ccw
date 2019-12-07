#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
#include <deque>
using namespace std;
int arr[101][101];
int row, apple, go;
struct info {
	int time;
	char dir;
};
struct snake {
	int x;
	int y;
};
info tmp;
queue<info> mv;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
deque<snake> dq;
snake s;
int result = 0;

void start(int dir) {
	if (!mv.empty()) {
		if (mv.front().time == result) {
			if (mv.front().dir == 'D')
				dir = (dir + 1) % 4;
			else
				dir = (dir + 3) % 4;
			mv.pop();
		}
	}
	int cx, cy, nx, ny;
	cx = dq.front().x;
	cy = dq.front().y;
	nx = cx + dx[dir];
	ny = cy + dy[dir];
	if (nx <= 0 || ny <= 0 || nx > row || ny > row) {
		result += 1;
		return;
	}
	else {
		int tx, ty;
		bool flag = false;
		for (int i = 0; i < dq.size(); i++) {
			tx = dq[i].x;
			ty = dq[i].y;
			if(tx==nx && ty ==ny){
				flag = true;
				break;
			}
		}
		if (flag) {
			result += 1;
			return;
		}
		else {
			s.x = nx;
			s.y = ny;
			dq.push_front(s);
			if (arr[ny][nx] != 1)
				dq.pop_back();
			else if (arr[ny][nx] == 1)
				arr[ny][nx] = 0;
			result += 1;
			start(dir);
		}
	}
}

int main() {
	cin >> row >> apple;
	int x, y;
	for (int i = 0; i < row; i++)
		memset(arr[i], 0, sizeof(arr[i]));
	for (int i = 0; i < apple; i++) {
		cin >> y >> x;
		arr[y][x] = 1;
	}
	cin >> go;
	char c;
	for (int i = 0; i < go; i++) {
		cin >> x >> c;
		tmp.time = x;
		tmp.dir = c;
		mv.push(tmp);
	}
	s.x = 1;
	s.y = 1;
	dq.push_back(s);
	start(1);
	cout << result;
	system("pause");
	return 0;
}