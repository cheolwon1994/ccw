#include <iostream>
using namespace std;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
char arr[20][20];
bool check[20][20][16][4];		//y,x,mem,dir
int row, col;
bool haveAnnotation, finish;

void dfs(int y, int x, int mem, int dir) {
	if (finish) return;
	if (check[y][x][mem][dir]) return;
	check[y][x][mem][dir] = true;
	int nx, ny, nd = dir, nm = mem;
	char c = arr[y][x];
	if (c == '?') {
		for (int i = 0; i < 4; i++) {
			nx = x + dx[i];
			ny = y + dy[i];
			if (nx == -1) nx = col - 1;
			else if (ny == -1) ny = row - 1;
			else if (nx == col) nx = 0;
			else if (ny == row) ny = 0;
			dfs(ny, nx, mem, i);
		}
	}
	else {
		if (c == '^') nd = 0;
		else if (c == '>') nd = 1;
		else if (c == 'v') nd = 2;
		else if (c == '<') nd = 3;
		else if (c == '_') nd = mem == 0 ? nd = 1 : nd = 3;
		else if (c == '|') nd = mem == 0 ? nd = 2 : nd = 0;
		else if (c == '.') {}
		else if (c == '@') {
			finish = true;
			return;
		}
		else if (c == '+') nm = mem == 15 ? nm = 0 : nm = mem + 1;
		else if (c == '-') nm = mem == 0 ? nm = 15 : nm = mem - 1;
		else if (0 <= c - '0' && c - '0' <= 9) nm = c - '0';
		nx = x + dx[nd];
		ny = y + dy[nd];
		if (nx == -1) nx = col - 1;
		else if (ny == -1) ny = row - 1;
		else if (nx == col) nx = 0;
		else if (ny == row) ny = 0;
		dfs(ny, nx, nm, nd);
	}
	
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		//초기화
		haveAnnotation = false;
		finish = false;
		cin >> row >> col;
		for(int i=0;i<row;i++)
			for (int j = 0; j < col; j++) {
				cin >> arr[i][j];
				if (arr[i][j] == '@')
					haveAnnotation = true;
				for (int k = 0; k < 16; k++)
					for (int m = 0; m < 4; m++)
						check[i][j][k][m] = false;
			}
		if (!haveAnnotation) {			//출구가 없는 경우
			cout << "#" << t << " " << "NO" << '\n';
			continue;
		}
		dfs(0, 0, 0, 1);
		cout <<"#"<<t<<" "<< (finish ? "YES" : "NO") << '\n';
	}
	return 0;
}