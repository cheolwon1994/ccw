#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
int num;
vector<int> v;
int arr[6];
bool check[14];

void dfs(int cnt) {
	if (cnt == 6) {
		for (int i = 0; i < 6; i++)
			cout << arr[i] << " ";
		cout << endl;
		return;
	}
	for (int i = 0; i < num; i++) {
		if (cnt == 0) {
			check[i] = true;
			arr[cnt] = v[i];
			dfs(cnt + 1);
			check[i] = false;
			arr[cnt] = 0;
		}
		else if (cnt > 0) {
			if (arr[cnt - 1] < v[i]) {
				check[i] = true;
				arr[cnt] = v[i];
				dfs(cnt + 1);
				arr[cnt] = 0;
				check[i] = false;
			}
		}
	}
}
int main() {
	int tt;
	while (1) {
		cin >> num;
		if (num == 0)
			break;
		//√ ±‚»≠
		v.clear();
		memset(arr, 0, sizeof(arr));
		memset(check, false, sizeof(check));

		for (int i = 0; i < num; i++) {
			cin >> tt;
			v.push_back(tt);
		}
		dfs(0);
		cout << endl;
	}
	system("pause");
	return 0;
}