#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
struct info {
	int x, y;
};
info tmp;
int cost[41], dist[41];
int arr[20][20];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int num, cc, result;
vector<info> v;

void find(int y, int x) {
	for (int i = 1; i < 41; i++)
		dist[i] = 0;
	for (int i = 0; i < v.size(); i++) {
		int d = abs(v[i].x - x) + abs(v[i].y - y) + 1;
		dist[d]++;
	}
	int cnt = 0;
	for (int i = 1; i < 41; i++) {
		cnt += dist[i];
		if (cnt*cc >= cost[i])
			result = max(result, cnt);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int test;
	cin >> test;
	for (int i = 1; i < 41; i++)
		cost[i] = i * i + (i - 1)*(i - 1);

	for (int t = 1; t <= test; t++) {
		//초기화
		result = 1;
		v.clear();

		cin >> num >> cc;
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
		cout << "#" << t << " " << result << '\n';
	}
	return 0;
}