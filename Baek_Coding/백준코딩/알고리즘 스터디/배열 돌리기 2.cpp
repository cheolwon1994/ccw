#include <iostream>
using namespace std;
long long arr[300][300];
int row, col, rot, mini;

void rotate(int k, int remain) {
	for (int m = 0; m < remain; m++) {
		int tt = arr[k][k];
		for (int j = k; j < col - 1 - k; j++)
			arr[k][j] = arr[k][j + 1];
		for (int j = k; j < row - 1 - k; j++)
			arr[j][col - 1 - k] = arr[j + 1][col - 1 - k];
		for (int j = col - 1 - k; j > k; j--)
			arr[row - 1 - k][j] = arr[row - 1 - k][j - 1];
		for (int j = row - 1 - k; j > k; j--)
			arr[j][k] = arr[j - 1][k];
		arr[k + 1][k] = tt;
	}
}

int main() {
	cin >> row >> col >> rot;
	mini = row < col ? row : col;
	mini /= 2;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			cin >> arr[i][j];

	for(int k=0;k<mini;k++)
		rotate(k,rot%(2*(row+col-2*k)-4*(k+1)));
	
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
	system("pause");
	return 0;
}