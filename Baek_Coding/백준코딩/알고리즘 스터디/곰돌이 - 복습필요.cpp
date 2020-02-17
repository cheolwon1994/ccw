#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;
char arr[801][801];
int check[801][801];
int num, jump, sx, sy;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

struct info {
	int x, y, val;
};
info tmp;
queue<info> bee;

bool start(int mid) {
	if (mid*jump >= check[sy][sx]) return false;
	bool flag[801][801] = { false, };
	queue<info> poo;
	tmp.x = sx;
	tmp.y = sy;
	tmp.val = mid*jump;
	flag[sy][sx] = true;
	poo.push(tmp);
	while (!poo.empty()) {
		int cx = poo.front().x;
		int cy = poo.front().y;
		int cv = poo.front().val;
		poo.pop();
		if (arr[cy][cx] == 'D') return true;		
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && ny >= 0 && nx < num && ny < num && !flag[ny][nx] && check[ny][nx]>cv+1 && arr[ny][nx]!='T'){
				flag[ny][nx] = true;
				tmp.x = nx;
				tmp.y = ny;
				tmp.val = cv + 1;
				poo.push(tmp);
			}
		}
	}
	return false;
}

int main() {
	cin >> num >> jump;
	memset(check, -1, sizeof(check));
	for (int i = 0; i < num; i++)
		for (int j = 0; j < num; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'H') {
				tmp.x = j;
				tmp.y = i;
				tmp.val = 0;
				bee.push(tmp);
				check[i][j] = 0;
			}
			else if (arr[i][j] == 'M') {
				sx = j;
				sy = i;
				arr[i][j] = 'G';
			}
			else if (arr[i][j] == 'D') 
				check[i][j] = num * num*jump;		
		}
	int low = 0, high = num*num*2, ans = -1;

	while (!bee.empty()) {
		int cx = bee.front().x;
		int cy = bee.front().y;
		int cv = bee.front().val;
		bee.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && ny >= 0 && nx < num &&ny < num && check[ny][nx]==-1 && arr[ny][nx]=='G') {
				check[ny][nx] = cv+jump;
				tmp.x = nx;
				tmp.y = ny;
				tmp.val = cv + jump;
				bee.push(tmp);
			}
		}
	}
	int mid;
	while (low <= high) {
		mid = low + (high - low) / 2;
		if (start(mid)) { ans = max(ans, mid); low = mid + 1; }
		else
			high = mid - 1;
	}
	cout << ans;
	system("pause");
	return 0;
}