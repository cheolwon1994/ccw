#define MAX 987654321
#include <iostream>
#include <algorithm>
using namespace std;
bool visit[101][21][51] = { false, };		//idx,구멍위치,사용한 제한횟수
bool tree[101][21] = { false, };
int dp[101][21];

int main() {
	int num, ability, hole, height;
	cin >> num >> ability;
	for (int i = 0; i < num; i++) {
		cin >> hole;
		for (int j = 0; j < hole; j++) {
			cin >> height;
			tree[i + 1][height] = true;
		}
	}
	for (int i = 0; i <= num; i++)
		for (int j = 1; j < 21; j++)
			dp[i][j] = MAX;
	tree[0][1] = true;
	dp[0][1] = 0;
	for (int j = 1; j <= num; j++) {
		for (int i = 1; i <= 20; i++) {
			if (tree[j][i]) {
				if (tree[j - 1][i])
					dp[j][i] = min(dp[j][i], dp[j - 1][i]);
				if (tree[j - 1][i - 1])
					dp[j][i] = min(dp[j][i], dp[j - 1][i - 1]);
				if (tree[j - 1][i + 1])
					dp[j][i] = min(dp[j][i], dp[j - 1][i + 1]);				
				if (i == 20) {
					for (int k = 10; k < 21; k++)
						if(tree[j-1][k])
							dp[j][i] = min(dp[j][i], dp[j - 1][k]);
				}
				if (i % 2 == 0 && tree[j - 1][i / 2])
					dp[j][i] = min(dp[j][i], dp[j - 1][i / 2]);
				for (int k = 1; k < 21; k++) {
					if (tree[j - 1][k])
						dp[j][i] = min(dp[j][i], dp[j - 1][k] + 1);
				}
			}
		}
	}
	int result = MAX;
	for (int i = 1; i < 21; i++) {
		if (dp[num][i] > ability) continue;
		result = min(result, dp[num][i]);
	}
	if (result == MAX) result = -1;
	cout << result;
	system("pause");
	return 0;
}