#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
vector<int> v;
bool dp[40001] = { false, };
int arr[31];
int main() {
	int num, tt, question;
	cin >> num;
	for (int i = 0; i < num; i++) 
		cin >> arr[i];
	
	cin >> question;	
	v.push_back(0);
	dp[0] = true;


	for (int i = 0; i < num; i++) {
		int len = v.size();
		int n = arr[i];
		for (int j = 0; j < len; j++) {
			int tt = v[j];
			if (!dp[n + tt]) {
				dp[n + tt] = true;
				v.push_back(n + tt);
			}
			tt = abs(tt - n);
			if (!dp[tt]) {
				dp[tt] = true;
				v.push_back(tt);
			}
		}
	}

	for (int i = 0; i < question; i++) {
		cin >> tt;
		if (dp[tt]) cout << 'Y' << ' ';
		else if (!dp[tt]) cout << 'N' << ' ';
	}
	system("pause");
	return 0;
}