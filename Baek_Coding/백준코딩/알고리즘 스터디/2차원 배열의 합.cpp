#include <iostream>
#include <algorithm>
using namespace std;
int arr[301][301];

int main() {
	int row, col, num, x, y, xx, yy;
	long long sum;
	cin >> row >> col;
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++)
			cin >> arr[i][j];
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> y >> x >> yy >> xx;
		sum = 0;
		for (int j = y; j <= yy; j++)
			for (int k = x; k <= xx; k++)
				sum += arr[j][k];
		cout << sum << endl;
	}
	system("pause");
	return 0;
}