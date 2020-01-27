#define MAX 9876543210;
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long mini = MAX;
long long maxi = -MAX;
int num, tt;
int arr[11];
bool check[10] = { false, };
int op[4];
vector<int> all_op;
vector<int> order;

void cal(int idx, long long sum) {
	if (idx == order.size()) {
		mini = min(mini, sum);
		maxi = max(maxi, sum);
		return;
	}
	if (order[idx] == 0) cal(idx + 1, sum + arr[idx + 1]);
	else if (order[idx] == 1) cal(idx + 1, sum - arr[idx + 1]);
	else if (order[idx] == 2) cal(idx + 1, sum * arr[idx + 1]);
	else if (order[idx] == 3) cal(idx + 1, (int)(sum /arr[idx + 1]));
}

void dfs(int cnt) {
	if(cnt == num - 1) {
		cal(0,arr[0]);
		return;
	}
	for (int i = 0; i < all_op.size(); i++) {
		if (!check[i]) {
			check[i] = true;
			order.push_back(all_op[i]);
			dfs(cnt + 1);
			order.pop_back();
			check[i] = false;
		}
	}
}

int main() {
	cin >> num;
	for (int i = 0; i < num; i++)
		cin >> arr[i];
	for (int i = 0; i < 4; i++) 
		cin >> op[i];
	for (int i = 0; i < 4; i++) {
		tt = op[i];
		for (int j = 0; j < tt; j++)
			all_op.push_back(i);
	}
	dfs(0);
	cout << maxi << endl << mini;
	system("pause");
	return 0;
}