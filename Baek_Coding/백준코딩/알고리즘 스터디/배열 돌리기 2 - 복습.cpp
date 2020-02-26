#include <iostream>
using namespace std;
int row, col, rot;
int arr[300][300];

void mv(int m, int amount) {		//외곽에서 몇번째 껍질인지, 몇번 회전시키는지
	int L = m;
	int R = col - 1 - m;
	int D = row - 1 - m;
	int U = m;
	for (int k = 0; k < amount; k++) {
		int val = arr[m][m];
		for (int i = L; i < R; i++)
			arr[m][i] = arr[m][i + 1];
		for (int i = U; i < D; i++)
			arr[i][R] = arr[i + 1][R];
		for (int i = R; i > L; i--)
			arr[D][i] = arr[D][i - 1];
		for (int i = D; i > U; i--)
			arr[i][m] = arr[i - 1][m];
		arr[m + 1][m] = val;

		/*cout << endl;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++)
				cout << arr[i][j] << " ";
			cout << endl;
		}*/
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> row >> col >> rot;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			cin >> arr[i][j];
	int mini = (row < col ? row : col) / 2;
	for (int i = 0; i < mini; i++) 
		mv(i, rot%(2 * (row + col) - 8 * i - 4));
	
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			cout << arr[i][j] << " ";
		cout << '\n';
	}
	system("pause");
	return 0;
}