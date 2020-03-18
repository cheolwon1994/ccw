#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
struct info {
	int x, y, val;
};
info tmp;
int row, col, result = 0;
int arr[300][300];

int main() {
	cin >> row >> col;
	vector<info> ice;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) {
			cin >> arr[i][j];
			if (arr[i][j] != 0) {
				tmp.x = j;
				tmp.y = i;
				tmp.val = arr[i][j];
				ice.push_back(tmp);
			}	
		}
	while (1) {
		result++;
		vector<info> dup;
		//빙산을 녹인다
		int len = ice.size();
		for(int k=0;k<len;k++){
			int cx = ice[k].x;
			int cy = ice[k].y;
			for (int i = 0; i < 4; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if (nx >= 0 && ny >= 0 && nx < col & ny < row && arr[ny][nx] == 0) {
					ice[k].val--;
					if (ice[k].val == 0) 
						break;					
				}
			}
		}
		int sx = -1, sy = -1;
		for (int k = 0; k < len; k++) {
			arr[ice[k].y][ice[k].x] = ice[k].val;
			if (ice[k].val != 0) {
				tmp.x = ice[k].x;
				tmp.y = ice[k].y;
				tmp.val = ice[k].val;
				dup.push_back(tmp);
				if (sx == -1 && sy == -1) {
					sx = tmp.x;
					sy = tmp.y;
				}
			}
		}
		if (dup.empty()) {		//빙산이 다 녹은 경우
			result = 0;
			break;		
		}
		ice.clear();
		ice = dup;
		bool check[300][300] = { false, };
		queue<info> q;
		tmp.x = sx;
		tmp.y = sy;
		q.push(tmp);
		int cnt = 1;
		check[sy][sx] = true;
		while (!q.empty()) {
			int cx = q.front().x;
			int cy = q.front().y;
			q.pop();
			for (int k = 0; k < 4; k++) {
				int nx = cx + dx[k];
				int ny = cy + dy[k];
				if (nx >= 0 && ny >= 0 && nx < col & ny < row && arr[ny][nx]>0 && !check[ny][nx]) {
					check[ny][nx] = true;
					tmp.x = nx;
					tmp.y = ny;
					q.push(tmp);
					cnt++;
				}
			}
		}
		if (cnt!=ice.size()) break;		//빙산이 2구역 이상으로 나눠진 경우
	}
	cout << result;
	system("pause");
	return 0;
}