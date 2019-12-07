#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;
int row, col;
struct info {
	int x;
	int y;
};
vector<info> virus;
info tmp;
int result = -1;
int arr[8][8];
int arr2[8][8];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
void spread() {
	queue<info> q;
	for (int i = 0; i < virus.size(); i++) {
		tmp.x = virus[i].x;
		tmp.y = virus[i].y;
		q.push(tmp);
	}
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			arr2[i][j] = arr[i][j];
	while (!q.empty()) {
		int ny, nx, cx, cy;
		cx = q.front().x;
		cy = q.front().y;
		q.pop();
		for (int i = 0; i < 4; i++) {
			nx = cx + dx[i];
			ny = cy + dy[i];
			if (nx >= 0 && ny >= 0 && nx < col && ny < row) {
				if (arr2[ny][nx] == 0) {
					arr2[ny][nx] = 2;
					tmp.x = nx;
					tmp.y = ny;
					q.push(tmp);
				}				
			}
		}
	}
	int temp = 0;
	for (int i = 0; i < row; i++) 
		for (int j = 0; j < col; j++) 
			if (arr2[i][j] == 0)
				temp++;		
	result = max(result, temp);
}

void construct(int idx, int cnt) {
	if (cnt == 3) {
		spread();		
		return;
	}
	if (idx == row * col)
		return;
	int cx, cy;
	cy = idx / col;
	cx = idx % col;
	if (arr[cy][cx] == 0) {
		arr[cy][cx] = 1;
		construct(idx + 1, cnt + 1);
		arr[cy][cx] = 0;
	}
	construct(idx + 1, cnt);
}

int main() {
	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				tmp.x = j;
				tmp.y = i;
				virus.push_back(tmp);
			}
		}
	}
	construct(0,0);
	cout << result << endl;
	system("pause");
	return 0;
}