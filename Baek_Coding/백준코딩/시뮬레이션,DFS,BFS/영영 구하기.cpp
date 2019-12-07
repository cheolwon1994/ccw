#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int row, col, num;
int arr[100][100];
struct info {
	int x;
	int y;
};
info tmp;
queue<info> q;
vector<int> v;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int diff = 1;
int main() {
	cin >> row >> col >> num;
	int x1, x2, y1, y2, cx, cy, nx, ny;
	for (int i = 0; i < num; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = row - y2; j < row - y1; j++) 
			for (int k = x1; k < x2; k++)
				arr[j][k] = -1;
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (arr[i][j] == 0) {
				tmp.x = j;
				tmp.y = i;
				q.push(tmp);
				arr[i][j] = diff;
				int local = 1;
				while (!q.empty()) {
					cx = q.front().x;
					cy = q.front().y;
					q.pop();
					for (int k = 0; k < 4; k++) {
						nx = cx + dx[k];
						ny = cy + dy[k];
						if (nx >= 0 && ny >= 0 && nx < col && ny < row) {
							if (arr[ny][nx] == 0) {
								tmp.x = nx;
								tmp.y = ny;
								arr[ny][nx] = diff;
								q.push(tmp);
								local += 1;
							}
						}
					}
				}
				v.push_back(local);
				diff++;
			}
		}
	}
	sort(v.begin(), v.end());
	cout << diff-1 << endl;
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	system("pause");
	return 0;
}