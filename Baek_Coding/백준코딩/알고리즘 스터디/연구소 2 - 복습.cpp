#define MAX 987654321
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
struct info {
	int x, y, val;
};
info tmp;
vector<info> virus;
vector<info> v;
int arr[50][50];
bool check[50][50];
int num, sel, tot = 0;
int result = MAX;

void bfs() {
	for (int i = 0; i < num; i++)
		memset(check[i], false, sizeof(check[i]));
	queue<info> q;
	for (int i = 0; i < sel; i++) {
		tmp.x = v[i].x;
		tmp.y = v[i].y;
		tmp.val = 0;
		q.push(tmp);
		check[tmp.y][tmp.x] = true;
	}
	int cx, cy, cv, nx, ny, temp = -1;
	while (!q.empty()) {
		cx = q.front().x;
		cy = q.front().y;
		cv = q.front().val;
		temp = max(temp, cv);
		q.pop();
		for (int i = 0; i < 4; i++) {
			nx = cx + dx[i];
			ny = cy + dy[i];
			if (nx >= 0 && ny >= 0 && nx < num && ny < num && !check[ny][nx] && arr[ny][nx]!=1) {
				check[ny][nx] = true;
				tmp.x = nx;
				tmp.y = ny;
				tmp.val = cv + 1;
				check[ny][nx] = true;
				q.push(tmp);
			}
		}
	}
	bool all_cover = true;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			if (arr[i][j] !=1 && !check[i][j]) {
				all_cover = false;
				break;
			}
		}
		if (!all_cover)
			break;
	}
	if(all_cover)
		result = min(result, temp);
}

int main() {
	cin >> num >> sel;
	for (int i = 0; i < num; i++)
		for (int j = 0; j < num; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				tmp.x = j;
				tmp.y = i;
				virus.push_back(tmp);
				tot++;
			}
		}

	vector<int> t;
	for (int i = 0; i < tot - sel; i++)
		t.push_back(0);
	for (int i = 0; i < sel; i++)
		t.push_back(1);

	do {
		v.clear();
		for (int i = 0; i < tot; i++) {
			if (t[i] == 1) {
				tmp.x = virus[i].x;
				tmp.y = virus[i].y;
				v.push_back(tmp);
			}
		}
		bfs();
	} while (next_permutation(t.begin(), t.end()));
	if (result == MAX) cout << -1;
	else cout << result;
	system("pause");
	return 0;
}