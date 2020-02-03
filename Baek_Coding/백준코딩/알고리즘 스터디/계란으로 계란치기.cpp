#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool broken[8] = { false, };
int egg;
struct info {
	int dur, weight;
};
info tmp;
vector<info> v;
int result = -1;
void dfs(int cnt, int num) {
	result = max(result, num);
	if (cnt == egg) {
		//°è»ê
		return;
	}
	if (broken[cnt]) dfs(cnt + 1, num);
	else {
		int cd = v[cnt].dur;
		int cw = v[cnt].weight;
		int nd, nw, tt = 0;
		for (int i = 0; i < egg; i++) {
			if (i == cnt) continue;
			if (!broken[i]) {
				nd = v[i].dur;
				nw = v[i].weight;
				v[cnt].dur -= v[i].weight;
				if (v[cnt].dur <= 0) {
					broken[cnt] = true;
					tt++;
				}
				v[i].dur -= v[cnt].weight;
				if (v[i].dur <= 0) {
					broken[i] = true;
					tt++;
				}
				dfs(cnt + 1, num + tt);
				v[cnt].dur += v[i].weight;
				v[i].dur += v[cnt].weight;
				tt = 0;
				broken[cnt] = false;
				broken[i] = false;
			}
		}
	}
}

int main() {
	cin >> egg;
	int d, w;
	for (int i = 0; i < egg; i++) {
		cin >> d >> w;
		tmp.dur = d;
		tmp.weight = w;
		v.push_back(tmp);
	}
	dfs(0, 0);
	cout << result;
	system("pause");
	return 0;
}