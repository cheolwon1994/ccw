#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int row, col;
int cnt = 1;		//섬의 갯수
int arr[10][10];
struct info {
	int x, y, val;
};
info tmp;
int result = 5000;
int cx, cy, nx, ny, cv;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
vector<info> v[7];		//바다와 맞닿아있는 섬부분을 저장
bool island[7] = { false, };	//연결된 섬

void mv(int y, int x, vector<int> &avail, vector<int> &b_len, int dir) {
	cx = x;
	cy = y;
	for (int i = 1;; i++) {
		nx = cx + dx[dir] * i;
		ny = cy + dy[dir] * i;
		if (nx >= 0 && ny >= 0 && nx < col && ny < row) {
			if (arr[ny][nx] > 0) {
				if (i - 1 > 1) {
					avail[dir] = arr[ny][nx];
					b_len[dir] = i - 1;
				}
				else
					avail[dir] = 0;
				break;
			}
			else if (arr[ny][nx] == 0)
				continue;
		}
		else {
			avail[dir] = 0;
			break;
		}
	}
	for (int i = 1;; i++) {
		nx = cx + dx[dir+2] * i;
		ny = cy + dy[dir+2] * i;
		if (nx >= 0 && ny >= 0 && nx < col && ny < row) {
			if (arr[ny][nx] > 0) {
				if (i - 1 > 1) {
					avail[dir + 2] = arr[ny][nx];
					b_len[dir + 2] = i - 1;
				}
				else
					avail[dir+2] = 0;
				break;
			}
			else if (arr[ny][nx] == 0)
				continue;
		}
		else {
			avail[dir + 2] = 0;
			break;
		}
	}
}

void check_attach(int len) {		//1부터 시작  방향
	bool finish = true;
	for (int i = 1; i <= cnt; i++) {
		if (!island[i]) {
			finish = false;
			break;
		}
	}
	if (finish) {
		result = min(result, len);
		return;
	}
	else {
		for (int i = 1; i <= cnt; i++) {
			if (island[i]) {
				for (int j = 0; j < v[i].size(); j++) {
					if (v[i][j].val != 0) {
						vector<int> avail(4, 0);		//연결되는 섬
						vector<int> b_len(4, 0);	//연결되는 섬까지의 거리(2이상)
						mv(v[i][j].y, v[i][j].x, avail, b_len, 0);		//위아래 확인
						mv(v[i][j].y, v[i][j].x, avail, b_len, 1);		//좌우 확인
						int non_avail = 0;				//다리 지을 수 없는 상태
						for (int k = 0; k < 4; k++) {
							non_avail += avail[k];
							if (b_len[k] > 0 && island[avail[k]] == false) {
								//잇는다
								island[avail[k]] = true;
								check_attach(len + b_len[k]);
								island[avail[k]] = false;
							}
						}
						if (non_avail == 0)
							v[i][j].val = 0;
					}
				}
			}
		}
	}
}

void name_island(){
	bool check[10][10] = { false, };
	bool check2[10][10] = { false, };
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (arr[i][j] == -1 && check[i][j]==false) {
				queue<info> q;
				arr[i][j] = cnt;
				tmp.x = j;
				tmp.y = i;
				tmp.val = cnt++;
				q.push(tmp);
				while (!q.empty()) {
					cx = q.front().x;
					cy = q.front().y;
					cv = q.front().val;
					q.pop();
					bool flag = false;
					for (int k = 0; k < 4; k++) {
						nx = cx + dx[k];
						ny = cy + dy[k];
						if (nx >= 0 && ny >= 0 && nx < col && ny < row) {
							if (arr[ny][nx] == 0 && !flag && !check2[cy][cx]) {
								flag = true;
								tmp.x = cx;
								tmp.y = cy;
								tmp.val = cv;
								check2[cy][cx] = true;
								v[cnt - 1].push_back(tmp);
							}
							if (!check[ny][nx] && arr[ny][nx] == -1) {
								check[ny][nx] = true;
								arr[ny][nx] = cv;
								tmp.x = nx;
								tmp.y = ny;
								tmp.val = cv;
								q.push(tmp);						
							}
						}
					}
				}
			}
		}
	}
	cnt -= 1;
	island[1] = true;
	check_attach(0);
}

int main() {
	cin >> row >> col;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1)
				arr[i][j] = -1;
		}
	name_island();
	if (result == 5000)
		cout << -1;
	else
		cout << result;
	return 0;
}
