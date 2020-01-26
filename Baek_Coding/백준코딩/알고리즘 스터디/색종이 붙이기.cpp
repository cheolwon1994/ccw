#include <iostream>
#include <algorithm>
using namespace std;
bool all_zero = true;
int arr[10][10];
int paper[6] = { 0,5,5,5,5,5 };
int result = 1000;

void cover(int y, int x, int len, int num) {
	for (int i = y; i < y + len; i++)
		for (int j = x; j < x + len; j++)
			arr[i][j] = num;
}

bool try_cover(int y, int x, int len) {
	bool flag = true;
	for (int i = y; i < y + len; i++) {
		for (int j = x; j < x + len; j++) {
			if (arr[i][j] == 0) {
				flag = false;
				break;
			}
		}
		if (!flag)
			break;
	}
	return flag;
}

void find(int y, int x) {
	if (x == 10) { y += 1; x = 0; }
	if (y == 10) {
		bool all_cover = true;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++)
				if (arr[i][j] == 1) {
					all_cover = false;
					break;
				}
			if (!all_cover)
				break;
		}
		if (all_cover) {
			int temp = 0;
			for (int i = 1; i < 6; i++)
				temp += (5 - paper[i]);
			result = min(result, temp);
		}
		return;
	}
	if (arr[y][x] == 1) {
		for (int k = 1; k < 6; k++) {
			if (y + k <= 10 && x + k <= 10 && paper[k]>0) {
				bool avail = try_cover(y, x, k);
				if (avail) {
					cover(y, x, k, 0);
					paper[k]--;
					find(y, x + k);
					paper[k]++;
					cover(y, x, k, 1);
				}
			}
		}
	}
	else
		find(y, x + 1);
}

int main() {
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1)
				all_zero = false;
		}
	if (all_zero)
		cout << 0;
	else {
		find(0, 0);
		if (result == 1000)
			cout << -1;
		else
			cout << result;
	}
	system("pause");
	return 0;
}