#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
struct info {
	int x, y, val, len;
};
info tmp;
int arr[11][11], mv, plant, oa[101], ob[101], result, t_result;
int dx[5] = { 0,0,1,0,-1 };
int dy[5] = { 0,-1,0,1,0 };
vector<info> v;
vector<int> go[2], selected;

void dfs(int pidx, int cnt) {
	if (pidx == 1 && cnt==1) {
		if (selected[0] == selected[1])		//같은 BC
			t_result = max(t_result, v[selected[0]].val);
		else		//다른 BC
			t_result = max(t_result, v[selected[0]].val + v[selected[1]].val);
		return;
	}
	if (pidx == 0 && cnt == 1) {
		dfs(1, 0);
		return;
	}
	for (int i = 0; i < go[pidx].size(); i++) {
		selected.push_back(go[pidx][i]);
		dfs(pidx, cnt + 1);
		selected.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		//초기화
		result = 0;
		v.clear();

		cin >> mv >> plant;
		for (int i = 1; i <= mv; i++)
			cin >> oa[i];
		for (int i = 1; i <= mv; i++)
			cin >> ob[i];
		for (int i = 0; i < plant; i++) {
			cin >> tmp.x >> tmp.y >> tmp.len >> tmp.val;
			v.push_back(tmp);
		}
		int ax = 1, ay = 1, bx = 10, by = 10;
		for (int k = 0; k <= mv; k++) {
			go[0].clear();		//a가 닿는 BC
			go[1].clear();		//b가 닿는 BC
			selected.clear();		//a,b가 닿을 BC
			t_result = 0;

			ax += dx[oa[k]];
			ay += dy[oa[k]];
			bx += dx[ob[k]];
			by += dy[ob[k]];

			for (int i = 0; i < plant; i++) {
				int px = v[i].x;
				int py = v[i].y;
				int pl = v[i].len;
				int pv = v[i].val;
				int dist = abs(px - ax) + abs(py - ay);
				if (dist <= pl) 
					go[0].push_back(i);				
				dist = abs(px - bx) + abs(py - by);
				if (dist <= pl) 
					go[1].push_back(i);				
			}	
			if (go[0].size() > 0 && go[1].size() > 0)
				dfs(0, 0);
			else {
				for (int i = 0; i < go[0].size(); i++)
					t_result = max(t_result, v[go[0][i]].val);
				for (int i = 0; i < go[1].size(); i++)
					t_result = max(t_result, v[go[1][i]].val);
			}
			result += t_result;
		}
		cout << "#" << t << " " << result << '\n';
	}

	return 0;
}