#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
int num, result;
int arr[9];
int tot;
bool check[9] = { false };
vector<int> v;

void order(long long l, long long r, int cnt,int remain) {
	if (l >= r + remain) {
		int tmp = 1;
		for (int i = 0; i < num - cnt; i++)
			tmp *= 2;
		for (int i = num - cnt; i > 0; i--)
			tmp *= i;
		result += tmp;
		return;
	}
	if (cnt == num) {
		result++;
		return;
	}
	for (int i = 0; i < num; i++) {
		if (!check[i]) {
			check[i] = true;
			order(l + arr[i], r, cnt + 1,remain-arr[i]);
			if (l >= r + arr[i])
				order(l, r + arr[i], cnt + 1,remain-arr[i]);
			check[i] = false;
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		result = 0;
		tot = 0;
		cin >> num;
		memset(check, false, sizeof(check));
		v.clear();
		for (int j = 0; j < num; j++) {
			cin >> arr[j];
			tot += arr[j];
		}
		order(0,0,0,tot);
		cout << "#" << t << " " << result << endl;
	}
	system("pause");
	return 0;
}