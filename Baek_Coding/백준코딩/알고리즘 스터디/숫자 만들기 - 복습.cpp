#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;
vector<long long> number;
int op[4];
int test, num, val;
long long mini, maxi;

void dfs(int idx, long long sum) {
	if(idx == num) {
		//계산
		mini = min(mini, sum);
		maxi = max(maxi, sum);
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (op[i] > 0) {
			op[i]--;
			long long temp;
			if (i == 0) temp = sum + number[idx];
			else if (i == 1) temp = sum - number[idx];
			else if (i == 2) temp = sum * number[idx];
			else if (i == 3) temp = sum / number[idx];
			dfs(idx + 1, temp);
			op[i]++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> test;
	for (int t = 1; t <= test; t++) {
		//초기화
		number.clear();
		mini = LLONG_MAX;
		maxi = LLONG_MIN;

		cin >> num;
		for (int i = 0; i < 4; i++) 
			cin >> op[i];
		for (int i = 0; i < num; i++) {
			cin >> val;
			number.push_back(val);
		}
		dfs(1, number[0]);
		cout << "#" << t << " " << maxi - mini << '\n';
	}
	return 0;
}