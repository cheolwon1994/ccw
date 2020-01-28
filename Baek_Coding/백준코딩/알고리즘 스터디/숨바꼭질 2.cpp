#define MAX 100001
#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>

using namespace std;
struct info {
	int mv, idx;
};
info tmp;
int main(){
	int check[MAX];
	int cnt = 0;
	memset(check, 0, sizeof(check));
	int start, end, num,cidx,cmv;
	cin >> start >> end;
	queue<info> q;
	tmp.idx = start;
	tmp.mv = 0;
	q.push(tmp);
	check[start] = 0;
	int dist = 100000;
	while (!cnt) {
		int len = q.size();
		for (int i = 0; i < len; i++) {
			cidx = q.front().idx;
			cmv = q.front().mv;
			check[cidx] = 1;
			q.pop();
			if (cidx == end) { cnt++; dist = min(dist, cmv); }
			if (cidx + 1 < MAX && check[cidx + 1] == 0) {
				tmp.idx = cidx + 1;
				tmp.mv = cmv + 1;
				q.push(tmp);
			}
			if (cidx - 1 >=0 && check[cidx - 1] == 0) {
				tmp.idx = cidx - 1;
				tmp.mv = cmv + 1;
				q.push(tmp);
			}
			if (cidx * 2 < MAX && check[2 *cidx] == 0) {
				tmp.idx = 2 * cidx;
				tmp.mv = cmv + 1;
				q.push(tmp);
			}
		}
	}
	cout << dist << endl << cnt;	
	system("pause");
	return 0;
}