#define MAX 987654321
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
int row, col;
char arr[20][20];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
struct info {
	int x, y;
};
info tmp;
int cx, cy, nx, ny, rx, ry, cv;
vector<info> dust;
int result;
int order[10];
int test[10];
int RDdist[10];
int dust_dist[20][20];
bool noReach;

void dfs(int num) {
	if (num == dust.size()) {
		int pre_result = RDdist[order[0]];
		for (int i = 0; i < num - 1; i++)
			pre_result += dust_dist[order[i]][order[i + 1]];
		result = min(result, pre_result);
		return;
	}
	for (int i = 0; i < dust.size(); i++) {
		if (test[i] != 1) {
			test[i] = 1;
			order[num] = i;
			dfs(num + 1);
			order[num] = -1;
			test[i] = 0;
		}
	}
}

int calRD(int start, int num) {
	queue<info> q;
	int check[20][20] = { 0, };
	if (start == -1) {
		tmp.x = rx;
		tmp.y = ry;
		q.push(tmp);
	}
	else {
		tmp.x = dust[start].x;
		tmp.y = dust[start].y;
		q.push(tmp);
	}
	int found = 0;
	while (!q.empty()) {
		cx = q.front().x;
		cy = q.front().y;
		q.pop();
		for (int i = 0; i < 4; i++) {
			nx = cx + dx[i];
			ny = cy + dy[i];
			if (nx >= 0 && ny >= 0 && nx < col && ny < row && arr[ny][nx] != 'x' && check[ny][nx]==0) {
				if (ny == dust[num].y && nx == dust[num].x) {
					found = check[cy][cx] + 1;
					break;
				}
				if (arr[ny][nx] == '.' || arr[ny][nx]=='o' || arr[ny][nx]=='*') {
					check[ny][nx] = check[cy][cx] + 1;
					tmp.y = ny;
					tmp.x = nx;
					q.push(tmp);
				}
			}
		}
		if (found)
			break;
	}
	return found;
}

int main() {
	while (1) {
		cin >> col >> row;
		for (int i = 0; i < row; i++)
			memset(dust_dist[i], 0, sizeof(dust_dist[i]));
		memset(order, -1, sizeof(order));
		memset(RDdist, 0, sizeof(RDdist));
		memset(test, 0, sizeof(test));
		dust.clear();
		result = MAX;
		noReach = false;
		if (col == 0 && row == 0)
			break;
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++) {
				cin >> arr[i][j];
				if (arr[i][j] == 'o') {
					rx = j;
					ry = i;
				}
				else if (arr[i][j] == '*') {
					tmp.x = j;
					tmp.y = i;
					dust.push_back(tmp);
				}
			}
		int dist;
		for (int i = 0; i < dust.size(); i++) {
			dist = calRD(-1, i);
			if (dist == 0) {
				noReach = true;
				break;
			}
			else 
				RDdist[i] = dist;			
		}
		if (noReach) {
			cout << -1 << endl;
			continue;
		}
		for (int i = 0; i < dust.size(); i++) {
			for (int j = i+1; j < dust.size(); j++) {
				dist = calRD(i, j);
				dust_dist[i][j] = dist;
				dust_dist[j][i] = dist;
			}
		}
		dfs(0);
		cout << result << endl;
	}
	system("pause");
	return 0;
}