#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;
int arr[104][104];
int num, result;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int block[6][4] = { {},{2,3,1,0},{1,3,0,2},{3,2,0,1},{2,0,3,1},{2,3,0,1} };
struct info {
	int x, y, val, dir;
};
info tmp;
vector<info> hole[5];
int sx, sy;

void bfs(int y, int x, int val) {
	queue<info> q;
	tmp.x = x;
	tmp.y = y;
	tmp.val = val;
	for (int i = 0; i < 4; i++) {
		tmp.dir = i;
		q.push(tmp);
	}
	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		int cv = q.front().val;
		int cd = q.front().dir;
		q.pop();
		int nx = cx + dx[cd];
		int ny = cy + dy[cd];
		if (nx == sx && ny == sy) {
			result = max(result, cv);
			continue;
		}
		int tt = arr[ny][nx];
		if (tt == -1) {		//다음 목적지가 블랙홀인 경우
			result = max(result, cv);
			continue;
		}

		else if (tt == 0) {		//빈 공간
			tmp.x = nx;
			tmp.y = ny;
			tmp.val = cv;
			tmp.dir = cd;
			q.push(tmp);
		}
		else if (tt > 0 && tt < 6) {		//블록
			int nd = block[tt][cd];
			tmp.x = nx;
			tmp.y = ny;
			tmp.val = cv + 1;
			tmp.dir = nd;
			q.push(tmp);
		}
		else if (6 <= tt && tt <= 10) {		//웜홀
			tmp.val = cv;
			tmp.dir = cd;
			if ((hole[tt - 6][0].x == nx) && (hole[tt - 6][0].y == ny)) {
				tmp.x = hole[tt - 6][1].x;
				tmp.y = hole[tt - 6][1].y;
			}
			else{
				tmp.x = hole[tt - 6][0].x;
				tmp.y = hole[tt - 6][0].y;
			}
			q.push(tmp);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		cin >> num;
		//초기화
		result = 0;
		for (int i = 0; i < num+2; i++)
			for (int j = 0; j < num + 2; j++) 
				arr[i][j] = 5;			
		for (int i = 0; i < 5; i++)
			hole[i].clear();

		for (int i = 1; i <= num; i++)
			for (int j = 1; j <= num; j++) {
				cin >> arr[i][j];
				if (6<= arr[i][j] && arr[i][j]<=10){
					tmp.x = j;
					tmp.y = i;
					hole[arr[i][j] - 6].push_back(tmp);
				}
			}

		for (int i = 1; i <= num; i++)
			for (int j = 1; j <= num; j++)
				if (arr[i][j] == 0) {
					sx = j;
					sy = i;
					bfs(i, j, 0);
				}
			
		cout << "#" << t << " " << result << endl;		
	}
	return 0;
}