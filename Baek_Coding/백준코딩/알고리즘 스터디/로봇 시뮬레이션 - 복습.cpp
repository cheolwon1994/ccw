#include <iostream>
#include <vector>
using namespace std;
int arr[101][101];
struct info {
	int x, y, dir;
};
struct info2 {
	int idx, repeat;
	char c;
};
info tmp;
info2 tmp2;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int row, col, robot, command;
vector<info> r;
vector<info2> cmd;
int main() {
	cin >> col >> row >> robot >> command;
	int x, y;
	char dir;
	for (int i = 0; i < robot; i++) {
		cin >> x >> y >> dir;
		tmp.x = x;
		tmp.y = row + 1 - y;
		if (dir == 'N') tmp.dir = 0;
		else if (dir == 'E') tmp.dir = 1;
		else if (dir == 'S') tmp.dir = 2;
		else if (dir == 'W') tmp.dir = 3;
		r.push_back(tmp);
		arr[tmp.y][tmp.x] = i + 1;
	}
	for (int i = 0; i < command; i++) {
		int idx, repeat;
		char c;
		cin >> idx >> c >> repeat;
		tmp2.c = c;
		tmp2.repeat = repeat;
		tmp2.idx = idx - 1;
		cmd.push_back(tmp2);
	}
	int flag = 0, rob1 = 0, rob2 = 0;		//0: ok, 1: crash wall, 2: crash robot // 부딪힌 로봇
	for (int i = 0; i < command; i++) {
		int r_idx = cmd[i].idx;
		char c = cmd[i].c;
		int repeat = cmd[i].repeat;
		if (c != 'F') {		//회전만 하는 경우
			repeat %= 4;
			if (repeat == 0) continue;		//제자리
			if (c == 'L') repeat = 4 - repeat;
			int nd = r[r_idx].dir;
			for (int j = 0; j < repeat; j++) 
				nd = (nd + 1) % 4;
			r[r_idx].dir = nd;
		}
		else {		//전진
			int cx = r[r_idx].x;
			int cy = r[r_idx].y;
			int cd = r[r_idx].dir;
			int nx, ny;
			for (int j = 0; j < repeat; j++) {
				nx = cx + dx[cd];
				ny = cy + dy[cd];
				if (nx<1 || ny<1 || nx>col || ny>row) {		//벽에 부딪히는 경우
					flag = 1;
					rob1 = r_idx + 1;
					break;
				}
				else if (arr[ny][nx]>0) {			//이미 로봇이 존재하는 경우
					flag = 2;
					rob1 = r_idx + 1;
					rob2 = arr[ny][nx];
					break;
				}
				else {
					arr[cy][cx] = 0;
					arr[ny][nx] = r_idx + 1;
					cx = nx;
					cy = ny;
					r[r_idx].x = cx;
					r[r_idx].y = cy;
				}
			}
		}
		if (flag > 0) break;
	}
	if (flag == 0) cout << "OK";
	else if (flag == 1) cout << "Robot " << rob1 << " crashes into the wall";
	else if (flag == 2) cout << "Robot " << rob1 << " crashes into robot " << rob2;
	system("pause");
	return 0;
}