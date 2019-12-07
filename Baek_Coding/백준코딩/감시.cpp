#define CRT_NO_SECURE_WARNINGS
#define MAX 987654321
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
using namespace std;
int row, col;
int arr[8][8];
int dup[8][8];
int x[4] = { 0,1,0,-1 };
int y[4] = { -1,0,1,0 };
struct info {
	int x;
	int y;
};
vector <info> check[8][8];
info tmp;
vector<info> cctv;
int total_c;
int ans = MAX;

void change(int cx, int cy, int j) {
	int nx, ny;
	int temp = 1;
	//감시할 수 있는 구역으로 설정
	while (1) {
		nx = cx + x[j] * temp;
		ny = cy + y[j] * temp;
		if (nx < 0 || ny < 0 || nx >= col || ny >= row || arr[ny][nx] == 6)
			break;
		if (arr[ny][nx] == 0) {
			tmp.x = nx;
			tmp.y = ny;
			check[cy][cx].push_back(tmp);
		}
		temp++;
	}
	/*cout << "change 수행중:"  << endl;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}*/
}

void dfs(int cnt) {
	if (cnt == total_c) {
		//사각지대 계산
		for (int i = 0; i < row; i++)
			memset(dup[i], 0, sizeof(dup[i]));
		memcpy(dup, arr, sizeof(arr));
	
		for (int i = 0; i < cctv.size(); i++) {
			for (int k = 0; k < check[cctv[i].y][cctv[i].x].size(); k++) {
				dup[check[cctv[i].y][cctv[i].x][k].y][check[cctv[i].y][cctv[i].x][k].x] = -1;
			}	
		}
		int temp=0;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (dup[i][j] == 0)
					temp += 1;
			}
		}
		/*cout << "계산 :\n";
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++)
				cout << dup[i][j] << " ";
			cout << endl;
		}
		cout << endl;*/
		ans = min(ans, temp);
		return;
	}
	for (int i = cnt; i < cctv.size(); i++) {
		int ct,cx,cy;
		cx = cctv[i].x;
		cy = cctv[i].y;
		ct = arr[cy][cx];
		if (ct == 1) {		//한방향 4번씩
			for (int j = 0; j < 4; j++) {
				change(cx, cy, j);
				dfs(cnt + 1);
				check[cy][cx].clear();
			}		
		}
		else if (ct == 2) {			//반대방향 2개가능
			for (int j = 0; j < 2; j ++) {
				change(cx, cy, j);
				change(cx, cy, j + 2);
				dfs(cnt + 1);
				check[cy][cx].clear();
			}
		}
		else if (ct == 3) {			//직각방향 4개 가능
			for (int j = 0; j < 4; j++) {
				change(cx, cy, j % 4);
				change(cx, cy, (j + 1) % 4);
				dfs(cnt + 1);
				check[cy][cx].clear();
			}
		}
		else if (ct == 4) {		//뻐큐 모양 4개 가능
			for (int j = 0; j < 4; j++) {
				change(cx, cy, j % 4);
				change(cx, cy, (j + 1) % 4);
				change(cx, cy, (j + 2) % 4);
				dfs(cnt + 1);
				check[cy][cx].clear();
			}
		}
		else if (ct == 5) {		//전 방향 1개 가능
			change(cx, cy, 0);
			change(cx, cy, 1);
			change(cx, cy, 2);
			change(cx, cy, 3);
			dfs(cnt + 1);
			check[cy][cx].clear();
		}
		break;
	}
}

int main() {
	cin >> row >> col;
	cctv.clear();
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) {
			cin >> arr[i][j];
			if (1 <= arr[i][j] && arr[i][j] <= 5) {
				tmp.x = j;
				tmp.y = i;
				cctv.push_back(tmp);
			}
		}
	total_c = cctv.size();
	dfs(0);
	cout << ans;
	system("PAUSE");
	return 0;
}