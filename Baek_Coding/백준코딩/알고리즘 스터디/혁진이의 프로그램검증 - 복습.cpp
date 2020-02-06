#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
char arr[20][20];
bool check[20][20][4][16];//dir,mem
int row, col;
bool finish;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
void start(int y, int x, int dir, int mem) {
	//cout << y << " " << x << " " << dir << " " << mem << endl;
	if (arr[y][x] == '@') {
		finish = true;
		return;
	}
	if (check[y][x][dir][mem]) 	return;		//반복
	int nd, nm;
	check[y][x][dir][mem] = true;

	if (arr[y][x] == '.') { nd = dir; nm = mem; }
	else if (arr[y][x] == '<') { nd = 3; nm = mem; }
	else if (arr[y][x] == '>') { nd = 1; nm = mem; }
	else if (arr[y][x] == '^') { nd = 0; nm = mem; }
	else if (arr[y][x] == 'v') { nd = 2; nm = mem; }
	else if (arr[y][x] == '_') {
		if (mem == 0) nd = 1;
		else nd = 3;
		nm = mem;
	}
	else if (arr[y][x] == '|') {
		if (mem == 0) nd = 2;
		else nd = 0;
		nm = mem;
	}
	else if (0 <= arr[y][x] - '0' && arr[y][x] - '0' <= 9) {
		nd = dir; nm = arr[y][x] - '0';
	}
	else if (arr[y][x] == '+') {
		nd = dir; nm = mem + 1;
		if (nm == 16) nm = 0;
	}
	else if (arr[y][x] == '-') {
		nd = dir; nm = mem - 1;
		if (nm == -1) nm = 15;
	}
	if (arr[y][x] != '?') {
		int nx = x + dx[nd];
		int ny = y + dy[nd];
		if (nx < 0) nx = col - 1;
		else if (nx == col) nx = 0;
		if (ny < 0) ny = row - 1;
		else if (ny == row) ny = 0;
		start(ny, nx, nd, nm);
	}
	else if (arr[y][x] == '?') {
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0) nx = col - 1;
			else if (nx == col) nx = 0;
			if (ny < 0) ny = row - 1;
			else if (ny == row) ny = 0;
			start(ny, nx, i, mem);
		}
	}
}

int main() {
	int test;
	cin >> test;
	string str;
	for (int t = 1; t <= test; t++) {
		cin >> row >> col;
		bool avail = false;
		for (int i = 0; i < row; i++) {
			cin >> str;
			for (int j = 0; j < col; j++) {
				arr[i][j] = str[j];
				if (arr[i][j] == '@')
					avail = true;
			}
		}
		if (!avail) { cout << "#" << t << " " << "NO\n"; continue; }
		//초기화
		for (int k = 0; k < 20; k++)
			for (int m = 0; m < 20; m++)
				for (int i = 0; i < 4; i++)
					for (int j = 0; j < 16; j++)
						check[k][m][i][j] = false;
		finish = false;
		start(0, 0, 1, 0);
		if (finish) cout << "#" << t << " " << "YES\n";
		else cout << "#" << t << " " << "NO\n";
	}
	system("pause");
	return 0;
}