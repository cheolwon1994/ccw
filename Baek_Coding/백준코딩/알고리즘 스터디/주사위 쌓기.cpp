#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int num, val, result = 0;
vector<int> dice[10000];
int maxi[10000][3];

int number[3][4] = {
	{1,2,3,4},
	{0,2,4,5},
	{0,1,3,5}
};
int rev[6] = { 5,3,4,1,2,0 };		//각각 반대편숫자 idx

void dfs(int level, int sum, int up) {
	if (level == num) {
		result = max(result, sum);
		return;
	}
	for (int i = 0; i < 6; i++) {
		int v = dice[level][i];
		if (v == up) {
			int nup = dice[level][rev[i]];
			int temp = i;
			if(i>2) temp = rev[i];
			dfs(level + 1, sum+maxi[level][temp], nup);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> num;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> val;
			dice[i].push_back(val);
		}
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 4; k++) {
				int nv = dice[i][number[j][k]];
				maxi[i][j] = max(maxi[i][j], nv);
			}
		}
	}
	for (int i = 0; i < 6; i++) {
		int up = dice[0][i];		//제일 위 숫자
		int temp = i;
		if (i > 2) temp = rev[i];
		dfs(1, maxi[0][temp], up);
	}
	cout << result;
	return 0;
}