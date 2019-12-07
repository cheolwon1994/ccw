#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string.h>
#include <stack>
using namespace std;
int waste_time[16];
int payment[16];
int num;
int result = -1;
int dp[16];

int main() {
	cin >> num;
	for (int i = 1; i <= num; i++) 
		cin >> waste_time[i] >> payment[i];
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= num+1; i++) {
		for (int j = 1; j <= i; j++) {
			if (j + waste_time[j] == i) 
				dp[i] = max(dp[i], dp[j] + payment[j]);			
			if (j == i)
				dp[i] = max(dp[i], dp[i - 1]);
		}
	}
	for (int i = 1; i <=num+1 ; i++) 
		result = max(result, dp[i]);
	cout << result;
	return 0;
}