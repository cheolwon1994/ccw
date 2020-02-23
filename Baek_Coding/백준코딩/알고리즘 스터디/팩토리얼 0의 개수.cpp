#include <iostream>
using namespace std;
int arr[501][2];		//2,5
int dp[501][2];
int main() {
	for (int i = 2; i < 501; i++) {
		int tt = i;
		while (tt % 2 == 0) {
			arr[i][0]++;
			tt /= 2;
		}
		while (tt % 5 == 0) {
			arr[i][1]++;
			tt /= 5;
		}
	}
	for (int i = 2; i < 501; i++) {
		dp[i][0] = dp[i - 1][0] + arr[i][0];
		dp[i][1] = dp[i - 1][1] + arr[i][1];
	}
	int num;
	cin >> num;
	int small = dp[num][0] < dp[num][1] ? dp[num][0] : dp[num][1];
	cout << small;
	system("pause");
}