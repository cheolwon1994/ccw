#define _CRT_NO_SECURE_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int arr[17][17];
int num;
int result = 0;

struct info {
	int x;
	int y;
	int type;
};
queue<info> q;
info tmp;
/*
type
0: →, 1: ↓, 2: ↘
0인 경우, 다음 행위로 0,2만 가능
1인 경우, 다음 행위로 1,2만 가능
2인 경우, 다음 해위로 0,1,2 가능
*/
void dfs() {
	while (!q.empty()) {
		int cur_x=q.front().x;
		int cur_y=q.front().y;
		int cur_type=q.front().type;
		q.pop();
		if (cur_x == num && cur_y == num) {
			result++;
			continue;
		}
		//가로가 가능한 경우
		if (cur_type == 0 || cur_type ==2) {
			if (cur_x + 1 <= num && arr[cur_y][cur_x + 1] != 1) {
				info tmp;
				tmp.x = cur_x + 1;
				tmp.y = cur_y;
				tmp.type = 0;
				q.push(tmp);
			}
		}
		//세로가 가능한 경우
		if (cur_type == 1 || cur_type == 2) {
			if (cur_y + 1 <= num && arr[cur_y + 1][cur_x] != 1) {
				info tmp;
				tmp.x = cur_x;
				tmp.y = cur_y+1;
				tmp.type = 1;
				q.push(tmp);
			}
		}
		//대각선이 가능한 경우
		if (cur_type == 0 || cur_type == 1 || cur_type == 2) {
			if (cur_y + 1 <= num && cur_x + 1 <= num && arr[cur_y + 1][cur_x] != 1 && arr[cur_y][cur_x + 1] != 1 && arr[cur_y + 1][cur_x + 1] != 1) {
				info tmp;
				tmp.x = cur_x+1;
				tmp.y = cur_y + 1;
				tmp.type = 2;
				q.push(tmp);
			}
		}
	}
}

int main() {
	cin >> num;
	for (int i = 1; i <= num; i++)
		for (int j = 1; j <= num; j++)
			cin >> arr[i][j];
	tmp.x = 2;
	tmp.y = 1;
	tmp.type = 0;
	q.push(tmp);
	dfs();
	cout << result;
	system("PAUSE");
	return 0;
}