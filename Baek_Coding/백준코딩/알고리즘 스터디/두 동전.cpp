#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct info {
	int x, y;
};
info tmp;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int row, col, result = 11;
char arr[20][20];
vector<info> coin[2];
vector<int> order;

void start() {
	int t_result;
	int c1x = coin[0][0].x;
	int c1y = coin[0][0].y;
	int c2x = coin[1][0].x;
	int c2y = coin[1][0].y;
	int n1x, n1y, n2x, n2y, out;
	for (int t = 0; t < 10; t++) {
		if (t > result) break;				//시간 단축 위해 사용
		int dir = order[t];
		out = 0;		//0: 둘다 안나감, 1: 하나만 나감, 2: 둘다 나감
		n1x = c1x + dx[dir];
		n1y = c1y + dy[dir];
		if (n1x >= 0 && n1y >= 0 && n1x < col && n1y < row) {
			if (arr[n1y][n1x] == '.') {
				c1x = n1x;
				c1y = n1y;
			}
		}
		else
			out++;
		n2x = c2x + dx[dir];
		n2y = c2y + dy[dir];
		if (n2x >= 0 && n2y >= 0 && n2x < col && n2y < row) {
			if (arr[n2y][n2x] == '.') {
				c2x = n2x;
				c2y = n2y;
			}
		}
		else
			out++;
		if (out == 0) continue;
		else if (out == 1) {
			t_result = t + 1;
			break;
		}
		else if (out == 2) 	break;		//더 이상 진행 불가
		
	}
	if (out==1) 
		result = min(result, t_result);	
}

void dfs(int cnt) {
	if(cnt == 10) {
		start();
		return;
	}
	for (int i = 0; i < 4; i++) {
		order.push_back(i);
		dfs(cnt + 1);
		order.pop_back();
	}
}

int main() {
	cin >> row >> col;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'o') {
				arr[i][j] = '.';
				tmp.x = j;
				tmp.y = i;
				if (coin[0].empty())
					coin[0].push_back(tmp);
				else
					coin[1].push_back(tmp);
			}
		}
	dfs(0);
	if (result == 11) result = -1;
	cout << result;
	system("pause");
	return 0;
}