#define CRT_NO_SECURE_WARNINGS
#define MAX 987654321
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <string>
#include <queue>

using namespace std;
int row, virus_num;
int arr[50][50];
int dup_arr[50][50];
int result = MAX;
int flag[10];
int pre_max = -1;

struct info {
	int x;
	int y;
};
vector<info> virus;
vector<int> temp;
info tmp;
queue <info> active_virus;

int x[4] = { 0,1,0,-1 };
int y[4] = { -1,0,1,0 };

//다 퍼졌는지 확인하는 함수
bool check() {
	bool test = true;
	pre_max = 0;
	/*for (int i = 0; i < row; i++) {
		for (int j = 0; j < row; j++) {
			cout << dup_arr[i][j];
		}
		cout << endl;
	}
	cout << endl;*/
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < row; j++) {
			if (arr[i][j] == 0) {
				if (dup_arr[i][j] == -1) {
					test = false;
					break;
				}
				else
					pre_max = max(pre_max, dup_arr[i][j]);
			}
		}
		if (!test)
			break;
	}
	return test;
}

bool bfs() {
	int cur_x,cur_y,next_x,next_y,q_size;
	bool test;
	while (!active_virus.empty()) {	
		cur_x = active_virus.front().x;
		cur_y = active_virus.front().y;
		active_virus.pop();
		for (int i = 0; i < 4; i++) {
			next_x = cur_x + x[i];
			next_y = cur_y + y[i];
			if (next_x < 0 || next_y < 0 || next_x >= row || next_y >= row)
				continue;
			if (arr[next_y][next_x] != 1 && dup_arr[next_y][next_x] == -1) {
				dup_arr[next_y][next_x] = dup_arr[cur_y][cur_x]+1;
				tmp.y = next_y;
				tmp.x = next_x;
				active_virus.push(tmp);
			}
		}
	}
	test = check();
	return test;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> row >> virus_num;
	virus.clear();
	memset(flag, 0, sizeof(flag));
	for (int i = 0; i < row; i++)
		for (int j = 0; j < row; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				tmp.x = j;
				tmp.y = i;
				virus.push_back(tmp);
			}
		}
	vector<int> v;
	for (int i = 0; i < virus.size()-virus_num; i++)
		v.push_back(0);
	for (int i = virus.size() - virus_num; i < virus.size(); i++)
		v.push_back(1);

	bool test;
	do {
		memset(dup_arr, -1, sizeof(dup_arr));
		for (int i = 0; i < v.size(); i++) {
			if (v[i] == 1) {
				tmp.x = virus[i].x;
				tmp.y = virus[i].y;
				dup_arr[tmp.y][tmp.x] = 0;
				active_virus.push(tmp);
			}
		}
		test = bfs();
		if (test)
			result = min(result, pre_max);
		while (!active_virus.empty())
			active_virus.pop();
	} while (next_permutation(v.begin(), v.end()));

	if (result == MAX)
		cout << -1;
	else
		cout << result;
	system("PAUSE");
	return 0;
}