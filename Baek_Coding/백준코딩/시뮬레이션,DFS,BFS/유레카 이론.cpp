#include <iostream>
#include <algorithm>
using namespace std;
int dp[45];
bool flag;
int num;

void start(int cnt, int sum) {
	if (cnt == 3) {
		if (sum == num) 
			flag = true;
		return;
	}
	for (int i = 1; i < 45; i++) {
		if (sum + dp[i] <= num) {
			start(cnt + 1, sum + dp[i]);
			if (flag)
				break;
		}
		else 
			break;		
	}
}

int main() {
	int test;
	cin >> test;
	for (int i = 1; i < 45; i++) 
		dp[i] = i * (i + 1) / 2;

	for (int t = 0; t < test; t++) {
		cin >> num;
		flag = false;
		if (num < 3) {
			cout << 0 << endl;
			continue;
		}
		start(0,0);
		if (flag)
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}
	system("pause");
	return 0;
}