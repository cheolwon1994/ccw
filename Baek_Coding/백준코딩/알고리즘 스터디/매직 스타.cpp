#include <iostream>
#include <string>
using namespace std;
struct info {
	int x, y;
};
info tmp;
char arr[5][9];
bool check[12] = { false, };
bool finish = false;
int num[12];
int test[6][4] = {
	{0,2,5,7},
	{0,3,6,10},
	{7,8,9,10},
	{1,2,3,4},
	{1,5,8,11},
	{4,6,9,11}
};

void dfs(int idx) {
	if (finish) return;
	if (idx == 12) {
		int t = 0;
		for (int j = 0; j < 4; j++)
			t += num[test[4][j]];
		if (t != 22)	return;
		t = 0;
		for (int j = 0; j < 4; j++)
			t += num[test[5][j]];
		if (t != 22)	return;
		int cnt = 0;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 9; j++) {
				if (arr[i][j] != '.') {
					char c = num[cnt++] + 'A';
					cout << c;
				}
				else
					cout << arr[i][j];
			}
			cout << '\n';
		}
		finish = true;
		return;
	}
	if (idx == 5) {
		int t = 0;
		for (int j = 0; j < 4; j++)
			t += num[test[3][j]];
		if (t != 22) return;
	}
	else if (idx == 8) {
		int t = 0;
		for (int j = 0; j < 4; j++)
			t += num[test[0][j]];
		if (t != 22) return;
	}
	else if (idx == 11) {
		int t = 0;
		for (int j = 0; j < 4; j++)
			t += num[test[2][j]];
		if (t != 22) return;
		t = 0;
		for (int j = 0; j < 4; j++)
			t += num[test[1][j]];
		if (t != 22) return;
	}
	if (num[idx] != -1) dfs(idx + 1);		//이미 번호가 있는 경우
	else {
		for (int i = 0; i < 12; i++) {
			if (check[i]) continue;
			check[i] = true;
			num[idx] = i;
			dfs(idx + 1);
			num[idx] = -1;
			check[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int cnt = 0;
	for (int i = 0; i < 12; i++)	num[i] = -1;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 9; j++) {
			cin >> arr[i][j];
			char c = arr[i][j];
			if (c != '.') {
				if (c == 'x') cnt++;
				else {
					check[c - 'A'] = true;
					num[cnt++] = c - 'A';
				}
			}
		}
	dfs(0);
	return 0;
}