#define MAX 987654321
#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
int row, col, result, clear_num, sx, sy;
char arr[20][20];
int RtoDust[10];
int DDdist[10][10];
bool flag[10];
bool no_finish;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
struct info {
	int x, y, val;
};
info tmp;
vector<info> dust;
vector<int> order;

int cal_dist(int f, int s) {
	bool check[20][20] = { false, };
	int cx, cy, cv, nx, ny, tx, ty, t_result = -1;
	tx = dust[s].x;
	ty = dust[s].y;
	queue<info> q;
	if (f == -1) {
		tmp.x = sx;
		tmp.y = sy;
	}
	else {
		tmp.x = dust[f].x;
		tmp.y = dust[f].y;
	}
	tmp.val = 0;
	q.push(tmp);
	check[tmp.y][tmp.x] = true;
	while (!q.empty()) {
		cx = q.front().x;
		cy = q.front().y;
		cv = q.front().val;
		q.pop();
		if (cx == tx && cy == ty) {
			t_result = cv;
			break;
		}
		for (int i = 0; i < 4; i++) {
			nx = cx + dx[i];
			ny = cy + dy[i];
			if (nx >= 0 && ny >= 0 && nx < col && ny < row && arr[ny][nx] != 'x' && !check[ny][nx]) {
				check[ny][nx] = true;
				tmp.x = nx;
				tmp.y = ny;
				tmp.val = cv + 1;
				q.push(tmp);
			}
		}
	}
	if (t_result == -1) {
		no_finish = true;
		return -1;
	}
	else 
		return t_result;	
}

void dfs(int cnt) {
	if (cnt == dust.size()) {
		int sum = RtoDust[order[0]];
		for (int i = 0; i < cnt - 1; i++) 
			sum += DDdist[order[i]][order[i+1]];		
		result = min(result, sum);
		return;
	}
	for (int i = 0; i < dust.size(); i++) {
		if (!flag[i]) {
			flag[i] = true;
			order.push_back(i);
			dfs(cnt + 1);
			order.pop_back();
			flag[i] = false;
		}
	}
}

int main() {
	while (1) {
		cin >> col >> row;
		if (row == 0 && col == 0)
			break;
		//√ ±‚»≠
		result = MAX;
		order.clear();
		dust.clear();
		no_finish = false;
		memset(flag, false, sizeof(flag));
		memset(RtoDust, 0, sizeof(RtoDust));
		for (int i = 0; i < 10; i++)
			memset(DDdist[i], 0, sizeof(DDdist[i]));

		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++) {
				cin >> arr[i][j];
				if (arr[i][j] == 'o') {
					sx = j;
					sy = i;
					arr[i][j] = '.';			
				}
				else if (arr[i][j] == '*') {
					tmp.x = j;
					tmp.y = i;
					dust.push_back(tmp);
				}
			}
		for (int i = 0; i < dust.size(); i++) {
			for (int j = i + 1; j < dust.size(); j++) {
				int tt = cal_dist(i,j);
				if (tt == -1)
					break;
				DDdist[i][j] = tt;
				DDdist[j][i] = tt;
			}
			if (no_finish)
				break;
		}

		if(!no_finish){
			for (int i = 0; i < dust.size(); i++) {
				int tt = cal_dist(-1, i);
				if (tt == -1)
					break;
				RtoDust[i] = tt;
			}
			dfs(0);
			if (!no_finish)				
				cout << result << endl;
		}
		if (no_finish) 	cout << -1 << endl;
	}
	system("pause");
	return 0;
}