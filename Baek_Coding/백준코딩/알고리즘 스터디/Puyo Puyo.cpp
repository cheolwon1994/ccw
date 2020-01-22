#include <iostream>
#include <string.h>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
char arr[12][6];
bool check[12][6];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int result = 0;		//연쇄 횟수
struct info {
	int x, y;
};
info tmp;
bool finish;		//true면 더이상 터질것이 없다

void mv_down() {
	string str;
	for (int j = 0; j < 6; j++) {
		str = "";
		for (int i = 11; i >= 0; i--) {
			if (arr[i][j] != '.')
				str += arr[i][j];
		}
		int cnt = 0;
		for (int i = 11; i > 11 - str.size(); i--) 
			arr[i][j] = str[cnt++];
		for (int i = 11 - str.size(); i >= 0; i--)
			arr[i][j] = '.';
	}
}

void bfs(int y, int x, char c) {
	int cx, cy, nx, ny;
	queue<info> q;
	vector<info> v;
	tmp.x = x;
	tmp.y = y;
	q.push(tmp);
	v.push_back(tmp);
	check[y][x] = true;
	while (!q.empty()) {
		cx = q.front().x;
		cy = q.front().y;
		q.pop();
		for (int i = 0; i < 4; i++) {
			nx = cx + dx[i];
			ny = cy + dy[i];
			if (nx >= 0 && ny >= 0 && nx < 6 && ny < 12 && !check[ny][nx] && arr[ny][nx]==c) {
				check[ny][nx] = true;
				tmp.x = nx;
				tmp.y = ny;
				q.push(tmp);
				v.push_back(tmp);
			}
		}
	}
	if (v.size() > 3) {
		for (int i = 0; i < v.size(); i++)
			arr[v[i].y][v[i].x] = '.';
		finish = false;
	}
	v.clear();
}

void find() {
	for(int i=11;i>=0;i--)
		for (int j = 0; j < 6; j++) {
			if (arr[i][j] != '.' && !check[i][j]) {
				bfs(i, j, arr[i][j]);
			}
		}
}

int main() {
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 6; j++)
			cin >> arr[i][j];
	while (1) {
		for (int i = 0; i < 12; i++)
			memset(check[i], false, sizeof(check[i]));
		finish = true;
		find();
		if (finish)
			break;
		mv_down();
		result++;
	}
	cout << result;
	system("pause");
	return 0;
}