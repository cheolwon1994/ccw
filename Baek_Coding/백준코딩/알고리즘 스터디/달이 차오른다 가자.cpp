#define MAX 987654321
#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <math.h>
using namespace std;
int row, col;
char arr[50][50];
bool check[50][50][64];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
struct info {
	int x, y, val, sum;
	vector<char> k;
};
info tmp;
int result = MAX;
int main() {
	int sx, sy;
	cin >> row >> col;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == '0') {
				sx = j;
				sy = i;
				arr[i][j] = '.';
			}
		}

	queue<info> q;
	tmp.x = sx;
	tmp.y = sy;
	tmp.val = 0;
	tmp.sum = 0;
	q.push(tmp);
	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		int cs = q.front().sum;
		vector<char> ck = q.front().k;
		int cv = q.front().val;
		if (arr[cy][cx] == '1') {
			result = min(result, cv);
			break;
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			vector<char> tt = ck;
			int s = cs;
			if (nx >= 0 && ny >= 0 && nx < col && ny < row) {				
				if (!check[ny][nx][s]) {
					if (arr[ny][nx] == '.' || arr[ny][nx]=='1') {
						check[ny][nx][s] = true;
						tmp.x = nx;
						tmp.y = ny;
						tmp.k = tt;
						tmp.sum = s;
						tmp.val = cv + 1;
						q.push(tmp);
					}
					else if ('a' <= arr[ny][nx] && arr[ny][nx] <= 'f') {
						bool have = false;
						for (int i = 0; i < tt.size(); i++) {
							if (tt[i] == arr[ny][nx]) {
								have = true;
								break;
							}
						}
						if (!have) {
							tt.push_back(arr[ny][nx]);
							int t_sum = pow(2, arr[ny][nx] - 'a');
							s += t_sum;
						}
						tmp.k = tt;
						check[ny][nx][s] = true;
						tmp.x = nx;
						tmp.y = ny;
						tmp.sum = s;
						tmp.val = cv + 1;
						q.push(tmp);
					}
					else if ('A' <= arr[ny][nx] && arr[ny][nx] <= 'F') {
						bool avail = false;
						for (int k = 0; k < ck.size(); k++)
							if (ck[k]-'a' == arr[ny][nx]-'A') {
								avail = true;
								break;
							}
						if (avail) {
							check[ny][nx][s] = true;
							tmp.x = nx;
							tmp.y = ny;
							tmp.k = tt;
							tmp.sum = s;
							tmp.val = cv + 1;
							q.push(tmp);
						}
					}
				}
			}
		}
	}
	if (result == MAX) cout << -1;
	else cout << result;
	system("pause");
	return 0;
}