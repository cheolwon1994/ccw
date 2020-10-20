#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct info {
	int x, y, r;
};
info tmp;
int num;
int par[3000];

int find_par(int x) {
	if (par[x] == x) return x;
	return par[x] = find_par(par[x]);
}

void make_union(int a, int b) {
	int pa = find_par(a);
	int pb = find_par(b);
	if (pa != pb) par[pa] = pb;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int test, x, y, r;
	cin >> test;
	for (int t = 0; t < test; t++) {
		vector<info> v;
		cin >> num;
		for (int i = 0; i < num; i++) {
			par[i] = i;
			cin >> x >> y >> r;
			tmp.x = x;
			tmp.y = y;
			tmp.r = r;
			v.push_back(tmp);
		}
		int result = num;
		for (int i = 0; i < num-1; i++)
			for (int j = i+1; j < num; j++) {
				int fx = v[i].x;
				int fy = v[i].y;
				int fr = v[i].r;
				int sx = v[j].x;
				int sy = v[j].y;
				int sr = v[j].r;
				long long d1 = (fr + sr)*(fr + sr);		//반지름 합
				long long d2 = (fx - sx)*(fx - sx) + (fy - sy)*(fy - sy);		//레이더 사이의 거리
				if (d1 >= d2 && find_par(i) != find_par(j)) {		//같은 그룹
					make_union(i, j);
					result--;
				}
			}
		cout << result << '\n';
	}
	return 0;
}