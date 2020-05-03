#include <iostream>
using namespace std;
long long factorial[4000001];
long long rev[4000001];
long long MOD = 1000000007;

long long my_pow(long long num, long long remain) {
	if (remain == 0) return 1;
	else if (remain == 1) return num;
	if (remain % 2 == 0) {
		long long temp = my_pow(num, remain / 2);
		return (temp*temp) % MOD;
	}
	else if (remain % 2 == 1) {
		long long temp = my_pow(num, remain - 1);
		return (temp*num) % MOD;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int m, n, k;
	cin >> m;
	factorial[0] = 1;
	for (int i = 1; i < 4000001; i++) {
		factorial[i] = factorial[i - 1] * i;
		factorial[i] %= MOD;
	}
	rev[4000000] = my_pow(factorial[4000000], MOD - 2) % MOD;
	for (int i = 3999999; i >= 0; i--)
		rev[i] = (rev[i + 1] * (i + 1)) % MOD;
	for (int i = 0; i < m; i++) {
		cin >> n >> k;
		long long up = factorial[n];
		long long down = rev[k];
		down *= rev[n - k];
		down %= MOD;
		cout << (up*down) % MOD << '\n';
	}
	system("pause");
	return 0;
}