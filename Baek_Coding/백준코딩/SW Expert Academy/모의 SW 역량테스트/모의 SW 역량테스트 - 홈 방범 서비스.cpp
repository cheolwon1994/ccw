#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int cost[40];
int arr[20][20];
struct info {
	int x, y;
};
info tmp;
vector<info> v;
int num, bill, result;

void find(int y, int x) {
	int dist[40];
	int cx, cy, d, maxi, house, cnt;
	memset(dist, 0, sizeof(dist));
	dist[1] = 1;
	maxi = 1;
	for (int i = 0; i < v.size(); i++) {
		if (y == v[i].y && x == v[i].x)
			continue;
		cx = v[i].x;
		cy = v[i].y;
		d = abs(cx - x) + abs(cy - y) + 1;
		maxi = max(maxi, d);
		dist[d]++;
	}	
	if (arr[y][x] == 1) {
		house = 1;
		cnt = 1;
	}
	else {
		house = 0;
		cnt = 0;
	}
	for (int i = 2; i <= maxi; i++) {
		cnt += dist[i];
		if (cost[i] <= cnt * bill)
			house = cnt;
	}
	
	result = max(result, house);
}

int main() {
	int test;
	cin >> test;
	for (int i = 1; i < 40; i++)
		cost[i] = i * i + (i - 1)*(i - 1);
	for (int t = 1; t <= test; t++) {
		//ÃÊ±âÈ­
		v.clear();
		result = 1;
		cin >> num >> bill;
		for (int i = 0; i < num; i++)
			for (int j = 0; j < num; j++) {
				cin >> arr[i][j];
				if (arr[i][j] == 1) {
					tmp.x = j;
					tmp.y = i;
					v.push_back(tmp);
				}
			}
		for (int i = 0; i < num; i++)
			for (int j = 0; j < num; j++)
				find(i, j);
		cout << "#" << t << " " << result << endl;
	}
	system("pause");
	return 0;
}