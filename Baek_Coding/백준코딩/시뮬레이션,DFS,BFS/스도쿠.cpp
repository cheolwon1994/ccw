#include <iostream>
#include <algorithm>
using namespace std;
bool row[9][10];		//앞: 몇번째 줄 , 뒤: 해당 번호
bool col[9][10];		
int arr[9][9];
bool sudoku[9][10];
int tx, ty;

void start(int num) {
	if (num == 81) {
		cout << endl;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)
				cout << arr[i][j] << " ";
			cout << endl;
		}
		system("pause");
		exit(0);
	}
	int  cx, cy;
	cy = num / 9;
	cx = num % 9;
	if (arr[cy][cx] == 0) {
		for (int k = 1; k < 10; k++) {
			if (row[cy][k]==false && col[cx][k]==false && sudoku[(cy / 3) * 3 + (cx / 3)][k]==false) {
				row[cy][k] = true;
				col[cx][k] = true;
				sudoku[(cy / 3) * 3 + cx / 3][k] = true;
				arr[cy][cx] = k;
				start(num + 1);
				arr[cy][cx] = 0;
				row[cy][k] = false;
				col[cx][k] = false;
				sudoku[(cy / 3) * 3 + (cx / 3)][k] = false;
			}
		}
	}
	else
		start(num + 1);
}

int main() {
	for (int i = 0; i < 9; i++) {
		ty = i % 3;
		for (int j = 0; j < 9; j++) {
			cin >> arr[i][j];
			if (arr[i][j] != 0) {
				tx = j % 3;
				sudoku[(i / 3) * 3 + (j / 3)][arr[i][j]] = true;
				row[i][arr[i][j]] = true;
				col[j][arr[i][j]] = true;
			}
		}
	}
	start(0);
	system("pause");
	return 0;
}