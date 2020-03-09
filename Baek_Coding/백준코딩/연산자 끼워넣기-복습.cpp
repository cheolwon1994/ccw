#define MAX 9876543210
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<long long> number;
vector<int> op;
bool flag[11] = { false, };
long long maxi = -MAX;
long long mini = MAX;
int num, tt;

void dfs(int cnt, long long result) {
	if (cnt == num - 1) {
		maxi = max(maxi, result);
		mini = min(mini, result);
		return;
	}
	for (int i = 0; i < num - 1; i++) {
		if (!flag[i]) {
			flag[i] = true;
			//°è»ê
			long long val;
			if (op[i] == 0)
				val = result + number[cnt + 1];
			else if (op[i] == 1)
				val = result - number[cnt + 1];
			else if (op[i] == 2)
				val = result * number[cnt + 1];
			else
				val = result / number[cnt + 1];
			dfs(cnt + 1, val);
			flag[i] = false;
		}
	}
}

int main() {
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> tt;
		number.push_back(tt);
	}
	for (int i = 0; i < 4; i++) {
		cin >> tt;
		for (int j = 0; j < tt; j++)
			op.push_back(i);
	}
	dfs(0,number[0]);
	cout << maxi << '\n' << mini;
	system("pause");
	return 0;
}