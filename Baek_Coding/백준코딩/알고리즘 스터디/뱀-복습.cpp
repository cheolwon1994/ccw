#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int arr[101][101];
bool check[101][101] = { false, };
int num, apple, command;
bool finish = false;
struct info {
	int x, y;
};
struct info2 {
	int t;
	char c;
};
info tmp;
info2 tmp2;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
deque<info> snake;
deque<info2> c;
int result = 0;
void start() {
	int cx, cy, nx, ny, cd = 1;
	while (!finish) {
		result++;
		cx = snake[0].x;
		cy = snake[0].y;
		//이동
		nx = cx + dx[cd];
		ny = cy + dy[cd];
		if (nx > 0 && ny > 0 && nx <= num && ny <= num) {
			if (check[ny][nx]) {		//자기 자신과 부딪히는 경우
				finish = true;
				break;
			}
			else {
				tmp.x = nx;
				tmp.y = ny;
				snake.push_front(tmp);
				check[ny][nx] = true;
				if (arr[ny][nx] == 0) {
					int x = snake[snake.size() - 1].x;
					int y = snake[snake.size() - 1].y;
					check[y][x] = false;
					snake.pop_back();
				}
				else if (arr[ny][nx] == 1)	arr[ny][nx] = 0;
			}
		}
		else {
			finish = true;		//벽과 부딪히는 경우
			break;
		}		
		if (!c.empty()) {
			if (c[0].t == result) {		//명령 수행
				if (c[0].c == 'D') 	cd = (cd + 1) % 4;
				else cd = (cd + 3) % 4;
				c.pop_front();
			}
		}
	}
}

int main() {
	int x,y;
	cin >> num >> apple;
	for (int i = 0; i < apple; i++) {
		cin >> y >> x;
		arr[y][x] = 1;
	}
	tmp.x = 1;
	tmp.y = 1;
	snake.push_back(tmp);
	check[1][1] = true;
	cin >> command;
	for (int i = 0; i < command; i++) {
		cin >> tmp2.t >> tmp2.c;
		c.push_back(tmp2);
	}
	start();
	cout << result;
	system("pause");
	return 0;
}