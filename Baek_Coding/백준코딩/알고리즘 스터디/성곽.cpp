#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int arr[50][50];
bool check[50][50] = { false, };
struct info {
	int x, y;
};
info tmp;
vector<info> team[2501];
vector<int> v[50][50];		//1: 벽 존재, 0: 벽x
int row, col, maxi;
int cnt = 0;
int result = 0;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

void wall(int f, int s) {
	int t_result = 0;
	bool find = false;
	int cx, cy, nx, ny;
	for (int i = 0; i < team[f].size(); i++) {
		cx = team[f][i].x;
		cy = team[f][i].y;
		for (int j = 0; j < 4; j++) {
			nx = cx + dx[j];
			ny = cy + dy[j];
			if (nx >= 0 && ny >= 0 && nx < col && ny < row) {
				if (arr[ny][nx] == s) {
					find = true;
					break;
				}
			}
		}
		if (find)
			break;
	}
	if (find) {
		t_result = team[f].size() + team[s].size();
		result = max(result, t_result);
	}
}

void start(int y, int x, int cnt) {
	int cx, cy, nx, ny, tt = 1;
	queue<info> q;
	tmp.x = x;
	tmp.y = y;
	q.push(tmp);
	check[y][x] = true;
	arr[y][x] = cnt;
	team[cnt].push_back(tmp);
	while (!q.empty()) {
		cx = q.front().x;
		cy = q.front().y;
		q.pop();
		for (int i = 0; i < 4; i++) {
			if (v[cy][cx][i] == 0) {
				nx = cx + dx[i];
				ny = cy + dy[i];
				if (nx >= 0 && ny >= 0 && nx < col && ny < row && !check[ny][nx]) {
					check[ny][nx] = true;
					arr[ny][nx] = cnt;
					tmp.x = nx;
					tmp.y = ny;
					q.push(tmp);
					team[cnt].push_back(tmp);
					tt++;
				}
			}
		}
	}
	maxi = max(maxi, tt);
}

int main() {
	cin >> col >> row;
	int tt;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> tt;
			v[i][j].push_back(tt / 8); tt %= 8;
			v[i][j].push_back(tt / 4); tt %= 4;
			v[i][j].push_back(tt / 2); tt %= 2;
			v[i][j].push_back(tt);
		}
	}
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			if (!check[i][j]) {
				cnt++;
				start(i, j, cnt);
			}
	for (int i = 1; i <= cnt; i++)
		for (int j = i + 1; j <= cnt; j++)
			wall(i, j);
	cout << cnt << endl << maxi << endl << result;
	system("pause");
	return 0;
}