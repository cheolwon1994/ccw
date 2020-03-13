#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int result = 0, row, col;
int dx[3] = { 0,1,1 };
int dy[3] = { 1,0,1 };
bool check[101][101] = { false, };
int generation[20];

struct info {
	int x, y;
};
info tmp;
vector<info> v[20];		//드래곤커브

void find_square() {		//답 구하는 함수
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (check[i][j]) {
				bool avail = true;
				for (int k = 0; k < 3; k++) {
					int nx = j + dx[k];
					int ny = i + dy[k];
					if (!check[ny][nx]) {
						avail = false;
						break;
					}
				}
				if (avail) result++;
			}
		}
	}
}

void rotate(int idx) {
	vector<info> dup;
	dup = v[idx];
	int dist_x = dup[dup.size() - 1].x;
	int dist_y = dup[dup.size() - 1].y;
	for (int i = v[idx].size() - 2; i >= 0; i--) {
		v[idx][i].x -= dist_x;
		v[idx][i].y -= dist_y;

		int next_x = -v[idx][i].y;
		int next_y = v[idx][i].x;

		next_x += dist_x;
		next_y += dist_y;
		tmp.x = next_x;
		tmp.y = next_y;
		check[next_y][next_x] = true;
		dup.push_back(tmp);
	}
	v[idx].clear();
	v[idx] = dup;
}

int main() {
	int num, x, y, dir, gen;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> x >> y >> dir >> gen;
		tmp.x = x;
		tmp.y = y;
		v[i].push_back(tmp);
		generation[i] = gen;
		check[y][x] = true;
		if (dir == 0) {			//우
			tmp.x = x + 1;
			tmp.y = y;
		}
		else if (dir == 1) {		//상
			tmp.x = x;
			tmp.y = y - 1;
		}
		else if (dir == 2) {		//좌
			tmp.x = x - 1;
			tmp.y = y;
		}
		else {			//하
			tmp.x = x;
			tmp.y = y + 1;
		}
		check[tmp.y][tmp.x] = true;
		v[i].push_back(tmp);
	}
	for (int i = 0; i < num; i++) {
		int g = generation[i];
		if (g == 0) continue;
		else {
			while (g > 0) {		//회전
				rotate(i);
				g--;
			}
		}
	}
	find_square();
	cout << result;
	system("pause");
	return 0;
}