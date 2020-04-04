#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int row, col, before, result = 0;
bool finish = false;
int arr[100][100];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
struct info {
	int x, y;
};
info tmp;
queue<info> q;

void cal() {
	int t_result = 0;
	for (int i = 0; i < row; i++) 
		for (int j = 0; j < col; j++)
			if (arr[i][j] == 1)
				t_result++;
	if (t_result == 0) finish = true;
	else before = t_result;
}

void spread() {
	int len = q.size();
	for(int k=0;k<len;k++){
		int cx = q.front().x;
		int cy = q.front().y;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && ny >= 0 && nx < col && ny < row && arr[ny][nx]==1) {
				tmp.x = nx;
				tmp.y = ny;
				q.push(tmp);
				arr[ny][nx] = 0;
			}
		}
	}
}

void find_uncheck() {
	bool check[100][100] = { false, };
	queue<info> tq;
	tmp.x = 0;
	tmp.y = 0;
	tq.push(tmp);
	q.push(tmp);
	check[0][0] = true;
	while (!tq.empty()) {
		int cx = tq.front().x;
		int cy = tq.front().y;
		tq.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && ny >= 0 && nx < col && ny < row && !check[ny][nx] && arr[ny][nx] == 0) {
				check[ny][nx] = true;
				tmp.x = nx;
				tmp.y = ny;
				q.push(tmp);
				tq.push(tmp);
			}
		}
	}
}

int main() {
	cin >> row >> col;
	for (int i = 0; i < row; i++) 
		for (int j = 0; j < col; j++) 
			cin >> arr[i][j];		
	
	while (1) {
		result++;
		cal();
		if (finish) {
			result -= 1;
			break;
		}
		find_uncheck();
		spread();
	}
	cout << result << '\n' << before;
	system("pause");
	return 0;
}