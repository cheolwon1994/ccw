#include <iostream>
using namespace std;
int test;
int l, r;
long long arr[32][32];
int main() {
	for (int i = 0; i < 31; i++) {
		arr[0][i] = 1;
		arr[i][0] = 1;
	}
	for (int i = 0; i <= 31; i++) 
		for (int j = 0; j < i; j++) 
			arr[i + 1][j + 1] = arr[i][j] + arr[i][j + 1];
	cin >> test;
	for (int t = 0; t < test; t++) {
		cin >> l >> r;
		cout << arr[r+1][l] << endl;
	}
	system("pause");
	return 0;
}