#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
char arr[100][100];
int check[100][100];
int row, col, lev, num;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
struct info {
	int x, y;
};
info tmp;
vector<info> mineral;		//부숴진 미네랄의 4방에 있던 미네랄

void bfs() {
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			check[i][j] = 0;

	int flying = 0;		//떠있는 미네랄들의 check값
	vector<info> v;		//떠 있는 미네랄들
	for (int i = 0; i < mineral.size(); i++) {
		queue<info> q;
		v.clear();
		bool fly = true;			//떠 있는지 여부 -> row-1에 붙어있는게 있다면 false로 바꾼다
		tmp.x = mineral[i].x;
		tmp.y = mineral[i].y;
		if (check[tmp.y][tmp.x] != 0) continue;		//이미 검사된 경우
		q.push(tmp);
		v.push_back(tmp);
		check[tmp.y][tmp.x] = i + 1;
		while (!q.empty()) {
			int cx = q.front().x;
			int cy = q.front().y;
			q.pop();
			if (cy == row - 1)
				fly = false;
			for (int k = 0; k < 4; k++) {
				int nx = cx + dx[k];
				int ny = cy + dy[k];
				if (nx >= 0 && ny >= 0 && nx < col && ny < row && arr[ny][nx] == 'x' && check[ny][nx] == 0) {
					check[ny][nx] = i + 1;
					tmp.x = nx;
					tmp.y = ny;
					q.push(tmp);
					v.push_back(tmp);
				}
			}
		}
		if (fly) {
			flying = i + 1;		//떠 있는 미네랄 클러스터들의 check값
			break;
		}
	}
	if (flying > 0) {
		int mini = 101;
		//얼마만큼 내려야 하는지 계산(높이차의 최소만큼)
		for (int i = 0; i < v.size(); i++) {
			int ny = v[i].y;
			int cnt = 0;
			while (1) {
				ny += dy[2];		//밑으로 한칸 내리기
				cnt++;
				if (ny == row) {		//바닥에 이미 닿았던 경우
					ny -= dy[2];
					cnt--;
					break;
				}
				else if (arr[ny][v[i].x] == 'x' && check[ny][v[i].x] != flying) {		//다른 클러스터의 미네랄과 부딪히는 경우
					ny -= dy[2];
					cnt--;
					break;
				}
			}
			mini = min(mini, cnt);
		}
		//떠있는 놈들 내리기
		char dup[100][100];
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (check[i][j] == flying)
					dup[i][j] = '.';
				else
					dup[i][j] = arr[i][j];
			}
		}
		for (int i = 0; i < v.size(); i++) {
			int x = v[i].x;
			int y = v[i].y;
			dup[y + mini][x] = 'x';
		}
		memcpy(arr, dup, sizeof(dup));
	}
}
int main() {
	cin >> row >> col;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			cin >> arr[i][j];
	cin >> num;
	bool left = true;
	for (int i = 0; i < num; i++) {
		cin >> lev;
		lev = row - lev;
		bool meet_mineral = false;
		mineral.clear();
		if (left) {					//왼쪽에서 던진다
			for (int j = 0; j < col; j++) {
				if (arr[lev][j] == 'x') {
					arr[lev][j] = '.';
					meet_mineral = true;					
					for (int k = 0; k < 4; k++) {
						int nx = j + dx[k];
						int ny = lev + dy[k];
						if (nx >= 0 && ny >= 0 && nx < col && ny < row && arr[ny][nx]=='x') {
							tmp.x = nx;
							tmp.y = ny;
							mineral.push_back(tmp);
						}
					}
					break;
				}
			}
		}
		else if (!left) {			//오른쪽에서 던진다
			for (int j = col - 1; j >= 0; j--) {
				if (arr[lev][j] == 'x') {
					arr[lev][j] = '.';
					meet_mineral = true;
					for (int k = 0; k < 4; k++) {
						int nx = j + dx[k];
						int ny = lev + dy[k];
						if (nx >= 0 && ny >= 0 && nx < col && ny < row && arr[ny][nx] == 'x') {
							tmp.x = nx;
							tmp.y = ny;
							mineral.push_back(tmp);
						}
					}
					break;
				}
			}
		}
		if(meet_mineral)	bfs();
		left = !left;
	}
	for (int j = 0; j < row; j++) {
		for (int k = 0; k < col; k++)
			cout << arr[j][k];
		cout << endl;
	}
	system("pause");
	return 0;
}