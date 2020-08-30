#define MOD 15746
#include <iostream>
using namespace std;
int arr[1000001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int num;
	cin >> num;
	arr[1] = 1;
	arr[2] = 2;
	for (int i = 3; i <= num; i++)
		arr[i] = (arr[i - 1] + arr[i - 2]) % MOD;
	cout << arr[num] % MOD;
	return 0;
}