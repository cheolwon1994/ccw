#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int arr[50][50];
int dup[50][50];		//빨간색 심어질 때: 10, 초록색 심어질 때: 20, 꽃: 100
int row, col, red, green, result = 0;
struct info {
	int x, y;
};
info tmp;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
vector<info> can_plant, r, g;
vector<int> v;			//어떤 부분에 배양액을 심을 것인지

void bfs() {
	int t_result = 0;
	vector<info> flower;
	queue<info> rr, gg;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			dup[i][j] = arr[i][j];
		
	for (int i = 0; i < r.size(); i++) {
		tmp.x = r[i].x;
		tmp.y = r[i].y;
		rr.push(tmp);
		dup[tmp.y][tmp.x] = 0;
	}
	for (int i = 0; i < g.size(); i++) {
		tmp.x = g[i].x;
		tmp.y = g[i].y;
		gg.push(tmp);
		dup[tmp.y][tmp.x] = 0;
	}
	while (1) {
		queue<info> nr, ng;
		//빨간색 퍼트린다
		int len = rr.size();
		for (int i = 0; i < len; i++) {
			int cx = rr.front().x;
			int cy = rr.front().y;
			rr.pop();
			if (dup[cy][cx] == 100) continue;		//꽃이 피어난 자리면
			dup[cy][cx] = 0;		//늦게 온 초록이랑 꽃이 되지 않도록 하기 위해 못가는 곳으로 초기화
			for (int k = 0; k < 4; k++) {
				int nx = cx + dx[k];
				int ny = cy + dy[k];
				if (nx >= 0 && ny >= 0 && nx < col && ny < row && dup[ny][nx] == 1) {
					tmp.x = nx;
					tmp.y = ny;
					nr.push(tmp);
					dup[ny][nx] = 10;
				}
			}
		}
		//초록색 퍼트린다
		len = gg.size();
		for (int i = 0; i < len; i++) {
			int cx = gg.front().x;
			int cy = gg.front().y;
			gg.pop();
			for (int k = 0; k < 4; k++) {
				int nx = cx + dx[k];
				int ny = cy + dy[k];
				if (nx >= 0 && ny >= 0 && nx < col && ny < row) {
					if (dup[ny][nx] == 1) {			//아직 방문하지 않은 곳
						tmp.x = nx;
						tmp.y = ny;
						dup[ny][nx] = 0;		//더이상 못가는 곳으로 바꾼다
						ng.push(tmp);
					}
					else if (dup[ny][nx] == 10) {		//꽃 생성
						dup[ny][nx] = 100;
						t_result++;					
					}					
				}
			}
		}
		rr = nr;
		gg = ng;
		if (gg.empty() && rr.empty()) break;
	}
	result = max(result, t_result);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> row >> col >> green >> red;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				tmp.x = j;
				tmp.y = i;
				can_plant.push_back(tmp);
				arr[i][j] = 1;
			}
		}
	vector<int> t;
	for (int i = 0; i < can_plant.size() - red - green; i++)
		t.push_back(0);
	for (int i = 0; i < red + green; i++)
		t.push_back(1);
	do {
		v.clear();
		for (int i = 0; i < can_plant.size(); i++)
			if (t[i] == 1)
				v.push_back(i);
		vector<int> tt;
		for (int i = 0; i < red; i++)	tt.push_back(0);
		for (int i = 0; i < green; i++)	tt.push_back(1);
		do {
			r.clear();
			g.clear();
			for (int i = 0; i < tt.size(); i++) {
				if (tt[i] == 0) {			//빨간색 배양액 시작할곳
					tmp.x = can_plant[v[i]].x;
					tmp.y = can_plant[v[i]].y;
					r.push_back(tmp);
				}
				else {						//초록색 배양액 시작할곳
					tmp.x = can_plant[v[i]].x;
					tmp.y = can_plant[v[i]].y;
					g.push_back(tmp);
				}
			}
			bfs();
		} while (next_permutation(tt.begin(), tt.end()));
	} while (next_permutation(t.begin(), t.end()));
	cout << result;
	system("pause");
	return 0;
}