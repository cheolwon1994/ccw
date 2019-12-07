#define CRT_NO_SECURE_WARNINGS
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#include <string>

using namespace std;

struct b_shark {
	int x;
	int y;
	int size = 2;
	int extra = 0;
};
struct info {
	int x;
	int y;
	int t;
};

info tmp;
b_shark tmp2;
vector <b_shark> s;
queue <info> q;
vector <info> avail;

int arr[20][20];
int check[20][20];
int x[4] = { 0,1,0,-1 };
int y[4] = { -1,0,1,0 };
int row;
int result = 0;
bool f_flag = false;

void eat() {
	int ex = 21;
	int ey = 21;
	int idx = -1;
	int dist = 401;
	for (int i = 0; i < avail.size(); i++)
		dist = min(dist, avail[i].t);
	for (int i = 0; i < avail.size(); i++) {
		if (avail[i].t == dist) {
			if (ey > avail[i].y) {
				ex = avail[i].x;
				ey = avail[i].y;
				idx = i;
			}
			else if (ey == avail[i].y && ex > avail[i].x) {
				ex = avail[i].x;
				idx = i;
			}
		}
	}
	if (idx == -1) {
		f_flag = true;
		return;
	}
	else {
		arr[avail[idx].y][avail[idx].x] = 0;
		result += avail[idx].t;
		arr[s[0].y][s[0].x] = 0;
		//아기 상어 정보 초기화
		if (s[0].extra + 1 == s[0].size) {
			s[0].size += 1;
			s[0].extra = 0;
		}
		else
			s[0].extra += 1;
		s[0].x = avail[idx].x;
		s[0].y = avail[idx].y;
	}
}

void bfs() {
	bool test = false;
	int cx, cy,ct,s1,nx,ny;
	int check[20][20] = { 0 };
	check[q.front().y][q.front().x] = 1;
	while (!q.empty()) {
		s1 = q.size();
		for (int i = 0; i < s1; i++) {
			cx = q.front().x;
			cy = q.front().y;
			ct = q.front().t;
			q.pop();
			for (int j = 0; j < 4; j++) {
				nx = cx + x[j];
				ny = cy + y[j];
				if (nx >= 0 && ny >= 0 && nx < row && ny < row) {
					if (check[ny][nx] == 1)
						continue;
					//먹을 수 있는 물고기
					if (arr[ny][nx] > 0 && arr[ny][nx] < s[0].size) {
						tmp.x = nx;
						tmp.y = ny;
						tmp.t = ct + 1;
						avail.push_back(tmp);
						check[ny][nx] = 1;
						test = true;
					}
					//없거나 먹을 수 없는 물고기
					else if (arr[ny][nx] == 0 || (arr[ny][nx] == s[0].size)) {
						tmp.x = nx;
						tmp.y = ny;
						tmp.t = ct + 1;
						q.push(tmp);
						check[ny][nx] = 1;
					}
				}
			}
		}
		if (test)
			break;
	}
}

void find() {
	while (!q.empty())
		q.pop();
	avail.clear();
	tmp.x = s[0].x;
	tmp.y = s[0].y;
	tmp.t = 0;
	q.push(tmp);
	bfs();
	eat();
}

bool eat_avail() {
	bool test = false;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < row; j++) {
			if (arr[i][j] < s[0].size && arr[i][j]>0) {
				test = true;
				break;
			}
		}
		if (test)
			break;
	}
	return test;
}

int main() {
	cin >> row;
	for(int i=0;i<row;i++)
		for (int j = 0; j < row; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				tmp2.x = j;
				tmp2.y = i;
				s.push_back(tmp2);
			}
		}
	bool test = true;
	while (1) {
		test = eat_avail();
		if (!test)
			break;
		find();
		if (f_flag)
			break;
	}
	cout << result;
	system("PAUSE");
	return 0;
}