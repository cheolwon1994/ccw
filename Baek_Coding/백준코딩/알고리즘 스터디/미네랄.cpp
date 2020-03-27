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
vector<info> mineral;		//�ν��� �̳׶��� 4�濡 �ִ� �̳׶�

void bfs() {
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			check[i][j] = 0;

	int flying = 0;		//���ִ� �̳׶����� check��
	vector<info> v;		//�� �ִ� �̳׶���
	for (int i = 0; i < mineral.size(); i++) {
		queue<info> q;
		v.clear();
		bool fly = true;			//�� �ִ��� ���� -> row-1�� �پ��ִ°� �ִٸ� false�� �ٲ۴�
		tmp.x = mineral[i].x;
		tmp.y = mineral[i].y;
		if (check[tmp.y][tmp.x] != 0) continue;		//�̹� �˻�� ���
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
			flying = i + 1;		//�� �ִ� �̳׶� Ŭ�����͵��� check��
			break;
		}
	}
	if (flying > 0) {
		int mini = 101;
		//�󸶸�ŭ ������ �ϴ��� ���(�������� �ּҸ�ŭ)
		for (int i = 0; i < v.size(); i++) {
			int ny = v[i].y;
			int cnt = 0;
			while (1) {
				ny += dy[2];		//������ ��ĭ ������
				cnt++;
				if (ny == row) {		//�ٴڿ� �̹� ��Ҵ� ���
					ny -= dy[2];
					cnt--;
					break;
				}
				else if (arr[ny][v[i].x] == 'x' && check[ny][v[i].x] != flying) {		//�ٸ� Ŭ�������� �̳׶��� �ε����� ���
					ny -= dy[2];
					cnt--;
					break;
				}
			}
			mini = min(mini, cnt);
		}
		//���ִ� ��� ������
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
		if (left) {					//���ʿ��� ������
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
		else if (!left) {			//�����ʿ��� ������
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