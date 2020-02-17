#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;
int row, col;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
struct info {
	int x, y;
};
info tmp;
int sx, sy;
char arr[1001][1001];	
bool check[1001][1001];
int main() {
	int test;
	cin >> test;
	for (int t = 0; t < test; t++) {
		cin >> col >> row;
		memset(check, false, sizeof(check));
		int result = 0;
		queue<info> fire;
		queue<info> q;
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++) {
				cin >> arr[i][j];
				if (arr[i][j] == '*') {
					tmp.x = j;
					tmp.y = i;
					fire.push(tmp);
				}
				else if (arr[i][j] == '@') {
					tmp.x = j;
					tmp.y = i;
					q.push(tmp);
					arr[i][j] = '.';
					check[i][j] = true;
				}
			}
		bool finish = false;
		while (1) {
			//불 -> 번질곳 찾기
			int len = fire.size();
			for(int i=0;i<len;i++){
				int cx = fire.front().x;
				int cy = fire.front().y;
				fire.pop();
				for (int i = 0; i < 4; i++) {
					int nx = cx + dx[i];
					int ny = cy + dy[i];
					if (nx >= 0 && ny >= 0 && nx < col && ny < row && arr[ny][nx] =='.') {
						tmp.x = nx;
						tmp.y = ny;
						fire.push(tmp);
						arr[ny][nx] = '*';
					}
				}
			}
			result++;
			//사람 움직이기
			len = q.size();
			if(len==0) break;
			for (int i = 0; i < len; i++) {
				int cx = q.front().x;
				int cy = q.front().y;
				q.pop();
				if (cy == 0 || cx == 0 || cx == col - 1 || cy == row - 1) {
					finish = true;
					break;
				}
				for (int j = 0; j < 4; j++) {
					int nx = cx + dx[j];
					int ny = cy + dy[j];
					if (nx >= 0 && ny >= 0 && nx < col && ny < row && arr[ny][nx] == '.' && !check[ny][nx]) {
						check[ny][nx] = true;
						tmp.x = nx;
						tmp.y = ny;
						q.push(tmp);
					}
				}
			}
			if (finish)
				break;
		}
		if(finish)	cout << result << endl;
		else cout << "IMPOSSIBLE" << endl;
	}
	system("pause");
	return 0;
}