#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
struct info {
	int y, x;
	char c;
};
info tmp;
char arr[50][50];
int num;
string str;
bool turned[50][50] = { false, };
int result = 0;

void find(int y,int x,int dir) {
	int cx, cy, nx, ny;
	char cv;
	tmp.x = x;
	tmp.y = y;
	tmp.c = arr[y][x];
	queue<info> q;
	q.push(tmp);
	bool check[50][50] = { false, };
	check[y][x] = true;
	int val = 1;
	while (!q.empty()) {
		cx = q.front().x;
		cy = q.front().y;
		cv = q.front().c;
		q.pop();
		for (int i = 0; i < 4; i+=2) {
			nx = cx + dx[(dir + i) % 4];
			ny = cy + dy[(dir + i) % 4];
			if (ny >= 0 && nx >= 0 && nx < num && ny < num && !check[ny][nx] && arr[ny][nx] == arr[y][x]) {
				check[ny][nx] = true;
				val += 1;
				tmp.x = nx;
				tmp.y = ny;
				tmp.c = arr[ny][nx];
				q.push(tmp);
			}
		}
	}
	result = max(result, val);
}

void start(int y, int x) {
	int cy, cx, ny, nx;
	char cv;
	cx = x;
	cy = y;
	for (int i = 0; i < 4; i++) {
		nx = cx + dx[i];
		ny = cy + dy[i];
		if (nx >= 0 && ny >= 0 && nx < num && ny < num && !turned[ny][nx]) {
			cv = arr[cy][cx];
			arr[cy][cx] = arr[ny][nx];
			arr[ny][nx] = cv;
			for (int j = 0; j < 2; j++)
				find(ny, nx, j);
			for (int j = 0; j < 2; j++)
				find(cy, cx, j);
			arr[ny][nx] = arr[cy][cx];
			arr[cy][cx] = cv;
		}
	}
	turned[y][x] = true;
}

int main() {
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> str;
		for (int j = 0; j < num; j++) 
			arr[i][j] = str[j];		
	}
	for(int i=0;i<num;i++)
		for(int j=0;j<num;j++)
			start(i,j);
	cout << result;
	system("pause");
	return 0;
}