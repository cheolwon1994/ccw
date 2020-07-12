#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int arr[50][50], row, col, ans = 1, mini;

void test(int y, int x, int len) {
	bool flag = true;
	if (arr[y][x] != arr[y + len][x]) flag = false;
	if (arr[y][x] != arr[y][x + len]) flag = false;
	if (arr[y][x] != arr[y + len][x + len]) flag = false;
	if (flag)
		ans = max(ans, (len + 1) * (len + 1));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> row >> col;
	string str;
	for (int i = 0; i < row; i++) {
		cin >> str;
		for (int j = 0; j < col; j++)
			arr[i][j] = str[j] - '0';
	}
	mini = min(row, col);
	for (int k = 2; k <= mini; k++) {
		for (int i = 0; i <= row - k; i++) {
			for (int j = 0; j <= col - k; j++) {
				test(i,j,k-1);
			}
		}
	}
	cout << ans;
	return 0;
}