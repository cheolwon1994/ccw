#include <iostream>
#include <queue>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
bool visit[100];
struct info {
	int x, y, idx;
};
info tmp;
vector<info> v;
int main() {
	int test, sx, sy, mart, tx, ty, x, y;
	cin >> test;
	for (int t = 0; t < test; t++) {
		cin >> mart >> sx >> sy;
		bool finish = false;
		queue<info> q;
		v.clear();
		for (int i = 0; i < mart; i++)
			visit[i] = false;
		for (int i = 0; i < mart; i++) {
			cin >> x >> y;
			tmp.x = x;
			tmp.y = y;
			tmp.idx = i;
			v.push_back(tmp);
			if (abs(sx - x) + abs(sy - y) <= 1000) {
				q.push(tmp);
				visit[i] = true;
			}
		}
		cin >> tx >> ty;
		if (abs(sx - tx) + abs(sy - ty) <= 1000)		//집에서 바로 페스티벌까지 갈 수 있는 경우
			cout << "happy\n";
		else {
			while (!q.empty()) {
				int cx = q.front().x;
				int cy = q.front().y;
				int cidx = q.front().idx;
				q.pop();
				if (abs(cx - tx) + abs(cy - ty) <= 1000) {
					finish = true;
					break;
				}
				for (int i = 0; i < v.size(); i++) {
					if (visit[v[i].idx]) continue;
					int dist = abs(cx - v[i].x) + abs(cy - v[i].y);
					if (dist <= 1000) {
						visit[i] = true;
						tmp.x = v[i].x;
						tmp.y = v[i].y;
						tmp.idx = v[i].idx;
						q.push(tmp);
					}
				}
			}
			if (finish) cout << "happy\n";
			else cout << "sad\n";
		}
	}
	system("pause");
	return 0;
}