#define MAX 987654321
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct info {
	int x, y, z, val;
};
info tmp;
int plate[5][5][5], ans = MAX;
int arr[5][5][5];
vector<int> p, r;
bool level[5] = { false, };
bool check[5][5][5];
int dx[6] = { 0,1,0,-1,0,0 };
int dy[6] = { -1,0,1,0,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };

void bfs() {
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			for (int k = 0; k < 5; k++)
				check[i][j][k] = false;
	queue<info> q;
	tmp.x = 0;
	tmp.y = 0;
	tmp.z = 0;
	tmp.val = 0;
	q.push(tmp);
	check[0][0][0] = true;
	bool finish = false;
	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		int cz = q.front().z;
		int cv = q.front().val;
		q.pop();
		if (cz == 4 && cy == 4 && cx == 4) {
			finish = true;
			ans = min(ans, cv);
			break;
		}
		for (int i = 0; i < 6; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			int nz = cz + dz[i];
			if (nx >= 0 && ny >= 0 && nz >= 0 && nx < 5 & ny < 5 && nz < 5 && arr[nz][ny][nx] == 1 && !check[nz][ny][nx]) {
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

void rot(int idx, int pla, int spin) {		//어떤 층에, 어떤 판을, 얼마만큼 회전
	int t_arr[5][5], tt[5];
	int s = spin;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			arr[idx][i][j] = plate[pla][i][j];
	//arr[idx]에다가 plate[pla]판을 spin만큼 회전시켜서 넣는다
	for (int t = 0; t < spin; t++) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++)
				t_arr[j][4-i] = arr[idx][i][j];
		}
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				arr[idx][i][j] = t_arr[i][j];
	}
}

void dfs(int lev) {
	if (ans == 12) return;
	if (lev == 5) {
		if(arr[0][0][0]==1)
			bfs();
		return;
	}
	for (int i = 0; i < 5; i++) {
		if (!level[i]) {
			level[i] = true;
			p.push_back(i);
			for (int j = 0; j < 4; j++) {
				rot(lev, i, j);
				dfs(lev + 1);
			}
			p.pop_back();
			level[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			for (int k = 0; k < 5; k++)
				cin >> plate[i][j][k];
	dfs(0);
	if (ans == MAX) ans = -1;
	cout << ans;
	return 0;
}