#define MAX 987654321
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
int arr[5][5][5];
int dup[5][5][5];

bool flag[5] = { false, };
vector<int> level;
vector<int> rot;
int result;
int dx[6] = { 0,1,0,-1,0,0 };
int dy[6] = { -1,0,1,0,0,0 };
int dz[6] = { 0,0,0,0,-1,1 };
struct info {
	int x, y, z, val;
};
info tmp;
void bfs() {
	bool check[5][5][5] = { false, };
	tmp.x = 0;
	tmp.y = 0;
	tmp.z = 0;
	tmp.val = 0;
	queue<info> q;
	q.push(tmp);
	check[0][0][0] = true;
	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		int cz = q.front().z;
		int cv = q.front().val;
		q.pop();
		if (cv > result) continue;
		if (cz == 4 && cy == 4 && cx == 4) {
			result = min(result, cv);
			break;
		}
		for (int i = 0; i < 6; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			int nz = cz + dz[i];
			if (nx >= 0 && ny >= 0 && nz >= 0 && nz < 5 && nx < 5 && ny < 5 && !check[nz][ny][nx] && dup[nz][ny][nx] == 1) {
				check[nz][ny][nx] = true;
				tmp.x = nx;
				tmp.y = ny;
				tmp.z = nz;
				tmp.val = cv + 1;
				q.push(tmp);
			}
		}
	}
}

void rotate_level(int lv, int k) {
	for (int x = 0; x < k; x++) {
		for (int i = 0; i < 2; i++) {
			for (int j = i; j < 4 - i; j++) {
				int k = dup[lv][i][j];
				dup[lv][i][j] = dup[lv][4 - j][i];
				dup[lv][4 - j][i] = dup[lv][4 - i][4 - j];
				dup[lv][4 - i][4 - j] = dup[lv][j][4 - i];
				dup[lv][j][4 - i] = k;
			}
		}
	}
}

void set_rotate(int cnt) {
	if (cnt == 5) {
		for (int i = 0; i < 5; i++)
			memcpy(dup[i], arr[level[i]], sizeof(dup[i]));
		for (int i = 0; i < 5; i++)
			rotate_level(i, rot[i]);
		if(dup[0][0][0]==1)
			bfs();
		return;
	}
	for (int i = 0; i < 4; i++) {
		rot.push_back(i);
		set_rotate(cnt + 1);
		rot.pop_back();
	}
}

void set_level(int cnt) {
	if (cnt == 5) {
		set_rotate(0);
		return;
	}
	for (int i = 0; i < 5; i++) {
		if (!flag[i]) {
			flag[i] = true;
			level.push_back(i);
			set_level(cnt + 1);
			if (result == 12) return;
			flag[i] = false;
			level.pop_back();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			for (int k = 0; k < 5; k++)
				cin >> arr[i][j][k];
	result = MAX;
	set_level(0);
	if (result == MAX) result = -1;
	cout << result;
	system("pause");
	return 0;
}