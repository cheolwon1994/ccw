#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct info {
	int x, y, val, dir;
	bool die;
};
info tmp;
int arr[100][100], num, k, hour, result;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
vector<info> v;
vector<int> next_arr[100][100];

int cal() {
	int t_Result = 0;
	for (int i = 0; i < k; i++) 
		if(!v[i].die)
			t_Result += v[i].val;	
	return t_Result;
}

void bfs() {
	for (int i = 0; i < num; i++)
		for (int j = 0; j < num; j++)
			next_arr[i][j].clear();

	for (int i = 0; i < k; i++) {
		if (v[i].die) continue;
		int cx = v[i].x;
		int cy = v[i].y;
		int cv = v[i].val;
		int cd = v[i].dir;

		int nx = cx + dx[cd];
		int ny = cy + dy[cd];
		int nd = cd;

		v[i].x = nx;
		v[i].y = ny;

		if (nx == 0 || ny == 0 || nx == num - 1 || ny == num - 1) {		//약품에 닿는거
			if (cv / 2 == 0) {
				v[i].die = true;
				continue;
			}
			nd = (cd + 2) % 4;			
			v[i].val = cv / 2;
			v[i].dir = nd;
			next_arr[ny][nx].push_back(i);
		}
		else {
			v[i].dir = cd;
			v[i].val = cv;
			next_arr[ny][nx].push_back(i);
		}
	}

	for (int i = 0; i < num; i++)
		for (int j = 0; j < num; j++) {
			if (next_arr[i][j].size() > 1) {
				int idx = -1, maxi = 0, sum = 0;
				//가장 큰 군집 찾기
				for (int m = 0; m < next_arr[i][j].size(); m++) {
					int ii = next_arr[i][j][m];
					int amount = v[ii].val;
					sum += amount;
					if (amount > maxi) {
						maxi = amount;
						idx = ii;
					}
				}
				for (int m = 0; m < next_arr[i][j].size(); m++) {
					int ii = next_arr[i][j][m];
					if (ii != idx) 
						v[ii].die = true;					
					else 
						v[idx].val = sum;					
				}
			}
		}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		cin >> num >> hour >> k;
		//초기화
		v.clear();

		int dir;
		for (int i = 0; i < k; i++) {
			cin >> tmp.y >> tmp.x >> tmp.val >> dir;
			if (dir == 1) tmp.dir = 0;
			else if (dir == 2) tmp.dir = 2;
			else if (dir == 3) tmp.dir = 3;
			else tmp.dir = 1;
			tmp.die = false;
			v.push_back(tmp);
		}
		while (hour > 0) {
			bfs();
			hour--;
		}
		result = cal();
		cout << "#" << t << " " << result << '\n';
	}
	return 0;
}