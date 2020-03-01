#define MOD 1000000007
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long N;
int M;

vector<vector<long long>> cal(vector<vector<long long>> &a, vector<vector<long long>> &b) {
	vector<vector<long long>> result(M, vector<long long>(M, 0));
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			long long tt = 0;
			for (int k = 0; k < M; k++)
				tt += (a[i][k] * b[k][j]) % MOD;
			result[i][j] = tt % MOD;
		}
	}
	return result;
}

int main() {	
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> M;
	long long sum = 0;
	vector<vector<long long> > v(M, vector<long long>(M, 0));
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			if (i == 0) {
				v[i][0] = 1; v[i][M - 1] = 1;
			}
			else {
				if (i == j + 1) v[i][j] = 1;
			}
		}
	}
	vector<vector<long long> > ans(M, vector<long long>(M, 0));
	for (int i = 0; i < M; i++)
		ans[i][i] = 1;
	while (N > 0) {
		if (N%2 == 1) {
			ans = cal(ans, v);
		}
		v = cal(v, v);
		N /= 2;
	}
	sum = ans[0][0];
	cout << sum;
	system("pause");
	return 0;
}