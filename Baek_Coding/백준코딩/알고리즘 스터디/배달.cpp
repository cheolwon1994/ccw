#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
using namespace std;
struct info {
	int x, y, dir, del, val;
};
info tmp;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
char arr[50][50];
int check[50][50][4][4];		//y,x,dir,deliver 성공 수
int row, col;
vector<info> deliver;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	queue<info> q;
	cin >> row >> col;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) {
			for (int m = 0; m < 4; m++) 
				for(int l=0;l<4;l++)
					check[i][j][m][l] = 987654321;			
			cin >> arr[i][j];
			if (arr[i][j] == 'S') {
				arr[i][j] = '.';
				tmp.x = j;
				tmp.y = i;
				tmp.dir = -1;
				tmp.val = 0;
				tmp.del = 0;
				q.push(tmp);
				for (int k = 0; k < 4; k++)
					check[i][j][k][0] = 0;
			}
			else if (arr[i][j] == 'C') {
				tmp.x = j;
				tmp.y = i;
				deliver.push_back(tmp);
			}
		}
	int result = -1;
	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		int cd = q.front().dir;
		int cdel = q.front().del;
		int cv = q.front().val;
		q.pop();
		if (cdel == 3) {
			result = cv;
			break;
		}
		for (int i = 0; i < 4; i++) {
			if (i == cd) continue;
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			char nv = arr[ny][nx];
			if (nx >= 0 && ny >= 0 && nx < col && ny < row && nv != '#') {
				if (nv == '.' && check[ny][nx][i][cdel]>cv+1) {
					check[ny][nx][i][cdel] = cv + 1;
					tmp.x = nx;
					tmp.y = ny;
					tmp.del = cdel;
					tmp.val = cv + 1;
					tmp.dir = i;
					q.push(tmp);
				}
				else if (nv == 'C') {
					int plus = 0;
					for (int k = 0; k < deliver.size(); k++) {
						if (nx == deliver[k].x && ny == deliver[k].y) {
							plus = pow(2, k);
							break;
						}
					}
					if (cdel != plus && check[ny][nx][i][cdel + plus] > cv + 1) {
						check[ny][nx][i][cdel + plus] = cv + 1;
						tmp.x = nx;
						tmp.y = ny;
						tmp.del = cdel + plus;
						tmp.val = cv + 1;
						tmp.dir = i;
						q.push(tmp);
					}
				}
			}
		}
	}
	cout << result;
	return 0;
}