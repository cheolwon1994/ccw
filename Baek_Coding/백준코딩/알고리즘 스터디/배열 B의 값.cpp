#define MAX -9876543210
#include <iostream>
#include <algorithm>
using namespace std;
int row, col;
int arr[1000][1000];
long long result, ans = MAX;

void change_line() {		//0 ¶Ç´Â row-1°ú¸¸ ¹Ù²Û´Ù
	long long t_result;
	for (int i = 1; i < row - 1; i++) {
		//row 0°ú ¹Ù²Û´Ù
		t_result = result;
		t_result += (arr[0][0] - arr[i][0] + arr[0][col-1] - arr[i][col-1]);
		for (int j = 1; j < col - 1; j++) 
			t_result += 2 * (arr[0][j] - arr[i][j]);
		ans = max(ans, t_result);

		//row row-1°ú ¹Ù²Û´Ù
		t_result = result;
		t_result += (arr[row-1][0] - arr[i][0] + arr[row-1][col - 1] - arr[i][col - 1]);
		for (int j = 1; j < col - 1; j++)
			t_result += 2 * (arr[row-1][j] - arr[i][j]);
		ans = max(ans, t_result);
	}

	for (int i = 1; i < col - 1; i++) {
		//col 0°ú ¹Ù²Û´Ù
		t_result = result;
		t_result += (arr[0][0] - arr[0][i] + arr[row-1][0] - arr[row-1][i]);
		for (int j = 1; j < row - 1; j++)
			t_result += 2 * (arr[j][0] - arr[j][i]);
		ans = max(ans, t_result);

		//col col-1°ú ¹Ù²Û´Ù
		t_result = result;
		t_result += (arr[0][col-1] - arr[0][i] + arr[row - 1][col-1] - arr[row - 1][i]);
		for (int j = 1; j < row - 1; j++)
			t_result += 2 * (arr[j][col-1] - arr[j][i]);
		ans = max(ans, t_result);
	}
}

int main() {
	cin >> row >> col;
	result = 0;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) {
			cin >> arr[i][j];
			if (i == 0 || j == 0 || i == row - 1 || j == col - 1)
				result += arr[i][j];
			else
				result += (4 * arr[i][j]);	
		}
	for (int i = 1; i < col - 1; i++)
		result += (arr[0][i]+arr[row-1][i]);
	for (int i = 1; i < row - 1; i++)
		result += (arr[i][0] + arr[i][col - 1]);
	ans = max(ans, result);
	change_line();

	cout << ans;
	system("pause");
	return 0;
}