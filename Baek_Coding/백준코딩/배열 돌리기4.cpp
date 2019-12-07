#define _CRT_NO_SECURE_WARNINGS
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int row, col;
int arr[51][51];
int dup_arr[51][51];
int result = 987654321;

struct info {
	int x;
	int y;
	int len;
};
vector<info> rot;
info tmp;

void rotate_arr(int y, int x, int len) {
	int tmp = dup_arr[y - len][x - len];
	int ys = y - len;
	int xs = x - len;
	for (int i = 0; i < 2 * len; i++)
		dup_arr[y - len + i][x - len] = dup_arr[y - len + i + 1][x - len];
	for (int i = 0; i < 2 * len; i++)
		dup_arr[y + len][x - len + i] = dup_arr[y + len][x - len + i + 1];
	for (int i = 0; i < 2 * len; i++)
		dup_arr[y + len - i][x + len] = dup_arr[y + len - 1 - i][x + len];
	for (int i = 0; i < 2 * len; i++) {
		if (i == 2 * len - 1)
			dup_arr[y - len][x + len - i] = tmp;
		else
			dup_arr[y - len][x + len - i] = dup_arr[y - len][x + len - i - 1];
	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int rot_num;
	cin >> row >> col >> rot_num;
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++)
			cin >> arr[i][j];
			
	for (int i = 0; i < rot_num; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		tmp.y = a;
		tmp.x = b;
		tmp.len = c;
		rot.push_back(tmp);
	}
	vector<int> v;
	for (int i = 0; i < rot_num; i++)
		v.push_back(i);
	do {
		for (int i = 1; i <= row; i++) 
			for (int j = 1; j <= col; j++)
				dup_arr[i][j] = arr[i][j];		

		int y, x, len;
		for (int i = 0; i < rot_num; i++) {
			y = rot[v[i]].y;
			x = rot[v[i]].x;
			len = rot[v[i]].len;
			for (int j = 1; j <= len; j++)
				rotate_arr(y, x, j);
		}
		
	/*for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++)
			cout << dup_arr[i][j];
		cout << "\n";
	}
	cout << "\n\n";*/
		int sum = 0;
		for (int i = 1; i <= row; i++) {
			sum = 0;
			for (int j = 1; j <= col; j++)
				sum += dup_arr[i][j];
			result = min(result, sum);
		}
	} while (next_permutation(v.begin(), v.end()));
	cout << result;
	system("PAUSE");
	return 0;
}