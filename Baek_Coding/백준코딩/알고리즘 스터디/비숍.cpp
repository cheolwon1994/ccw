#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int num;
int max_w = 0;
int max_b = 0;
int arr[10][10];
struct info {
	int x, y;
};
info tmp;
vector<info> v[2];		//w,b
/*****************
WBWBWBWBWB...
BWBWBWBWBW...
WBWBWBWBWB...
*****************/

bool check(int y, int x, char c) {
	bool flag = true;
	vector<info> t;
	if (c == 'W')
		t = v[0];
	else
		t = v[1];
	int cx, cy;
	for (int i = 0; i < t.size(); i++) {
		cx = t[i].x;
		cy = t[i].y;
		if (cx + cy == y + x || cx - cy == x - y) {
			flag = false;
			break;
		}
	}
	return flag;
}

void start(int y, int x, int cnt, char c) {
	if (x >= num) {
		y += 1;
		if (c == 'W') {
			if (y % 2 == 1)	x = 1;
			else x = 0;
		}
		else if (c == 'B') {
			if (y % 2 == 1)	x = 0;
			else x = 1;
		}
	}
	if (y == num) {
		if (c == 'W')
			max_w = max(max_w, cnt);
		else if (c == 'B')
			max_b = max(max_b, cnt);
		return;
	}

	if (arr[y][x] == 1 && check(y, x, c)) {
		tmp.x = x;
		tmp.y = y;
		if (c == 'W')
			v[0].push_back(tmp);
		else
			v[1].push_back(tmp);
		start(y, x + 2, cnt + 1, c);
		if (c == 'W')
			v[0].pop_back();
		else
			v[1].pop_back();
		
	}
	start(y, x + 2, cnt, c);
}

int main() {
	cin >> num;
	for (int i = 0; i < num; i++)
		for (int j = 0; j < num; j++)
			cin >> arr[i][j];
	start(0, 0, 0,'W');		//Èò»ö
	start(0, 1, 0,'B');		//°ËÁ¤»ö
	cout << max_w + max_b;
	system("pause");
	return 0;
}