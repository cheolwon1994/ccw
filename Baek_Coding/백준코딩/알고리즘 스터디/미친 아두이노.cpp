#include <iostream>
#include <vector>
#include <string>
using namespace std;
int dx[10] = { 0,-1,0,1,-1,0,1,-1,0,1 };
int dy[10] = { 0,1,1,1,0,0,0,-1,-1,-1 };
struct info {
	int x, y;
	bool crash;
};
info tmp;
int row, col, mx, my;		//행,열,내 아두이노의 x,y값
char arr[101][101];
int check[101][101];		//옮겨진 위치에 어떤 idx의 아두이노가 있는지 확인
vector<info> v;		//미친로봇의 위치
bool finish = false;

void mv() {		//미친 아두이노 이동
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			check[i][j] = -1;
	for (int i = 0; i < v.size(); i++) {
		if (!v[i].crash) {		//붕괴되지 않은 아두이노
			int cx = v[i].x;
			int cy = v[i].y;
			arr[cy][cx] = '.';
			if (mx > cx) {		//미친 아두이노가 내 기준 1,4,7방향에 위치한 경우. 
				if (my < cy) {		//1
					v[i].x -= dx[1];
					v[i].y -= dy[1];
				}
				else if (my == cy) {		//4
					v[i].x -= dx[4];
					v[i].y -= dy[4];
				}
				else if (my > cy) {		//7
					v[i].x -= dx[7];
					v[i].y -= dy[7];
				}
			}
			else if (mx == cx) {		//2,5,8의 위치에 존재
				if (my < cy) {		//2
					v[i].x -= dx[2];
					v[i].y -= dy[2];
				}
				else if (my > cy) {		//8
					v[i].x -= dx[8];
					v[i].y -= dy[8];
				}
			}
			else if (mx < cx) {		//3,6,9의 위치에 존재
				if (my < cy) {		//3
					v[i].x -= dx[3];
					v[i].y -= dy[3];
				}
				else if (my == cy) {	//6
					v[i].x -= dx[6];
					v[i].y -= dy[6];
				}
				else if (my > cy) {		//9
					v[i].x -= dx[9];
					v[i].y -= dy[9];
				}
			}
			if (arr[v[i].y][v[i].x] == 'I') {		//내 아두이노와 부딪히는 경우
				finish = true;
				break;
			}
			else if (check[v[i].y][v[i].x] == -1) 		//빈 경우, 몇번째 아두이노가 도착하는지 저장
				check[v[i].y][v[i].x] = i;
			else if (check[v[i].y][v[i].x] != -1) {		//또 다른 미친 아두이노와 부딪히는 경우
				v[i].crash = true;						//방금 움직인 아두이노
				v[check[v[i].y][v[i].x]].crash = true;	//이미 움직였던 아두이노
			}
		}
	}
	//붕괴된것들 처리
	for (int i = 0; i < v.size(); i++) {
		if (v[i].crash)		arr[v[i].y][v[i].x] = '.';
	}
	for (int i = 0; i < v.size(); i++) {
		if (!v[i].crash)	arr[v[i].y][v[i].x] = 'R';
	}
}

int main() {
	cin >> row >> col;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'I') {
				mx = j; my = i;
			}
			else if (arr[i][j] == 'R') {
				tmp.x = j;
				tmp.y = i;
				tmp.crash = false;
				v.push_back(tmp);
			}
		}
	string str;
	cin >> str;
	int result = 0;
	for (int i = 0; i < str.size(); i++) {
		int dir = str[i] - '0';
		//1. 내 아두이노 이동
		arr[my][mx] = '.';
		mx += dx[dir]; my += dy[dir];
		//2. 미친 아두이노랑 부딪혔는지 확인
		if (arr[my][mx] == 'R') {		//부딪힌 경우
			finish = true;
			result = i + 1;
			break;
		}
		arr[my][mx] = 'I';
		//3,4,5. 미친 아두이노 이동
		mv();
		if (finish) {
			result = i + 1;
			break;
		}
	}
	if (finish) cout << "kraj " << result;
	else {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++)
				cout << arr[i][j];
			cout << '\n';
		}
	}
	system("pause");
	return 0;
}