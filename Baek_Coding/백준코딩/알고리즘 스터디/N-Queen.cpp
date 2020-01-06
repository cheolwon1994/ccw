#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int num;
int row[15];		//어떤 j값이 들어갔는지
int result = 0;

void queen(int y, int x, int cnt) {
	if (cnt == num) { result++; return; }
	if (x == num) {
		if (row[y] == -1)
			return;
		else
			x = 0;  y += 1;
	}
	if (y == num) { return; }
	int cx, cy;
	bool avail = true;

	for (int i = 0; i < y; i++) {
		cx = row[i];
		cy = i;
		if (row[i] == x) {			//세로 확인
			avail = false;
			break;
		}
		if (x + y == cx + cy) {		// 1->7시 확인
			avail = false;
			break;
		}
		if (x - y == cx - cy) {		// 11->5시 확인
			avail = false;
			break;
		}
	}
	if (avail) {		//가능한 위치
		row[y] = x;
		queen(y + 1, 0, cnt + 1);
		row[y] = -1;
	}
	queen(y, x + 1, cnt);
}

int main() {
	cin >> num;
	memset(row, -1, sizeof(row));
	queen(0, 0, 0);
	cout << result;
	system("pause");
	return 0;
}