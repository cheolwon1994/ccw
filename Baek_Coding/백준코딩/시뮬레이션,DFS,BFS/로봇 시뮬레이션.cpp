#include <iostream>
#include <vector>
using namespace std;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int row, col, r_num, cmd;
int arr[101][101];		//1~100 사용
struct info {
	int x, y,dir;
};
info tmp;
struct info2 {
	int robot_num, repeat;
	char type;
};
info2 tmp2;
vector<info> robot;
vector<info2> command;
bool crash_wall = false;
bool crash_robot = false;

int rotate(int cd, char c, int rep) {		//오른쪽 회전 기준
	int rtn = cd;
	rep %= 4;
	if (c == 'L') 
		rep = 4 - rep;
	for (int i = 0; i < rep; i++)
		rtn = (rtn + 1) % 4;
	return rtn;
}

void start(int num){
	if (num == command.size())
		return;
	int robo, rep;
	char type;
	robo = command[num].robot_num - 1;
	type = command[num].type;
	rep = command[num].repeat;
	int cx, cy, cd, nd, nx, ny, cr;
	cx = robot[robo].x;
	cy = robot[robo].y;
	cd = robot[robo].dir;
	if (type == 'L' || type == 'R') {
		nd = rotate(cd,type,rep);
		robot[robo].dir = nd;
	}
	else if (type == 'F') {		
		nx = cx;
		ny = cy;
		for (int i = 0; i < rep; i++) {
			nx += dx[cd];
			ny += dy[cd];
			if (nx > 0 && ny > 0 && nx <= col && ny <= row) {
				if (arr[ny][nx] != 0) {
					cr = arr[ny][nx];
					crash_robot = true;
					break;
				}
			}
			else {
				crash_wall = true;
				break;
			}
		}
		if (!crash_robot) {
			robot[robo].x = nx;
			robot[robo].y = ny;
			arr[cy][cx] = 0;
			arr[ny][nx] = robo + 1;
		}
	}

	if (crash_wall) {
		cout << "Robot " << robo+1 << " crashes into the wall" << endl;
		system("pause");
		exit(0);
	}
	if (crash_robot) {
		cout << "Robot " << robo+1 << " crashes into robot " << cr<<endl;
		system("pause");
		exit(0);
	}	
	start(num + 1);
}

int main() {
	int x, y, rep;
	char c;
	cin >> col >> row;
	cin >> r_num >> cmd;
	for (int i = 0; i < r_num; i++) {
		cin >> x >> y >> c;
		tmp.y = row - y + 1;
		tmp.x = x;
		if (c == 'N')
			tmp.dir = 0;
		else if (c == 'E')
			tmp.dir = 1;
		else if (c == 'S')
			tmp.dir = 2;
		else if (c == 'W')
			tmp.dir = 3;
		robot.push_back(tmp);
		arr[tmp.y][tmp.x] = i+1;
	}
	for (int i = 0; i < cmd; i++) {
		cin >> r_num >> c >> rep;
		tmp2.repeat = rep;
		tmp2.robot_num = r_num;
		tmp2.type = c;
		command.push_back(tmp2);
	}
	start(0);
	if (!crash_wall && !crash_robot)
		cout << "OK" << endl;
	system("pause");
	return 0;
}