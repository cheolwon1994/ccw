#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
char arr[10][10];
int check[10][10];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int row, col;
struct info {
	int x, y;
};
info tmp;
stack<info> r;
stack<info> b;
bool red_found, blue_found, red_blocked, blue_blocked;
int result = -1;

int move(char c, int y,int x, int dir) {
	int nx = x;
	int ny = y;
	int temp = 0;
	for (int i = 0;; i++) {
		temp = i;
		nx += dx[dir];
		ny += dy[dir];
		if (arr[ny][nx] == '.')
			continue;
		else if (arr[ny][nx] == '#') 
			break;		
		else if (arr[ny][nx] == 'O') {
			if (c == 'R') {
				red_found = true;
				break;
			}
			else if (c == 'B') {
				blue_found = true;
				break;
			}
		}
		else if (arr[ny][nx] == 'R') {
			blue_blocked = true;
			continue;
		}
		else if (arr[ny][nx] == 'B') {
			red_blocked = true;
			continue;
		}
	}
	if (temp == 0)
		return temp;
	else
		return temp;
}

void start(int num,int dir) {
	if (num > 9) 
		return;	
	int rcx = r.top().x;
	int rcy = r.top().y;
	int bcx = b.top().x;
	int bcy = b.top().y;
	for (int i = 0; i < 4; i++) {
		if ((i + 2) % 4 == dir && num != 0)	continue;	//이전에서 왔던 방향은 안한다
		red_found = false;
		blue_found = false;
		red_blocked = false;
		blue_blocked = false;
		int rnx = rcx + dx[i];
		int rny = rcy + dy[i];
		if (rnx >= 0 && rny >= 0 && rnx < col && rny < row) {
			int r_move = move('R', rcy, rcx, i);
			int b_move = move('B', bcy, bcx, i);
			if (blue_found) continue;		//파란공이 빠진경우

			if (red_found) {			//골인 한 경우
				if (result == -1)
					result = num + 1;
				else
					result = min(result, num + 1);
				break;
			}
			if (r_move == 0 && b_move==0) continue;		//못움직이는 경우
			
			if (red_blocked) {
				if (b_move == 0 && r_move==1)
					continue;
				else {
					if (b_move > 0) {
						arr[bcy + dy[i] * b_move][bcx + dx[i] * b_move] = 'B';
						arr[bcy][bcx] = '.';
						tmp.x = bcx + dx[i] * b_move;
						tmp.y = bcy + dy[i] * b_move;
						b.push(tmp);
					}
					arr[rcy + dy[i] *(r_move-1)][rcx + dx[i] * (r_move-1)] = 'R';
					arr[rcy][rcx] = '.';
					tmp.x = rcx + dx[i] * (r_move-1);
					tmp.y = rcy + dy[i] * (r_move-1);
					r.push(tmp);
					start(num + 1, i);
					arr[r.top().y][r.top().x] = '.';
					r.pop();
					arr[r.top().y][r.top().x] = 'R';
					if (b_move > 0) {
						arr[b.top().y][b.top().x] = '.';
						b.pop();
						arr[b.top().y][b.top().x] = 'B';
					}
					rcx = r.top().x;
					rcy = r.top().y;
					bcx = b.top().x;
					bcy = b.top().y;
				}
			}
			else if (blue_blocked) {
				if (r_move == 0 && b_move==1)
					continue;
				else {
					if (r_move > 0) {
						arr[rcy + dy[i] * r_move][rcx + dx[i] * r_move] = 'R';
						arr[rcy][rcx] = '.';
						tmp.x = rcx + dx[i] * r_move;
						tmp.y = rcy + dy[i] * r_move;
						r.push(tmp);
					}
					arr[bcy + dy[i] * (b_move-1)][bcx + dx[i] * (b_move-1)] = 'B';
					arr[bcy][bcx] = '.';
					tmp.x = bcx + dx[i] * (b_move-1);
					tmp.y = bcy + dy[i] * (b_move-1);
					b.push(tmp);
					start(num + 1, i);
					if (r_move > 0) {
						arr[r.top().y][r.top().x] = '.';
						r.pop();
						arr[r.top().y][r.top().x] = 'R';
					}
					arr[b.top().y][b.top().x] = '.';
					b.pop();
					arr[b.top().y][b.top().x] = 'B';
					rcx = r.top().x;
					rcy = r.top().y;
					bcx = b.top().x;
					bcy = b.top().y;
				}
			}
			else {
				if (r_move > 0) {
					arr[rcy + dy[i] * r_move][rcx + dx[i] * r_move] = 'R';
					arr[rcy][rcx] = '.';
					tmp.x = rcx + dx[i] * r_move;
					tmp.y = rcy + dy[i] * r_move;
					r.push(tmp);
				}
				if (b_move > 0) {
					arr[bcy + dy[i] * b_move][bcx + dx[i] * b_move] = 'B';
					arr[bcy][bcx] = '.';
					tmp.x = bcx + dx[i] * b_move;
					tmp.y = bcy + dy[i] * b_move;
					b.push(tmp);
				}
				start(num + 1, i);
				if (r_move > 0) {
					arr[r.top().y][r.top().x] = '.';
					r.pop();
					arr[r.top().y][r.top().x] = 'R';
				}
				if (b_move > 0) {
					arr[b.top().y][b.top().x] = '.';
					b.pop();
					arr[b.top().y][b.top().x] = 'B';
				}
				rcx = r.top().x;
				rcy = r.top().y;
				bcx = b.top().x;
				bcy = b.top().y;
			}
		}
	}

	return;
}

int main() {
	cin >> row >> col;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'R') {
				tmp.x = j;
				tmp.y = i;
				r.push(tmp);
			}
			else if (arr[i][j] == 'B') {
				tmp.x = j;
				tmp.y = i;
				b.push(tmp);
			}
		}

	start(0,0);
	cout << result;
	system("pause");
	return 0;
}