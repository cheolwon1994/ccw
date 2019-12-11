#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int arr[200][200];
int check[200][200][32];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int nightx[8] = { 1,2,2,1,-1,-2,-2,-1 };
int nighty[8] = { -2,-1,1,2,2,1,-1,-2 };
int num, row, col;
int result = 0;
struct info {
	int y,x,avail,val;
};
info tmp;
queue<info> q;

int main() {
	cin >> num >> col >> row;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			cin >> arr[i][j];
	q.push({ 0,0,0,0 });
	for(int i=0;i<31;i++)
		check[0][0][i] = 1;
	bool flag = false;
	int cx, cy, cv, ca, nx, ny;
	if (row == 1 && col == 1 && arr[0][0] == 1)
		cout << 0;
	else {
		while (!q.empty()) {
			cx = q.front().x;
			cy = q.front().y;
			ca = q.front().avail; 
			cv = q.front().val;
			q.pop();
			if (num - ca > 0) {		//말로 이동 가능
				for (int i = 0; i < 8; i++) {
					nx = cx + nightx[i];
					ny = cy + nighty[i];
					if (nx >= 0 && ny >= 0 && nx < col && ny < row && check[ny][nx][ca + 1] != 1 && arr[ny][nx] != 1) {
						if (ny == row - 1 && nx == col - 1) {
							flag = true;
							result = cv + 1;
							break;
						}
						check[ny][nx][ca + 1] = 1;
						q.push({ ny, nx, ca + 1, cv + 1 });
					}
				}
				if (flag)
					break;
			}
			for (int i = 0; i < 4; i++) {
				nx = cx + dx[i];
				ny = cy + dy[i];
				if (nx >= 0 && ny >= 0 && nx < col && ny < row && check[ny][nx][ca] != 1 && arr[ny][nx] != 1) {
					if (ny == row - 1 && nx == col - 1) {
						flag = true;
						result = cv + 1;
						break;
					}
					check[ny][nx][ca] = 1;
					q.push({ ny,nx,ca,cv + 1 });
				}
			}
			if (flag)
				break;
		}
		if (flag)
			cout << result;
		else
			cout << -1;
	}
	system("pause");
	return 0;
}