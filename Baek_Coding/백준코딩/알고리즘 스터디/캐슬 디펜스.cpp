#include <iostream>
#include <queue>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
int row, col, dist;
int arr[16][15];
int dup[16][15];
int check[16][15];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int result, t_result;
vector<int> archer;
struct info {
	int x, y;
};
info tmp;
struct cmp {
	bool operator()(info &a, info &b) {
		return a.x > b.x;
	}
};
void move_down() {		//적 한칸 밑으로 이동
	for (int i = row - 1; i > 0; i--) 
		for (int j = 0; j < col; j++)
			dup[i][j] = dup[i - 1][j];
	for (int i = 0; i < col; i++)
		dup[0][i] = 0;
}

void attack() {
	int cx, cy, nx, ny;
	vector<info> v;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j <16; j++)
			memset(check[j], 0, sizeof(check[j]));
		priority_queue<info, vector<info>, cmp> pq;
		queue<info> q;
		tmp.x = archer[i];
		tmp.y = row;
		q.push(tmp);
		while (!q.empty()) {
			int len = q.size();
			bool finish = false;
			for (int j = 0; j < len; j++) {
				cx = q.front().x;
				cy = q.front().y;
				q.pop();
				if (dup[cy][cx] == 1) {
					finish = true;
					tmp.x = cx;
					tmp.y = cy;
					pq.push(tmp);
					continue;
				}
				if (finish)
					continue;
				for (int k = 0; k < 4; k++) {
					nx = cx + dx[k];
					ny = cy + dy[k];
					if (nx >= 0 && ny >= 0 && nx < col && ny <= row && check[ny][nx] == 0) {
						if (check[cy][cx] + 1 <= dist) {
							check[ny][nx] = check[cy][cx] + 1;
							tmp.x = nx;
							tmp.y = ny;
							q.push(tmp);
						}
					}
				}
			}
			if (finish) {
				v.push_back(pq.top());
				break;
			}
		}		
	}
	for (int i = 0; i < v.size(); i++) {
		if (dup[v[i].y][v[i].x] == 1) {
			dup[v[i].y][v[i].x] = 0;
			t_result++;
		}
	}
}

int main() {
	//초기화
	result = 0;

	cin >> row >> col >> dist;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			cin >> arr[i][j];
	vector<int> v;
	for (int i = 0; i < col - 3; i++)
		v.push_back(0);
	for (int i = col - 3; i < col; i++)
		v.push_back(1);
	do {
		//초기화
		archer.clear();
		t_result = 0;
		memcpy(dup, arr, sizeof(arr));

		//궁수 세팅
		for (int i = 0; i < col; i++)
			if (v[i] == 1)
				archer.push_back(i);
		for (int k = 0; k < row; k++) {
			//공격할 대상 찾기
			attack();
			move_down();
		}
		result = max(result, t_result);
	} while (next_permutation(v.begin(), v.end()));
	cout << result;
	system("pause);
	return 0;
}