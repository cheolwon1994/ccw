#define MAX 987654321
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int row, col, cmd, result;
int arr[52][52];
int dup[52][52];
struct info {
	int y, x, dist;
};
info tmp;
vector<info> v;
vector<int> order;
bool flag[6] = { false, };

void rotate(int y, int x, int dist) {
	int t = dist;
	while (t > 0) {
		int temp = dup[y-t][x-t];	
		int tt = 2 * t;
		for (int j = 0; j < tt; j++)
			dup[y - t + j][x - t] = dup[y - t + j+1][x - t];
		for (int j = 0; j < tt; j++)
			dup[y + t][x - t + j] = dup[y + t][x - t + j+1];
		for (int j = 0; j < tt; j++)
			dup[y + t - j][x + t] = dup[y + t - j-1][x + t];
		for (int j = 0; j < tt; j++)
			dup[y-t][x+t-j] = dup[y - t][x + t - j-1];
		dup[y - t][x - t + 1] = temp;
		t--;
	}
}

void dfs(int cnt) {
	if (cnt == cmd) {
		//배열 돌리기
		for (int i = 1; i <= row; i++)
			for (int j = 1; j <= col; j++)
				dup[i][j] = arr[i][j];
		for (int i = 0; i < cmd; i++)
			rotate(v[order[i]].y, v[order[i]].x, v[order[i]].dist);
		int sum = MAX;
		for (int i = 1; i <= row; i++) {
			int t_sum = 0;
			for (int j = 1; j <= col; j++)
				t_sum += dup[i][j];
			sum = min(sum, t_sum);
		}
		result = min(result, sum);
		return;
	}
	for (int i = 0; i < cmd; i++) {
		if (!flag[i]) {
			flag[i] = true;
			order.push_back(i);
			dfs(cnt + 1);
			order.pop_back();
			flag[i] = false;
		}
	}
}

int main() {
	cin >> row >> col >> cmd;
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++)
			cin >> arr[i][j];
	int y, x, dist;
	result = MAX;
	for (int i = 0; i < cmd; i++) {
		cin >> y >> x >> dist;
		tmp.x = x;
		tmp.y = y;
		tmp.dist = dist;
		v.push_back(tmp);
	}
	dfs(0);
	cout << result;
	system("pause");
	return 0;
}