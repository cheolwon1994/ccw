#define MAX 987654321
#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
int row, col;
char arr[1501][1501];
int check[1501][1501];

struct info {
	int x;
	int y;
};
info tmp;
queue<info> water;
vector<info> swan;
queue<info> ice;
queue<info> q;
bool flag = true;
int day = 0;
int cx, cy, nx, ny;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };


void melt_ice() {
	int len = water.size();
	while (len--) {
		cx = water.front().x;
		cy = water.front().y;
		water.pop();				
		for (int i = 0; i < 4; i++) {
			nx = cx + dx[i];
			ny = cy + dy[i];
			if (ny > 0 && nx > 0 && nx <= col && ny <= row && arr[ny][nx] == 'X') {
				arr[ny][nx] = '.';
				tmp.x = nx;
				tmp.y = ny;
				water.push(tmp);
			}
		}
	}
}

void move_Swan() {			//백조 움직여보기
	int fx = swan[1].x;
	int fy = swan[1].y;
	tmp.x = swan[0].x;
	tmp.y = swan[0].y;
	q.push(tmp);
	check[tmp.y][tmp.x] = 1;
	while (!q.empty()) {
		cx = q.front().x;
		cy = q.front().y;
		q.pop();
		if (cx == fx && cy == fy) {
			flag = false;
			break;
		}
		else {
			for (int i = 0; i < 4; i++) {
				nx = cx + dx[i];
				ny = cy + dy[i];
				if (nx > 0 && ny > 0 && nx <= col && ny <= row && check[ny][nx]!=1){
					check[ny][nx] = 1;
					if (arr[ny][nx] == 'X') {
						tmp.x = nx;
						tmp.y = ny;
						ice.push(tmp);
						continue;
					}
					tmp.x = nx;
					tmp.y = ny;
					q.push(tmp);
				}
			}
		}
	}
}

int main() {
	cin >> row >> col;
	for(int i=1;i<=row;i++)
		for (int j = 1; j <= col; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == '.' || arr[i][j] == 'L') {
				tmp.x = j;
				tmp.y = i;
				water.push(tmp);
			}
			if (arr[i][j] == 'L') {
				tmp.x = j;
				tmp.y = i;
				swan.push_back(tmp);
			}
		}
	while (flag) {
		move_Swan();
		if (!flag)
			break;
		q = ice;
		while (!ice.empty())
			ice.pop();
		melt_ice();
		day++;
	}
	cout << day;
	system("pause");
	return 0;
}