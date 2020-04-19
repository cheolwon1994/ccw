#include <iostream>
#include <algorithm>
using namespace std;
long long dp[100][100001], result = 0;
int arr[100][2];		//무게, 가치
int num, weight;

long long knapsack(int idx, int remain) {
	if (idx == num) return 0;
	long long temp = dp[idx][remain];
	if (temp != -1) return temp;
	if (arr[idx][0] <= remain) 		//추가 가능
		temp = knapsack(idx + 1, remain - arr[idx][0]) + arr[idx][1];
	temp = max(temp, knapsack(idx + 1, remain));
	result = max(result, temp);
	return dp[idx][remain] = temp;
}

int main() {
	cin >> num >> weight;
	for (int i = 0; i < num; i++) {
		cin >> arr[i][0] >> arr[i][1];
		for (int j = 0; j <= weight; j++)
			dp[i][j] = -1;
	}
	knapsack(0, weight);
	cout << result;
	system("pause");
	return 0;
}