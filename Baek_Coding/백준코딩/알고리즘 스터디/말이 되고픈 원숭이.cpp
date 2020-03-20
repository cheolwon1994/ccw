#define MAX 987654321
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int arr[200][200];
int check[200][200][31];
int dx[12] = { 0,1,0,-1,1,2,2,1,-1,-2,-2,-1 };
int dy[12] = { -1,0,1,0,-2,-1,1,2,2,1,-1,-2 };
int num, row, col;
int result = 0;
struct info {
	int y, x, jump;
};
info tmp;
queue<info> q;

int main() {
	cin >> num >> col >> row;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) {
			cin >> arr[i][j];
			for (int k = 0; k < 31; k++)
				check[i][j][k] = MAX;
		}
	q.push({ 0,0,0});
	check[0][0][0] = 0;
	int result = 987654321;
	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		int cj = q.front().jump;
		q.pop();
		if (cx == col - 1 && cy == row - 1) {
			result = check[cy][cx][cj];
			break;
		}
		for (int i = 0; i < 12; i++) {
			if (cj == num && i == 4) break;		//남은 나이트 이동횟수가 없는 경우
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && ny >= 0 && nx < col && ny < row) {
				if (arr[ny][nx] == 1) 	continue;	//이동 + 다음칸이 장애물
				if (i < 4) {
					if (check[ny][nx][cj] <= check[cy][cx][cj] + 1) continue;
					q.push({ ny,nx,cj });
					check[ny][nx][cj] = check[cy][cx][cj] + 1;
				}
				else {		//나이트 점프
					if (check[ny][nx][cj + 1] <= check[cy][cx][cj] + 1) continue;
					q.push({ ny,nx,cj + 1 });
					check[ny][nx][cj + 1] = check[cy][cx][cj] + 1;
				}
			}
		}
	}
	if (result == MAX) result = -1;
	cout << result;
	system("pause");
	return 0;
}