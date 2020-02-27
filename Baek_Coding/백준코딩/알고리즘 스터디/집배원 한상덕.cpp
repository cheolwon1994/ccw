#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;
char arr[50][50];
int height[50][50];
bool check[50][50];
bool flag;
int num, sx, sy, home = 0, result = 987654321;
int dx[8] = { 0,1,0,-1,1,1,-1,-1 };
int dy[8] = { -1,0,1,0,-1,1,1,-1 };
struct info {
	int x, y;
};
info tmp;
vector<info> v;
set<int> s;
int main() {
	cin >> num;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'P') {
				sx = j;
				sy = i;
			}
			else if (arr[i][j] == 'K')
				home++;
		}
	}
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			cin >> height[i][j];
			s.insert(height[i][j]);
		}
	}
	set<int> ::iterator it;
	int val[2501];
	int cnt = 0;
	for (it = s.begin(); it != s.end(); it++)
		val[cnt++] = *it;
	int low = 0, high = 0;
	while (low <= high && high < s.size()) {
		if (height[sy][sx] > val[high] || height[sy][sx] < val[low]) {
			high++;
			continue;
		}
		for (int i = 0; i < num; i++)
			for (int j = 0; j < num; j++)
				check[i][j] = false;
		cnt = 0;
		queue<info> q;
		check[sy][sx] = true;
		tmp.x = sx;
		tmp.y = sy;
		q.push(tmp);
		while (!q.empty()) {
			int cx = q.front().x;
			int cy = q.front().y;
			q.pop();
			for (int i = 0; i < 8; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if (nx >= 0 && ny >= 0 && nx < num && ny < num && !check[ny][nx]) {
					check[ny][nx] = true;
					int tt = height[ny][nx];
					if (val[low] <= tt && tt <= val[high]) {
						tmp.x = nx;
						tmp.y = ny;
						q.push(tmp);
						if (arr[ny][nx] == 'K')
							cnt++;
					}
				}
			}
		}
		if (cnt == home) {
			result = min(result, val[high] - val[low]);
			low++;
		}
		else 
			high++;		
	}
	cout << result;	
	system("pause");
	return 0;
}