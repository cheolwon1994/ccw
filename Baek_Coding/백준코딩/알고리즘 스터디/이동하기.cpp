#include <iostream>
#include <algorithm>
using namespace std;

int row, col;
int arr[1000][1000];
long long sum[1000][1000];
long long tt;
int main() {
	cin >> row >> col;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			cin >> arr[i][j];
	sum[0][0] = arr[0][0];
	for (int i = 1; i < row; i++)
		sum[i][0] = sum[i - 1][0] + arr[i][0];
	for (int j = 1; j < col; j++)
		sum[0][j] = sum[0][j-1] + arr[0][j];
	for (int i = 1; i < row; i++) {
		for (int j = 1; j < col; j++) {
			tt = max(sum[i - 1][j], sum[i][j - 1]);
			sum[i][j] = arr[i][j] + max(tt, sum[i - 1][j - 1]);
		}
	}
	/*cout << endl;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			cout << sum[i][j] << " ";
		cout << endl;
	}
	cout << endl;*/
	cout << sum[row - 1][col - 1];
	system("pause");
	return 0;
}