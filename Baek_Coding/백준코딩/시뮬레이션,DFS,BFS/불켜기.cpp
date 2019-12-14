#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct info {
	int y;
	int x;
};
info tmp;
queue<info> q;
vector<info> v;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
vector<info> arr[101][101];
int check[101][101];
int num, test, cx, cy, nx, ny, result;
int main() {
	cin >> num >> test;
	
	for (int i = 0; i < test; i++) {
		cin >> cy >> cx >> ny >> nx;
		tmp.x = nx;
		tmp.y = ny;
		arr[cy][cx].push_back(tmp);
	}
	check[1][1] = 2;
	tmp.x = 1;
	tmp.y = 1;
	q.push(tmp);
	v.push_back(tmp);
	result = 1;
	//불 킨다 -> 켜진곳으로 이동할 수 있으면 queue에 넣는다
	while (!q.empty()) {
		while (!q.empty()) {
			cx = q.front().x;
			cy = q.front().y;
			q.pop();
			int len = arr[cy][cx].size();
			if (len > 0) {
				for (int i = 0; i < len; i++) {
					if (check[arr[cy][cx][i].y][arr[cy][cx][i].x] == 0) {
						check[arr[cy][cx][i].y][arr[cy][cx][i].x] = 1;
						result++;
					}
				}
			}
		}
		for (int k = 0; k < v.size(); k++) {
			cx = v[k].x;
			cy = v[k].y;
			for (int i = 0; i < 4; i++) {
				nx = cx + dx[i];
				ny = cy + dy[i];
				if (nx > 0 && ny > 0 && nx <= num && ny <= num && check[ny][nx] == 1) {
					check[ny][nx] = 2;
					tmp.x = nx;
					tmp.y = ny;
					v.push_back(tmp);
					q.push(tmp);
				}
			}
		}
	}
	cout << result;
	system("pause");
	return 0;
}