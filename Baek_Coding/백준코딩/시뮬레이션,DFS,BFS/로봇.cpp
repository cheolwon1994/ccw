#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int arr[101][101];
int check[101][101][5];
int row, col;
struct info {
	int y;
	int x;
	int dir;
	int val;
};
//동서남북 : 1~4
int dx[5] = { 0,1,-1,0,0 };
int dy[5] = { 0,0,0,1,-1 };
queue<info> q;
int dest_x, dest_y, dest_dir;
int result = 0;

int opp(int n) {
	if (n == 1) return 2;
	else if (n == 2) return 1;
	else if (n == 3) return 4;
	else return 3;
}

int main() {
	cin >> row >> col;
	int x, y, dir, cx, cy, cv, cd, nx, ny, nd;
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++)
			cin >> arr[i][j];
	cin >> y >> x >> dir;
	q.push({ y,x ,dir,0 });
	check[y][x][dir] = 1;
	cin >> dest_y >> dest_x >> dest_dir;
	while (!q.empty()) {
		cx = q.front().x;
		cy = q.front().y;
		cv = q.front().val;
		cd = q.front().dir;
		q.pop();
		if (cx == dest_x && cy == dest_y && cd == dest_dir) {
			result = cv;
			break;
		}
		for (int i = 1; i <= 3; i++) {  // 그 방향으로 갈 수 있는 곳은 cnt 변화 없이 que 에 넣습니다. 
			nx = cx + dx[cd] * i;
			ny = cy + dy[cd] * i;
			if (nx < 1 || ny < 1 || nx > col || ny > row) break; // 맵을 벗어나면
			if (arr[ny][nx]==1) break; // 벽이면
			if (check[ny][nx][cd]==1) continue; // 다음 것 조사하도록 넘어갑니다.
			check[ny][nx][cd] = 1;
			q.push({ ny,nx,cd,cv + 1 });
		}
		for (int i = 1; i <= 4; i++) { // 동 서 남 북 으로 턴해서 갈 수 있는 곳은 cnt+1 을 하고 que에 넣습니다.
			if (i == cd) continue; // 동쪽을 바라보고 있으면 그냥, 서쪽을 바라보고 있으면 그냥 왜 반대쪽도 그냥 넘어가지?
			if (check[cy][cx][i]==1) continue; // 왔던 길이면, 패스
			check[cy][cx][i] = 1;
			if (i == opp(cd)) {
				q.push({ cy,cx,i,cv + 2 });
			}
			else {
				q.push({ cy,cx,i,cv + 1 });
			}
		}
	}
	cout << result;
	system("pause");
	return 0;
}