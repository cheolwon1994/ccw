#define MAX 987654321
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
struct info {
	int x, y, state, val, made;
};
info tmp;
int arr[10][10], num, bridge, result;
int check[10][10][2];		//0: 주기가 M인 오작교 아직 안만듬, 1: 만듬
int dx[4] = { 0,1,0,-1 };	
int dy[4] = { -1,0,1,0 };

int main() {
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		cin >> num >> bridge;
		for (int i = 0; i < num; i++)
			for (int j = 0; j < num; j++) {
				cin >> arr[i][j];
				check[i][j][0] = MAX;
				check[i][j][1] = MAX;
			}
		result = MAX;
		queue<info> q;
		tmp.x = 0;
		tmp.y = 0;
		tmp.state = 0;
		tmp.val = 0;
		tmp.made = 0;
		q.push(tmp);
		check[0][0][0] = 0;
		while (!q.empty()) {
			int cx = q.front().x;
			int cy = q.front().y;
			int cv = q.front().val;
			int cs = q.front().state;
			int cm = q.front().made;
			q.pop();
			if (cx == num - 1 && cy == num - 1) {
				result = min(result, cv);
				continue;
			}
			for (int k = 0; k < 4; k++) {
				int nx = cx + dx[k];
				int ny = cy + dy[k];
				if (nx >= 0 && ny >= 0 && nx < num && ny < num) {
					if (arr[ny][nx] == 1 && check[ny][nx][cm] > cv + 1) {
						check[ny][nx][cm] = cv + 1;
						tmp.x = nx;
						tmp.y = ny;
						tmp.val = cv + 1;
						tmp.state = 0;
						tmp.made = cm;
						q.push(tmp);
					}
					else if (arr[ny][nx] == 0) {
						if (cm == 1) continue;		//이미 오작교를 하나 만든 경우
						if (cs == 1) {
							tmp.x = cx;
							tmp.y = cy;
							tmp.state = 0;
							tmp.val = cv + 1;
							tmp.made = cm;
							q.push(tmp);
							continue;
						}
						if (check[ny][nx][1]>cv+1) {
							int nnx = nx + dx[k], nny = ny + dy[k];
							if (nnx >= 0 && nny >= 0 && nnx < num && nny < num && check[nny][nnx][1] > cv + 2 && arr[nny][nnx] == 1) {
								if ((cv + 1) % bridge == 0) {
									check[ny][nx][1] = cv + 1;
									check[nny][nnx][1] = cv + 2;
									tmp.x = nnx;
									tmp.y = nny;
									tmp.state = 1;
									tmp.val = cv + 2;
									tmp.made = 1;
									q.push(tmp);
								}
								else {
									int v = bridge - (cv + 1) % bridge;
									tmp.x = cx;
									tmp.y = cy;
									tmp.state = 0;
									tmp.val = cv + v;
									tmp.made = cm;
									q.push(tmp);
								}
							}
						}
					}					
					else if (arr[ny][nx] > 1) {
						//방금 오작교를 건넜거나, 아직 오작교가 쉬는 중인 경우
						if (cs == 1) {
							tmp.x = cx;
							tmp.y = cy;
							tmp.state = 0;
							tmp.val = cv + 1;
							tmp.made = cm;
							q.push(tmp);
							continue;
						}
						int nnx = nx + dx[k], nny = ny + dy[k];
						if (nnx >= 0 && nny >= 0 && nnx < num && nny < num && check[ny][nx][cm]>cv+1 &&check[nny][nnx][cm] > cv + 2 && arr[nny][nnx]==1) {
							if ((cv + 1) % arr[ny][nx] != 0) {
								int v = arr[ny][nx] - (cv + 1) % arr[ny][nx];
								tmp.x = cx;
								tmp.y = cy;
								tmp.state = 0;
								tmp.val = cv + v;
								tmp.made = cm;
								q.push(tmp);
							}
							else if ((cv + 1) % arr[ny][nx] == 0) {
								check[ny][nx][cm] = cv + 1;
								check[nny][nnx][cm] = cv + 2;
								tmp.x = nnx;
								tmp.y = nny;
								tmp.val = cv + 2;
								tmp.state = 1;
								tmp.made = cm;
								q.push(tmp);
							}
						}
					}
				}
			}
		}
		cout << "#" << t << " " << result << '\n';
	}
	system("pause");
	return 0;
}