#include <iostream>
#include <queue>
#include <math.h>
using namespace std;
struct info {
	int x, y, val;
};
info tmp;
int n, m, t;
int arr[51][50];
bool check[51][50], flag;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

void cal() {
	int sum = 0;
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < m; j++) {
			if (arr[i][j] != 0) {
				sum += arr[i][j];
				cnt++;
			}
		}
	double avg = (double)sum / cnt;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < m; j++) {
			if (arr[i][j] != 0) {
				if (arr[i][j] < avg)	arr[i][j] += 1;
				else if (arr[i][j] > avg)	arr[i][j] -= 1;
			}
		}
}

void bfs(int y, int x) {
	queue<info> q, er;
	check[y][x] = true;
	tmp.x = x;
	tmp.y = y;
	tmp.val = arr[y][x];
	q.push(tmp);
	er.push(tmp);
	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		int cv = q.front().val;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = cx + dx[k];
			int ny = cy + dy[k];
			if (nx == -1) nx = m - 1;
			else if (nx == m) nx = 0;
			if (1 <= ny && ny <= n) {
				if (arr[ny][nx] == cv && !check[ny][nx]) {
					check[ny][nx] = true;
					tmp.x = nx;
					tmp.y = ny;
					tmp.val = cv;
					q.push(tmp);
					er.push(tmp);
				}
			}
		}
	}
	if (er.size() > 1) {
		flag = true;
		while (!er.empty()) {
			int cx = er.front().x;
			int cy = er.front().y;
			er.pop();
			arr[cy][cx] = 0;
		}
	}
}


void rot(int lev, int many) {		//시계방향으로만 회전
	for (int k = 0; k < many; k++) {
		int temp = arr[lev][m - 1];
		for (int i = m-1; i > 0; i--) 
			arr[lev][i] = arr[lev][i - 1];		
		arr[lev][0] = temp;
	}
}

bool test() {
	bool tt = true;
	for (int k = 1; k <= n; k++) {
		for (int j = 0; j < m; j++)
			if (arr[k][j] != 0) {
				tt = false;
				break;
			}
		if (!tt) break;
	}
	return tt;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> t;
	for (int i = 1; i <= n; i++) 
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	
	bool allzero = false;
	int plate, dir, many;
	for (int i = 0; i < t; i++) {
		cin >> plate >> dir >> many;
		if (allzero) continue;
		if (dir == 1) many = m - many;
		for (int k = plate; k <= n; k += plate)
			rot(k, many);
		flag = false;
		for (int k = 1; k <= n; k++)
			for (int j = 0; j < m; j++)
				check[k][j] = false;
		for (int k = 1; k <= n; k++)
			for (int j = 0; j < m; j++) {
				if (!check[k][j] && arr[k][j] > 0) {
					bfs(k, j);
				}
			}
		allzero = test();			
		if(!allzero && !flag)
			cal();		
	}
	int result = 0;
	for (int k = 1; k <= n; k++) 
		for (int j = 0; j < m; j++) 
			result += arr[k][j];
	cout << result;
	return 0;
}