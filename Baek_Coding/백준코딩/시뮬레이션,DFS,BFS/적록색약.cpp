#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
int num, RG, NRG, cx, cy, nx, ny;
char cv;
char arr[100][100];
int check[100][100];		//적록 x
int check2[100][100];		//적록
struct info {
	int y;
	int x;
	char val;
};
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int main() {
	string str;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> str;
		for (int j = 0; j < num; j++)
			arr[i][j] = str[j];
	}
	RG = 0;
	NRG = 0;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			if (check[i][j] != 1) {
				++NRG;
				queue<info> nq;	//적록x
				nq.push({ i,j,arr[i][j] });
				check[i][j] = 1;
				while (!nq.empty()) {
					cx = nq.front().x;
					cy = nq.front().y;
					cv = nq.front().val;
					nq.pop();
					for (int k = 0; k < 4; k++) {
						nx = cx + dx[k];
						ny = cy + dy[k];
						if (nx >= 0 & ny >= 0 && nx < num && ny < num && check[ny][nx] != 1) {
							if (arr[ny][nx] == cv) {
								check[ny][nx] = 1;
								nq.push({ ny,nx,cv });
							}
						}
					}
				}
			}
			if (check2[i][j] != 1) {
				++RG;
				queue<info> q;
				q.push({ i,j,arr[i][j] });
				check2[i][j] = 1;
				while (!q.empty()) {
					cx = q.front().x;
					cy = q.front().y;
					cv = q.front().val;
					q.pop();
					for (int k = 0; k < 4; k++) {
						nx = cx + dx[k];
						ny = cy + dy[k];
						if (nx >= 0 & ny >= 0 && nx < num && ny < num && check2[ny][nx] != 1) {
							if (cv=='R') {
								if (arr[ny][nx] == 'R' || arr[ny][nx] == 'G') {
									check2[ny][nx] = 1;
									q.push({ ny,nx,cv });
								}
							}
							else if (cv == 'G') {
								if (arr[ny][nx] == 'R' || arr[ny][nx] == 'G') {
									check2[ny][nx] = 1;
									q.push({ ny,nx,cv });
								}
							}
							else if (cv == 'B' && arr[ny][nx]=='B') {
								check2[ny][nx] = 1;
								q.push({ ny,nx,cv });
							}
						}
					}
				}
			}
		}
	}
	cout << NRG << " " << RG;
	system("pause");
	return 0;
}