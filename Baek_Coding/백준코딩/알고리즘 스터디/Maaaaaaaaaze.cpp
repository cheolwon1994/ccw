#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int arr[5][5][5];//Ãþ,y,x
int dup[5][5][5];

int N = 5;
bool check[5];
vector<int> rot;
vector<int> order;
bool finish = false;
bool fin = false;
int result=1000;
int dx[6] = { 0,1,0,-1,0,0 };
int dy[6] = { -1,0,1,0,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };
struct info {
	int x, y, z, val;
};
info tmp;

void mv() {
	if (dup[0][0][0] != 1)
		return;
	int cz, cy, cx, cv, nx, ny, nz;
	bool flag[5][5][5] = { false, };
	queue<info> q;
	flag[0][0][0] = true;
	tmp.x = 0;
	tmp.y = 0;
	tmp.z = 0;
	tmp.val = 0;
	q.push(tmp);
	while (!q.empty()) {
		cx = q.front().x;
		cy = q.front().y;
		cz = q.front().z;
		cv = q.front().val;
		q.pop();
		if (cx == 4 && cy == 4 && cz == 4) {
			finish = true;
			result = min(result, cv);
			continue;
		}
		for (int i = 0; i < 6; i++) {
			nx = cx + dx[i];
			ny = cy + dy[i];
			nz = cz + dz[i];
			if (nz >= 0 && nx >= 0 && ny >= 0 && nz < 5 && nx < 5 && ny < 5 && !flag[nz][ny][nx] && dup[nz][ny][nx] == 1) {
				flag[nz][ny][nx] = true;
				tmp.x = nx;
				tmp.y = ny;
				tmp.z = nz;
				tmp.val = cv + 1;
				q.push(tmp);
			}
		}
	}
}

void rotate(int level, int k) {		//Ãþ,90µµ k¹ø È¸Àü
	for (int x = 0; x < k; x++) {
		for (int i = 0; i < N / 2; i++) {
			for (int j = i; j < N - i - 1; j++) {
				int k = dup[level][i][j];
				dup[level][i][j] = dup[level][N - 1 - j][i];
				dup[level][N - 1 - j][i] = dup[level][N - 1 - i][N - 1 - j];
				dup[level][N - 1 - i][N - 1 - j] = dup[level][j][N - 1 - i];
				dup[level][j][N - 1 - i] = k;
			}
		}
	}

}

void lev(int cnt) {	
	if (cnt == 5) {
		int tt;
		for (int i = 0; i < 5; i++)
			memcpy(dup[i], arr[order[i]], sizeof(dup[i]));
		for (int i = 0; i < 5; i++)
			rotate(i, rot[i]);
		//½ÃÀÛ
		mv();
		return;
	}
	for (int i = 0; i < 5; i++) {
		if (!check[i]) {
			check[i] = true;
			order.push_back(i);
			lev(cnt + 1);
			order.pop_back();
			check[i] = false;
		}
	}
}

void dfs(int cnt) {
	if (cnt == 5) {
		lev(0);
		if (result == 12)
			fin = true;
		return;
	}
	for (int i = 0; i < 4; i++) {
		rot.push_back(i);
		dfs(cnt + 1);
		if (fin)
			return;
		rot.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			for (int k = 0; k < 5; k++)
				cin >> arr[i][j][k];
	dfs(0);
	if (finish)
		cout << result;
	else
		cout << -1;
	system("pause");
	return 0;
}