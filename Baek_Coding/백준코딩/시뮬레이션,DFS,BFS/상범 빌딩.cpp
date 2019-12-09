#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int height, row, col, result, cx, cy, cz, cv, nx, ny, nz;
bool flag = false;
char arr[30][30][30];
int check[30][30][30];
int dx[6] = { 0,1,0,-1,0,0 };
int dy[6] = { -1,0,1,0,0,0 };
int dz[6] = { 0,0,0,0,-1,1 };

struct info {
	int x;
	int y;
	int z;
	int val;
};
info tmp;
int main() {
	while (1) {
		cin >> height >> row >> col;
		if (height == 0 && row == 0 && col == 0)
			break;
		queue<info> q;
		result = 0;
		flag = false;
		for (int z = 0; z < height; z++)
			for (int i = 0; i < row; i++)
				for (int j = 0; j < col; j++)
					check[z][i][j] = 0;

		for (int z = 0; z < height; z++) {
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {
					cin >> arr[z][i][j];
					if (arr[z][i][j] == 'S') {
						tmp.x = j;
						tmp.y = i;
						tmp.z = z;
						tmp.val = 0;
						q.push(tmp);
						check[z][i][j] = 1;
					}
				}
			}
		}
		while (!q.empty()) {
			cx = q.front().x;
			cy = q.front().y;
			cz = q.front().z;
			cv = q.front().val;
			q.pop();
			for (int i = 0; i < 6; i++) {
				nx = cx + dx[i];
				ny = cy + dy[i];
				nz = cz + dz[i];
				if (nx >= 0 && ny >= 0 && nz >= 0 && nx < col && ny < col && nz < height) {
					if (check[nz][ny][nx] != 1) {
						if (arr[nz][ny][nx] == 'E') {
							flag = true;
							result = cv + 1;
							break;
						}
						else if (arr[nz][ny][nx] == '.') {
							tmp.x = nx;
							tmp.y = ny;
							tmp.z = nz;
							tmp.val = cv + 1;
							q.push(tmp);
							check[nz][ny][nx] = 1;
						}
					}
				}
			}
			if (flag)
				break;
		}
		if (flag)
			cout << "Escaped in " << result << " minute(s)." << endl;
		else
			cout << "Trapped!" << endl;
		if (!q.empty())
			q.pop();
	}
	system("pause");
	return 0;
}