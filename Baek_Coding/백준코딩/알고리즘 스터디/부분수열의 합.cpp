#include <iostream>
#include <string.h>
using namespace std;
int num, sum;
int result = 0;
int arr[20];
bool check[20];
int ans[20];

void dfs(int cnt) {
	if (cnt == num) {
		int tmp = 0;
		bool flag = false;
		for (int i = 0; i < num; i++) {
			if (check[i]) {
				tmp += ans[i];
				flag = true;
			}
		}
		if (sum == tmp && flag)
			result++;
		return;
	}
	ans[cnt] = arr[cnt];
	check[cnt] = true;
	dfs(cnt + 1);
	check[cnt] = false;
	ans[cnt] = 0;
	dfs(cnt + 1);
}

int main() {
	cin >> num >> sum;
	for (int i = 0; i < num; i++)
		cin >> arr[i];
	dfs(0);
	cout << result;
	system("pause");
	return 0;
}