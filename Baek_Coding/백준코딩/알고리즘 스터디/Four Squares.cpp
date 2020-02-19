#include <iostream>
#include <algorithm>
using namespace std;
int dp[225];
int num, result = 987654321;
void cal(int cnt, int maxi,int remain) {
	if (cnt >= result) return;
	if (remain == 0) {
		result = min(result,cnt);
		return;
	}
	int idx = 0;
	for (int i = 1; i <= maxi; i++) {
		if (remain < dp[i]) {
			idx = i-1;
			break;
		}
	}
	for (int i = idx; i > 0; i--) {
		cal(cnt + 1, i,remain - dp[i]);
	}
}

int main() {
	for (int i = 1; i < 225; i++)
		dp[i] = i * i;
	cin >> num;
	cal(0,225,num);
	cout << result;
	system("pause");
	return 0;
}