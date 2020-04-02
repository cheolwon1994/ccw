#include <iostream>
using namespace std;
long long MOD = 1000000007;
int n, k;

long long pow(long long num, long long idx) {
	if (idx == 0) return 1;
	else if (idx == 1) return num;
	if (idx % 2 == 0) {
		long long temp = pow(num,idx/2) % MOD;
		return (temp*temp) % MOD;
	}
	long long temp = pow(num, idx - 1) % MOD;
	return (num*temp) % MOD;
}

int main() {
	cin >> n >> k;
	long long up = 1, down = 1, result;
	for (int i = 2; i <= n; i++) {
		up *= i;
		up %= MOD;
	}
	for (int i = 1; i <= n - k; i++) {
		down *= i;
		down %= MOD;
	}
	for (int i = 1; i <= k; i++) {
		down *= i;
		down %= MOD;
	}
	result = up*pow(down, MOD - 2);
	cout << result % MOD;
	system("pause");
	return 0;
}