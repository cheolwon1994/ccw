#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;
char arr[102][102];
int check[102][102][3];
int row, col;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
struct info {
	int x, y;
};
info tmp;
vector<info> people;
void meetPrison() {
	deque<info> q;
	tmp.x = 0;
	tmp.y = 0;
	q.push_front(tmp);
	check[0][0][0] = 0;
	int cx, cy, nx, ny, cv;
	while (!q.empty()) {
		cx = q.front().x;
		cy = q.front().y;
		cv = check[cy][cx][0];
		q.pop_front();
		for (int i = 0; i < 4; i++) {
			nx = cx + dx[i];
			ny = cy + dy[i];
			if (nx >= 0 && ny >= 0 && nx < col + 2 && ny < row + 2 && check[ny][nx][0]==-1) {
				if (arr[ny][nx] == '*') continue;
				tmp.x = nx;
				tmp.y = ny;
				if (arr[ny][nx] == '#') {
					check[ny][nx][0] = cv + 1;
					q.push_back(tmp);
				}
				else {
					check[ny][nx][0] = cv;
					q.push_front(tmp);
				}
			}
		}
	}
}

void goOut(int idx) {
	deque<info> q;
	tmp.x = people[idx].x;
	tmp.y = people[idx].y;
	q.push_back(tmp);
	check[tmp.y][tmp.x][idx+1] = 0;
	int cx, cy, nx, ny, cv;
	while (!q.empty()) {
		cx = q.front().x;
		cy = q.front().y;
		cv = check[cy][cx][idx+1];
		q.pop_front();
		for (int i = 0; i < 4; i++) {
			nx = cx + dx[i];
			ny = cy + dy[i];
			if (nx >= 0 && ny >= 0 && nx < col + 2 && ny < row + 2 && check[ny][nx][idx+1] == -1) {
				if (arr[ny][nx] == '*') continue;
				tmp.x = nx;
				tmp.y = ny;
				if (arr[ny][nx] == '#') {
					check[ny][nx][idx+1] = cv + 1;
					q.push_back(tmp);
				}
				else {
					check[ny][nx][idx+1] = cv;
					q.push_front(tmp);
				}
			}
		}
	}
}
int main() {
	int test;
	cin >> test;
	for (int t = 0; t < test; t++) {
		cin >> row >> col;
		memset(check, -1, sizeof(check));
		for (int i = 0; i < row + 2; i++)
			for (int j = 0; j < col + 2; j++) 
				arr[i][j] = '.';
			
		people.clear();
		for (int i = 1; i <= row; i++)
			for (int j = 1; j <= col; j++) {				
				cin >> arr[i][j];
				if (arr[i][j] == '$') {
					arr[i][j] == '.';
					tmp.x = j;
					tmp.y = i;				
					people.push_back(tmp);
				}
			}
		meetPrison();		//(0,0)에서 각각 죄수들을 만나러 갈 때 열어야 하는 문의 수
		for(int i=0;i<2;i++)
			goOut(i);
		int mini = 987654321;				
		for(int i=0;i<row+2;i++)
			for (int j = 0; j < col+2; j++) {
				if(arr[i][j]!='*'){
					int sum = 0;
					for (int k = 0; k < 3; k++) 
						sum += check[i][j][k];
					if (arr[i][j] == '#') sum -= 2;
					mini = min(mini, sum);
				}
			}
		cout << mini << endl;
	}
	system("pause");
	return 0;
}