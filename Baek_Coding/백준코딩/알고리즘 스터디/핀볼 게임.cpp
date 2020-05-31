#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;
struct info {
	int x, y, val, dir;
	bool s;		//시작지점인지 검사
};
info tmp;
int arr[102][102];
bool check[102][102][4];
int hx1[11], hx2[11], hy1[11], hy2[11];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int dir[6][4] = { {0,0,0,0},{2,3,1,0},{1,3,0,2},{3,2,0,1},{2,0,3,1},{2,3,0,1} };
int num, result, sx, sy;

void bfs(int y, int x) {
	queue<info> q;
	for (int i = 0; i < 4; i++) {
		tmp.x = x;
		tmp.y = y;
		tmp.dir = i;
		tmp.val = 0;
		tmp.s = true;
		q.push(tmp);
	}
	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		int cv = q.front().val;
		int cd = q.front().dir;
		bool cs = q.front().s;		
		q.pop();
		if (arr[cy][cx] == -1 || (sx == cx && sy == cy && !cs) || check[cy][cx][cd]) {		//시작지점으로 돌아오거나 블랙홀에 빠진 경우
			result = max(result, cv);
			continue;
		}
		check[cy][cx][cd] = true;
		int nd = cd;
		int nx = cx + dx[cd];
		int ny = cy + dy[cd];
		int v = arr[ny][nx];	
		tmp.x = nx;
		tmp.y = ny;
		tmp.dir = cd;
		tmp.val = cv;
		tmp.s = false;
		if (v < 1) 	q.push(tmp);		
		else if (v < 6) {
			tmp.dir = dir[v][cd];
			tmp.val = cv + 1;
			q.push(tmp);
		}
		else if(v>5){
			if (nx == hx1[v] && ny == hy1[v]) {
				tmp.x = hx2[v];
				tmp.y = hy2[v];
			}
			else {
				tmp.x = hx1[v];
				tmp.y = hy1[v];
			}
			q.push(tmp);
		}
	}	
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		result = 0;
		cin >> num;
		for (int i = 5; i < 11; i++) {
			hx1[i] = -1, hy1[i] = -1;
			hx2[i] = -1, hy2[i] = -1;
		}
		for (int i = 0; i < num+2; i++) 
			for (int j = 0; j < num+2; j++) {
				if (i == 0 || j == 0 || i == num + 1 || j == num + 1) {
					arr[i][j] = 5;
					continue;
				}
				cin >> arr[i][j];
				if (arr[i][j] > 5) {
					int v = arr[i][j];
					if (hx1[v] == -1) {
						hx1[v] = j; hy1[v] = i;
					}
					else {
						hx2[v] = j; hy2[v] = i;
					}
				}
			}
		for (int i = 1; i <= num; i++)
			for (int j = 1; j <= num; j++) {
				if (arr[i][j] == 0) {
					memset(check, false, sizeof(check));
					sx = j;
					sy = i;
					bfs(i, j);
				}
			}		
		cout << "#" << t << " " << result << '\n';		
	}
	system("pause");
	return 0;
}