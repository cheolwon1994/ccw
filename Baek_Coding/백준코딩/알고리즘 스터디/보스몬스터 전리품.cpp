#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct info {
	int x, y;
};
info tmp;
int row, col, player, bx, by, val, hp;
char arr[1000][1000];
bool check[1000][1000] = { false, };
bool arrive[26] = { false, };
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int dps[26];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> row >> col >> player;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'B') {
				bx = j;
				by = i;
			}
		}
	for (int i = 0; i < player; i++) {
		char c;
		cin >> c >> val;
		dps[c - 'a'] = val;
	}
	cin >> hp;		//보스 체력

	int cnt = 0;	//참가한 플레이어
	//보스->플레이어까지의 거리
	queue<info> q;
	tmp.x = bx;
	tmp.y = by;
	q.push(tmp);
	check[by][bx] = true;	

	while (hp>0) {
		int len = q.size();
		for (int k = 0; k < len; k++) {
			int cx = q.front().x;
			int cy = q.front().y;
			q.pop();
			if ('a'<=arr[cy][cx] && arr[cy][cx] <= 'z') {		//플레이어 위치
				arrive[arr[cy][cx] - 'a'] = true;
				cnt++;
			}
			for (int i = 0; i < 4; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if (nx >= 0 && ny >= 0 && nx < col && ny < row && !check[ny][nx] && arr[ny][nx] != 'X') {
					check[ny][nx] = true;
					tmp.x = nx;
					tmp.y = ny;
					q.push(tmp);
				}
			}
		}
		for (int i = 0; i < player; i++) 
			if (arrive[i]) hp -= dps[i];	
	}
	cout << cnt;
	return 0;
}