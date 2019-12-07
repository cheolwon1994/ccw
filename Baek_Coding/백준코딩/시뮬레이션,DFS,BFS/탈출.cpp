#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
char arr[50][50];		//찰 예정: 1, 찬 이후: 2
bool flag = false;
int result = 0;
int row, col;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
struct info {
	int x;
	int y;
};
info tmp;
queue<info> target;
queue<info> water;
queue<info> pre_water;
void start() {

}

int main() {
	cin >> row >> col;
	int x, y;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'S') {
				tmp.x = j;
				tmp.y = i;
				target.push(tmp);
			}
			else if (arr[i][j] == '*') {
				tmp.x = j;
				tmp.y = i;
				water.push(tmp);
				arr[i][j] = '2';
			}
		}
	while (1) {
		//물이 퍼질곳 구하기
		int cx, cy, nx, ny;
		while (!water.empty()) {
			cx = water.front().x;
			cy = water.front().y;
			water.pop();
			for (int i = 0; i < 4; i++) {
				nx = cx + dx[i];
				ny = cy + dy[i];
				if (nx >= 0 && ny >= 0 && nx < col && ny < row) {
					if (arr[ny][nx] != 'D' && arr[ny][nx] != 'X' && arr[ny][nx] != '1' && arr[ny][nx] != '2') {
						tmp.x = nx;
						tmp.y = ny;
						pre_water.push(tmp);
						arr[ny][nx] = '1';
					}
				}
			}
		}
		//고슴도치 움직이기
		int all = target.size();
		bool move_avail = true;
		for (int i = 0; i <= all; i++) {
			if (i == all) {
				if (target.empty()) {		//갈 수 있는곳이 없는 경우
					move_avail = false;
					break;
				}
			}
			else {
				cx = target.front().x;
				cy = target.front().y;
				target.pop();
				for (int j = 0; j < 4; j++) {
					nx = cx + dx[j];
					ny = cy + dy[j];
					if (nx >= 0 && ny >= 0 && nx < col && ny < row) {
						if (arr[ny][nx] == 'D') {		//목적지 도착
							flag = true;
							result++;
							break;
						}
						else if (arr[ny][nx] == '.') {		//이동 가능한 장소
							tmp.x = nx;
							tmp.y = ny;
							arr[ny][nx] = 'S';
							target.push(tmp);
						}
					}
				}
				if (flag)
					break;
			}
		}
		if (!move_avail)
			break;
		if (flag)
			break;
		//물이 퍼질곳-> 퍼진것으로 바꾸기
		while (!pre_water.empty()) {
			cx = pre_water.front().x;
			cy = pre_water.front().y;
			pre_water.pop();
			tmp.x = cx;
			tmp.y = cy;
			water.push(tmp);
			arr[cy][cx] = '2';
		}
		result++;
	}

	if (!flag)
		cout << "KAKTUS";
	else
		cout << result;
	system("pause");
	return 0;
}