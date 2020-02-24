#include <iostream>
using namespace std;
int num;
long long result = 0;
long long dp[33][33][3];		//i,j,µµÂø ¹æÇâ
int arr[33][33];
int main() {
	cin >> num;
	for (int i = 1; i <= num; i++)
		for (int j = 1; j <= num; j++)
			cin >> arr[i][j];
	
	dp[1][2][0] = 1;
	if (arr[num][num] != 1) {
		for (int i = 1; i <= num; i++) {
			for (int j = 2; j <= num; j++) {
				if (i == 1 && j == 2) continue;
				if (arr[i][j] == 0) {
					if(arr[i][j - 1]==0)
						dp[i][j][0] = dp[i][j - 1][2] + dp[i][j - 1][0];
					if(arr[i - 1][j]==0)
						dp[i][j][1] = dp[i - 1][j][1] + dp[i - 1][j][2];
					if(arr[i][j - 1] == 0 && arr[i - 1][j] == 0 && arr[i - 1][j-1]==0)
						dp[i][j][2] = dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
				}
			}
		}
		for (int k = 0; k < 3; k++)
			result += dp[num][num][k];
	}
	cout << result;
	system("pause");
	return 0;
}