#define CRT_NO_SECURE_WARNINGS
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <queue>

using namespace std;
int check[20][20][16][4];		//y,x,mem,dir
char arr[20][20];
int row, col;
int storage;		//메모리 역할
int dx[4] = { 1,0,-1,0 };		//0: 오, 1: 아, 2: 왼, 3: 위
int dy[4] = { 0,1,0,-1 };
struct info {
	int y;
	int x;
	int mem;
	int dir;
};
info tmp;

bool go() {
	queue<info> q;
	tmp.dir = 0;
	tmp.mem = 0;
	tmp.y = 0;
	tmp.x = 0;
	q.push(tmp);
	check[0][0][0][0] = 1;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int dir = q.front().dir;
		int mem = q.front().mem;
		/*cout << y << " " << x << " " << mem << " " << dir << endl;
		system("PAUSE");*/
		q.pop();
		if (0 <= arr[y][x] - '0' && arr[y][x] - '0' <= 9)
			mem = arr[y][x] - '0';
		else if (arr[y][x] == '<') dir = 2;
		else if (arr[y][x] == '>') dir = 0;
		else if (arr[y][x] == '^') dir = 3;
		else if (arr[y][x] == 'v') dir = 1;
		else if (arr[y][x] == '_') dir = mem == 0 ? 0 : 2;	
		else if (arr[y][x] == '|') dir = mem == 0 ? 1 : 3;
		else if (arr[y][x] == '?') {
			for (int i = 0; i < 4; i++) {
				int nx, ny;
				nx = x + dx[i];
				ny = y + dy[i];
				if (nx == -1) nx = col - 1;
				else if (nx == col) nx = 0;
				if (ny == -1) ny = row - 1;
				else if (ny == row) ny = 0;

				if (check[ny][nx][mem][i] != 1) {
					tmp.x = nx;
					tmp.y = ny;
					tmp.dir = i;
					tmp.mem = mem;
					q.push(tmp);
					check[ny][nx][mem][i] = 1;
				}
			}
		}
		else if (arr[y][x] == '@') { return true;}
		else if (arr[y][x] == '+') mem = mem == 15 ? 0 : mem + 1;
		else if (arr[y][x] == '-') mem = mem == 0 ? 15 : mem - 1;

		int nx, ny;
		nx = x + dx[dir];
		ny = y + dy[dir];
		if (nx == -1) nx = col - 1;
		else if (nx == col) nx = 0;
		if (ny == -1) ny = row - 1;
		else if (ny == row) ny = 0;

		if (check[ny][nx][mem][dir] != 1) {
			tmp.x = nx;
			tmp.y = ny;
			tmp.dir = dir;
			tmp.mem = mem;
			q.push(tmp);
			check[ny][nx][mem][dir] = 1;
		}
	}
	return false;
}

int main(){
	int t;
	cin >> t;
	for (int k = 1; k <= t; k++) {
		cin >> row >> col;
		for (int i = 0; i < row; i++) 
			memset(arr[i], 0, sizeof(arr[i]));
		memset(check, 0, sizeof(check));
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				cin >> arr[i][j];
		bool flag = go();
		if (flag)
			cout << "#" << k << " " << "YES" << endl;
		else
			cout << "#" << k << " " << "NO" << endl;
	}
	system("PAUSE");
	return 0;
}