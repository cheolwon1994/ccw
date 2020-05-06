#define MAX 987654321
#include <iostream>
#include <algorithm>
using namespace std;
int arr[1001][1001];
int check[1001][1001];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int row, col, maxi = 0;
	cin >> row >> col;
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++) {
			cin >> arr[i][j];
			check[i][j] = 0;
			if (arr[i][j] == 0) {
				int tt = MAX;
				tt = min(tt, check[i - 1][j]);
				tt = min(tt, check[i][j - 1]);
				tt = min(tt, check[i - 1][j - 1]);
				if (tt == MAX) tt = 0;
				check[i][j] = tt + 1;
				maxi = max(maxi, tt + 1);
			}
		}
	cout << maxi;
	system("pause");
	return 0;
}