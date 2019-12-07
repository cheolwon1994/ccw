#define CRT_NO_SECURE_WARNINGS
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
using namespace std;
long long result = 0;
int temp;
vector <int> building;		//2~1001까지 사용 -> 0,1,1002,1003 사용x
struct info {
	int height;
	int second;
	int idx;
};
info dp[1004];
info tmp;

void check() {
	for (int i = 2; i < temp - 2; i++) {
		if (i == dp[i].idx && dp[i].height !=dp[i].second) {		//second랑 제일큰거랑 같을 수 있음
			result += dp[i].height - dp[i].second;
		}
	}
}

void dp_cal() {
	tmp.height = 0;
	tmp.idx = 0;
	tmp.second = 0;
	dp[0] = tmp;
	tmp.idx = 1;
	dp[1] = tmp;
	int ix, mh;
	vector<int> test;
	for (int i = 2; i < temp - 2; i++) {
		test.clear();
		for (int j = i - 2; j < i + 3; j++) 
			test.push_back(building[j]);		
		sort(test.begin(), test.end());
		mh = test[4];
		tmp.second = test[3];
		for (int j = i - 2; j < i + 3; j++) {
			if (building[j] == mh) {
				tmp.idx = j;
				tmp.height = mh;
			}
		}
		dp[i] = tmp;
	}
}

int main() {
	int test_Case = 10;
	for (int i = 0; i < test_Case; i++) {
		cin >> temp;
		building.clear();
		int t;
		result = 0;
		for (int j = 0; j < temp; j++) {
			cin >> t;
			building.push_back(t);
		}
		dp_cal();
		check();
		cout << "#"<<i + 1 << " " << result << endl;
	}

	system("PAUSE");
	return 0;
}