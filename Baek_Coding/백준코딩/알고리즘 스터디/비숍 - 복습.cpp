#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int num, result[2];
struct info {
	int x, y;
};
info tmp;
vector<info> v;
int arr[10][10];

void bishop(int y, int x, int cnt, int color) {
	if (x >= num) {
		y += 1;
		if (color == 0) {
			if (y % 2 == 0) x = 0;
			else x = 1;			
		}
		else if (color == 1) {
			if (y % 2 == 0) x = 1;
			else x = 0;
		}
	}
	if (y == num) {
		if (color == 0)		result[0] = max(result[0], cnt);
		else	result[1] = max(result[1], cnt);
		return;
	}
	if (arr[y][x] == 0)		bishop(y, x + 2, cnt, color);
	else {
		bool avail = true;
		for (int i = 0; i < v.size(); i++) {
			int cx = v[i].x;
			int cy = v[i].y;
			if (cx + cy == y + x || cx - x == cy - y) {
				avail = false;
				break;
			}
		}
		if (avail) {
			tmp.x = x;
			tmp.y = y;
			v.push_back(tmp);
			bishop(y, x + 2, cnt + 1, color);
			v.pop_back();
		}
		bishop(y, x + 2, cnt, color);
	}
}

int main() {
	cin >> num;
	int val;
	for (int i = 0; i < num; i++)
		for (int j = 0; j < num; j++) 
			cin >> arr[i][j];	
	bishop(0, 0, 0, 0);
	bishop(0, 1, 0, 1);
	cout << result[0] + result[1];
	system("pause");
	return 0;
}