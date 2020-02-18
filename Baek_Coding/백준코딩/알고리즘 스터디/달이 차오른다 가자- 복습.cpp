#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
char arr[50][50];
bool check[50][50][65];
int row, col, sx, sy;
struct info {
	int x, y, val, keySum;
	vector<char> k;
};
info tmp;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

int main() {
	cin >> row >> col;
	queue<info> q;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == '0') {
				arr[i][j] = '.';
				sx = j; sy = i;
				tmp.x = j;
				tmp.y = i;
				tmp.keySum = 0;
				tmp.val = 0;
				q.push(tmp);
			}
		}
	int result = -1;
	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		int cv = q.front().val;
		int ck = q.front().keySum;
		vector<char> v = q.front().k;
		q.pop();
		if (arr[cy][cx] == '1') {
			result = cv;
			break;
		}
		for (int i = 0; i < 4; i++) {
			vector<char> tt = v;
			int num = ck;
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && ny >= 0 && nx < col && ny < row ) {
				if (!check[ny][nx][num]) {
					if (arr[ny][nx] == '.' || arr[ny][nx] == '1') {
						check[ny][nx][num] = true;
						tmp.keySum = num;
						tmp.k = tt;
						tmp.x = nx;
						tmp.y = ny;
						tmp.val = cv + 1;
						q.push(tmp);
					}
					else if (arr[ny][nx] == '#') continue;
					else if ('a' <= arr[ny][nx] && arr[ny][nx] <= 'f') {
						bool add = true;
						for (int j = 0; j < tt.size(); j++) {
							if (tt[j] == arr[ny][nx]) {
								add = false;
								break;
							}
						}
						if (add) {
							tt.push_back(arr[ny][nx]);
							num += pow(2, arr[ny][nx] - 'a');
						}
						tmp.k = tt;
						tmp.keySum = num;
						tmp.x = nx;
						tmp.y = ny;
						tmp.val = cv + 1;
						check[ny][nx][num] = true;
						q.push(tmp);
						
					}
					else if ('A' <= arr[ny][nx] && arr[ny][nx] <= 'F') {
						bool avail = false;
						for (int j = 0; j < tt.size(); j++) {
							if (tt[j] - 'a' == arr[ny][nx] - 'A') {
								avail = true;
								break;
							}
						}
						if (avail) {
							check[ny][nx][num] = true;
							tmp.keySum = num;
							tmp.k = tt;
							tmp.x = nx;
							tmp.y = ny;
							tmp.val = cv + 1;
							q.push(tmp);
						}
					}
				}
			}
		}
	}
	cout << result;
	system("pause");
	return 0;
}