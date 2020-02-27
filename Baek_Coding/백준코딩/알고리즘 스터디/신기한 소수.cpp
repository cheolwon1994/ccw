#include <iostream>
#include <math.h>
using namespace std;
int num;
int primary[4] = { 2,3,5,7 };

bool check(int num) {
	int i = 2;
	while (1) {
		if (i <= sqrt(num)) {
			if (num%i == 0) {
				return false;
			}
			else
				i++;
		}
		else
			return true;
	}
}

void dfs(int cnt, int sum) {
	if (cnt == num) {
		cout << sum << '\n';
		return;
	}
	if (cnt == 0) {
		for (int i = 0; i < 4; i++)
			dfs(cnt + 1, primary[i]);
	}
	else {
		for (int i = 1; i < 10; i++) {
			int tt = sum * 10 + i;
			if (check(tt))	dfs(cnt + 1, tt);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> num;
	dfs(0, 0);
	system("pause");
	return 0;
}