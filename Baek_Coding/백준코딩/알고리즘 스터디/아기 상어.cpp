#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

struct info {
	int x, y, level, fill;
};
info tmp;
struct cmp {
	bool operator()(info &a, info &b) {
		if (a.y == b.y)
			return a.x > b.x;
		else 
			return a.y > b.y;		
	}
};
int num, result = 0;
bool finish = false;
int arr[20][20];
int check[20][20];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
vector<info> shark;

void bfs() {
	int cx, cy, cf, cl, nx, ny;
	tmp.x = shark[0].x;
	tmp.y = shark[0].y;
	tmp.fill = shark[0].fill;
	tmp.level = shark[0].level;
	queue<info> q;
	priority_queue<info, vector<info>, cmp> pq;
	for (int i = 0; i < 20; i++)
		memset(check[i], 0, sizeof(check[i]));
	int cnt = 0;
	q.push(tmp);
	bool eat = false;
	while (!q.empty()) {
		int len = q.size();
		cnt++;
		for (int k = 0; k < len; k++) {
			cx = q.front().x;
			cy = q.front().y;
			cf = q.front().fill;
			cl = q.front().level;
			q.pop();
			if (arr[cy][cx] < cl && arr[cy][cx]>0) {
				if(!eat)
					result += (cnt - 1);
				eat = true;
				tmp.x = cx;
				tmp.y = cy;
				pq.push(tmp);
			}
			if (eat)
				continue;
			for (int i = 0; i < 4; i++) {
				nx = cx + dx[i];
				ny = cy + dy[i];
				if (nx >= 0 && ny >= 0 && nx < num && ny < num &&check[ny][nx] == 0) {
					if (arr[ny][nx] > cl)
						continue;
					else{
						check[ny][nx] = cnt;
						tmp.x = nx;
						tmp.y = ny;
						tmp.fill = cf;
						tmp.level = cl;
						q.push(tmp);
					}
				}
			}
		}
		if (eat)
			break;
	}
	if (!eat)
		finish = true;
	else {
		int tx = pq.top().x;
		int ty = pq.top().y;
		shark[0].x = tx;
		shark[0].y = ty;
		shark[0].fill += 1;
		if (shark[0].fill == shark[0].level) {
			shark[0].level += 1;
			shark[0].fill = 0;
		}
		arr[ty][tx] = 0;
	}
}

int main() {
	cin >> num;
	for (int i = 0; i < num; i++)
		for (int j = 0; j < num; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				tmp.x = j;
				tmp.y = i;
				tmp.fill = 0;
				tmp.level = 2;
				shark.push_back(tmp);
				arr[i][j] = 0;
			}
		}
	while(!finish)
		bfs();
	cout << result;
	system("pause");
	return 0;
}