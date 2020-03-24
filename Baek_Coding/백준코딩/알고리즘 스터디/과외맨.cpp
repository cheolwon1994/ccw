#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
struct info {
	int x, y;
};
info tmp;
struct info2 {
	int tyle, val, dist;
};
info2 arr[501][501*2];
int before[501*501];			//이전 값
int num, s, e, r = 0, c = 0, maxi = 0, cnt = 1;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

void path() {
	vector<int> v;
	v.push_back(maxi);
	while (before[maxi]!=0) {
		maxi = before[maxi];
		v.push_back(maxi);
	}
	cout << v.size() << '\n';
	for (int i = v.size() - 1; i >= 0; i--)
		cout << v[i] << " ";
}

void bfs() {
	queue<info> q;
	tmp.x = 0;
	tmp.y = 0;
	q.push(tmp);
	tmp.x = 1;
	q.push(tmp);
	arr[0][0].dist = 1;
	arr[0][1].dist = 1;
	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && ny >= 0 && nx < 2 * num && ny < num && arr[ny][nx].val == arr[cy][cx].val) {
				if (arr[ny][nx].dist != 0) continue;		//이미 방문한 경우
				bool left = false;
				if (arr[ny][nx].tyle == arr[ny][nx - 1].tyle) left = true;	//왼쪽이 같은 타일
				arr[ny][nx].dist = arr[cy][cx].dist + 1;
				tmp.x = nx;
				tmp.y = ny;
				q.push(tmp);
				if (left) {			//왼쪽타일이 같음
					arr[ny][nx - 1].dist = arr[cy][cx].dist + 1;
					tmp.x = nx - 1;
					q.push(tmp);
				}
				else {				//오른쪽이 같음
					arr[ny][nx + 1].dist = arr[cy][cx].dist + 1;
					tmp.x = nx + 1;
					q.push(tmp);
				}
				//경로 갱신
				before[arr[ny][nx].tyle] = arr[cy][cx].tyle;
				maxi = max(maxi, arr[ny][nx].tyle);
			}
		}
	}
}

int main() {
	cin >> num;
	for (int i = 0; i < num*num - num / 2; i++) {
		cin >> s >> e;
		arr[r][c].val = s;
		arr[r][c + 1].val = e;
		arr[r][c].tyle = cnt;
		arr[r][c + 1].tyle = cnt++;
		c += 2;
		if (r % 2 == 0 && c == 2 * num) {
			r += 1;
			c = 1;
		}
		else if (r % 2 == 1 && c == 2 *num - 1) {
			r += 1;
			c = 0;
		}
	}
	bfs();
	path();
	system("pause");
	return 0;
}