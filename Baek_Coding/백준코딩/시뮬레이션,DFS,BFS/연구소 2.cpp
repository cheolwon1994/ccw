#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;
int num, v_num, cx, cy, nx, ny, cv;
int arr[50][50];
int check[50][50];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
struct info {
	int x;
	int y;
	int val = 0;
};
info tmp;
vector<info> v;
int result = 2500;
bool spread = false;
int main() {
	cin >> num >> v_num;
	for (int i = 0; i < num; i++)
		for (int j = 0; j < num; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				tmp.x = j;
				tmp.y = i;
				v.push_back(tmp);
			}
		}
	int len = v.size();
	vector<int> t;
	for (int i = 0; i < len - v_num; i++)
		t.push_back(0);
	for (int i = 0; i < v_num; i++)
		t.push_back(1);
	do {
		for (int i = 0; i < num; i++)
			memset(check[i], -1, sizeof(check[i]));
		queue<info> virus;
		for(int i=0;i<len;i++)
			if (t[i] == 1) {
				tmp.x = v[i].x;
				tmp.y = v[i].y;
				tmp.val = 0;
				virus.push(tmp);
				check[tmp.y][tmp.x] = 0;
			}
		int time = 0;
		while (!virus.empty()) {
			cx = virus.front().x;
			cy = virus.front().y;
			cv = virus.front().val;
			time = cv;
			virus.pop();
			for (int i = 0; i < 4; i++) {
				nx = cx + dx[i];
				ny = cy + dy[i];
				if (nx >= 0 && ny >= 0 && nx < num && ny < num && check[ny][nx] ==-1 && arr[ny][nx] != 1) {
					check[ny][nx] = cv + 1;
					tmp.x = nx;
					tmp.y = ny;
					tmp.val = cv + 1;
					virus.push(tmp);
				}
			}
		}
		bool flag = true;
		for (int i = 0; i < num; i++) {
			for (int j = 0; j < num; j++) {
				if (check[i][j] == -1 && arr[i][j]!=1) {
					flag = false;
					break;
				}
			}
			if (!flag)
				break;
		}
		if (flag) {
			spread = true;
			result = min(result, time);
		}
	} while (next_permutation(t.begin(), t.end()));
	if (spread)
		cout << result;
	else
		cout << -1;
	system("pause");
	return 0;
}