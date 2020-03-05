#include <iostream>
#include <queue>
using namespace std;
char arr[1000][1000];
int row, col, result = -1;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
struct info {
	int x, y;
};
info tmp;
int main() {
	cin >> row >> col;
	queue<info> fire;
	queue<info> q;
	int sx, sy;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'J') {
				if (i == 0 || i == row - 1 || j == 0 || j == col - 1) result = 1;
				tmp.x = j;
				tmp.y = i;
				q.push(tmp);
			}
			else if (arr[i][j] == 'F') {
				tmp.x = j;
				tmp.y = i;
				fire.push(tmp);
			}
		}
	}
	if (result > -1) cout << result;
	else {
		int cnt = 0;
		while (1) {
			int len = fire.size();
			for (int k = 0; k < len; k++) {
				int cx = fire.front().x;
				int cy = fire.front().y;
				fire.pop();
				for (int i = 0; i < 4; i++) {
					int nx = cx + dx[i];
					int ny = cy + dy[i];
					if (nx >= 0 && ny >= 0 && nx < col && ny < row && (arr[ny][nx] == '.' || arr[ny][nx]=='J')) {
						arr[ny][nx] = 'F';
						tmp.x = nx;
						tmp.y = ny;
						fire.push(tmp);
					}
				}
			}
			len = q.size();
			for (int k = 0; k < len; k++) {
				int cx = q.front().x;
				int cy = q.front().y;
				q.pop();
				for (int i = 0; i < 4; i++) {
					int nx = cx + dx[i];
					int ny = cy + dy[i];
					if (nx >= 0 && ny >= 0 && nx < col && ny < row && arr[ny][nx] == '.') {
						arr[ny][nx] = 'J';
						tmp.x = nx;
						tmp.y = ny;
						q.push(tmp);
					}
					else if (nx < 0 || ny < 0 || nx == col || ny == row) {		//탈출 가능
						result = cnt + 1;
						break;
					}
				}
				if (result != -1)	break;
			}
			if (q.empty()) break;		//사람이 더이상 갈 곳이 없는 경우
			if (result > -1) break;		//도착한경우
			cnt++;
		}
		if (result == -1) cout << "IMPOSSIBLE";
		else cout << result;
	}
	system("pause");
	return 0;
}