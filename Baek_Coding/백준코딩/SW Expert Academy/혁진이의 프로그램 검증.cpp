#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int row, col;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
char arr[20][20];
bool check[20][20][4][16];		//y,x,dir,mem
bool finish_avail;
bool stop_avail;

int next(int idx, int dir, char c) {
	if (c == 'y') {
		if (idx + dy[dir] == -1)
			return row - 1;
		else if (idx + dy[dir] == row)
			return 0;
		else
			return idx + dy[dir];
	}
	else if (c == 'x') {
		if (idx + dx[dir] == -1)
			return col - 1;
		else if (idx + dx[dir] == col)
			return 0;
		else
			return idx + dx[dir];
	}
}

void go(int y, int x, int dir, int mem) {
	//cout << "y,x,dir,mem: " << y << " " << x << " " << dir << " " << mem << endl;
	int ny, nx;
	if (stop_avail)
		return;
	if (arr[y][x] == '<') {
		ny = next(y, 3, 'y');
		nx = next(x, 3, 'x');
		if (check[ny][nx][3][mem]) {
			finish_avail = true;
			return;
		}
		else {
			check[ny][nx][3][mem] = true;
			go(ny, nx, 3, mem);
		}
	}
	else if (arr[y][x] == '>') {
		ny = next(y, 1, 'y');
		nx = next(x, 1, 'x');
		if (check[ny][nx][1][mem]) {
			finish_avail = true;
			return;
		}
		else {
			check[ny][nx][1][mem] = true;
			go(ny, nx, 1, mem);
		}
	}
	else if (arr[y][x] == '^') {
		ny = next(y, 0, 'y');
		nx = next(x, 0, 'x');
		if (check[ny][nx][0][mem]) {
			finish_avail = true;
			return;
		}
		else {
			check[ny][nx][0][mem] = true;
			go(ny, nx, 0, mem);
		}
	}
	else if (arr[y][x] == 'v') {
		ny = next(y, 2, 'y');
		nx = next(x, 2, 'x');
		if (check[ny][nx][2][mem]) {
			finish_avail = true;
			return;
		}
		else {
			check[ny][nx][2][mem] = true;
			go(ny, nx, 2, mem);
		}
	}
	else if (arr[y][x] == '_') {
		if (mem == 0) {
			ny = next(y, 1, 'y');
			nx = next(x, 1, 'x');
			if (check[ny][nx][1][mem]) {
				finish_avail = true;
				return;
			}
			else {
				check[ny][nx][1][mem] = true;
				go(ny, nx, 1, mem);
			}
		}
		else {
			ny = next(y, 3, 'y');
			nx = next(x, 3, 'x');
			if (check[ny][nx][3][mem]) {
				finish_avail = true;
				return;
			}
			else {
				check[ny][nx][3][mem] = true;
				go(ny, nx, 3, mem);
			}
		}
	}
	else if (arr[y][x] == '|') {
		if (mem == 0) {
			ny = next(y, 2, 'y');
			nx = next(x, 2, 'x');
			if (check[ny][nx][2][mem]) {
				finish_avail = true;
				return;
			}
			else {
				check[ny][nx][2][mem] = true;
				go(ny, nx, 2, mem);
			}
		}
		else {
			ny = next(y, 0, 'y');
			nx = next(x, 0, 'x');
			if (check[ny][nx][0][mem]) {
				finish_avail = true;
				return;
			}
			else {
				check[ny][nx][0][mem] = true;
				go(ny, nx, 0, mem);
			}
		}
	}
	else if (arr[y][x] == '?') {
		bool all_non = true;		//4방향 모두 안되는 경우 끝내기
		for (int i = 0; i < 4; i++) {
			ny = next(y, i, 'y');
			nx = next(x, i, 'x');
			if (check[ny][nx][i][mem])
				continue;
			else {
				check[ny][nx][i][mem] = true;
				all_non = false;
				go(ny, nx, i, mem);
			}
		}
		if (all_non) {
			finish_avail = true;
			return;
		}
	}
	else if (arr[y][x] == '.') {
		ny = next(y, dir, 'y');
		nx = next(x, dir, 'x');
		if (check[ny][nx][dir][mem]) {
			finish_avail = true;
			return;
		}
		else {
			check[ny][nx][dir][mem] = true;
			go(ny, nx, dir, mem);
		}
		return;
	}
	else if (arr[y][x] == '@') {
		stop_avail = true;
		return;
	}
	else if (arr[y][x] - '0' >= 0 && arr[y][x] - '0' <= 9) {
		ny = next(y, dir, 'y');
		nx = next(x, dir, 'x');
		if (check[ny][nx][dir][arr[y][x] - '0']) {
			finish_avail = true;
			return;
		}
		else {
			check[ny][nx][dir][arr[y][x] - '0'] = true;
			go(ny, nx, dir, arr[y][x] - '0');
		}
	}
	else if (arr[y][x] == '+') {
		int t_mem = (mem + 1) % 16;
		ny = next(y, dir, 'y');
		nx = next(x, dir, 'x');
		if (check[ny][nx][dir][t_mem]) {
			finish_avail = true;
			return;
		}
		else {
			check[ny][nx][dir][t_mem] = true;
			go(ny, nx, dir, t_mem);
		}
	}
	else if (arr[y][x] == '-') {
		int t_mem = (mem + 15) % 16;
		ny = next(y, dir, 'y');
		nx = next(x, dir, 'x');
		if (check[ny][nx][dir][t_mem]) {
			finish_avail = true;
			return;
		}
		else {
			check[ny][nx][dir][t_mem] = true;
			go(ny, nx, dir, t_mem);
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		cin >> row >> col;
		bool noAdd = true;
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++) {
				cin >> arr[i][j];
				if (arr[i][j] == '@')
					noAdd = false;
			}
		if (noAdd) {
			cout << "#" << t << " " << "NO" << endl;
			continue;
		}
		//초기화 작업
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				for (int k = 0; k < 4; k++)
					for (int m = 0; m < 16; m++)
						check[i][j][k][m] = false;
		finish_avail = false;
		stop_avail = false;
		check[0][0][1][0] = true;
		go(0, 0, 1, 0);
		if (stop_avail)
			cout << "#" << t << " " << "YES" << endl;
		else
			cout << "#" << t << " " << "NO" << endl;
	}
	system("pause");
	return 0;
}