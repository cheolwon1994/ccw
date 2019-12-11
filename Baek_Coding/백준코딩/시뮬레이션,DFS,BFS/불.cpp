#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <deque>
using namespace std;
int test, row, col;
struct info {
	int y;
	int x;
	int val;
};
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };
char arr[1000][1000];
int check[1000][1000][2];		//[][][0] : 사람, [][][1]: 불 ->1: 퍼질예정, 2: 퍼진 후

int main() {
	cin >> test;
	string str;
	int cx, cy, nx, ny, cv;
	for (int t = 0; t < test; t++) {
		cin >> col >> row;
		for(int i=0;i<row;i++)
			for (int j = 0; j < col; j++) {
				arr[i][j] = 0;
				check[i][j][0] = 0;
				check[i][j][1] = 0;
			}
		queue<info> q;
		deque<info> fire;
		int result;
		for (int i = 0; i < row; i++) {
			cin >> str;
			for (int j = 0; j < col; j++) {
				arr[i][j] = str[j];
				if (arr[i][j] == '@') {
					q.push({ i,j,0 });
					check[i][j][0] = 1;
				}
				else if (arr[i][j] == '*') {
					fire.push_back({ i, j, 0 });
					check[i][j][1] = 2;
				}
			}
		}
		//불이 퍼질예정->사람 이동->예정을 퍼진거로 바꾸기
		bool flag = false;
		while (1) {
			int len = fire.size();
			for(int i=0;i<len;i++){		//불 퍼질 예정
				cx = fire.front().x;
				cy = fire.front().y;
				cv = fire.front().val;
				fire.pop_front();
				for (int i = 0; i < 4; i++) {
					nx = cx + dx[i];
					ny = cy + dy[i];
					if (nx >= 0 && ny >= 0 && nx < col && ny < row && arr[ny][nx] != '#' &&check[ny][nx][1] == 0) {
						fire.push_back({ ny,nx,cv });
						check[ny][nx][1] = 1;
					}
				}
			}
			len = q.size();
			for(int k=0;k<len;k++) {
				cx = q.front().x;
				cy = q.front().y;
				cv = q.front().val;
				q.pop();
				for (int i = 0; i < 4; i++) {
					nx = cx + dx[i];
					ny = cy + dy[i];
					if (nx == -1 || ny == -1 || nx == col || ny == row) {
						flag = true;
						result = cv + 1;
						break;
					}
					if (nx >= 0 && ny >= 0 && nx < col && ny < row) {
						if (check[ny][nx][0] != 1 && check[ny][nx][1] == 0 && arr[ny][nx]=='.') {
							q.push({ ny,nx,cv + 1 });
							check[ny][nx][0] = 1;
						}
					}
				}
				if (flag)
					break;
			}
			if (flag) {
				cout << result << endl;
				break;
			}
			if (q.empty()) {
				cout << "IMPOSSIBLE" << endl;
				break;
			}
			for (int i = 0; i < fire.size(); i++) {
				fire[i].val = 2;
				check[fire[i].y][fire[i].x][1] = 2;
			}
		}
	}
	system("pause");
	return 0;
}