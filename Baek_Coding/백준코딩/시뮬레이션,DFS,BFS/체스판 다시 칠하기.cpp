#define MAX 987654321
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int result = MAX;
char arr[50][50];
int row, col;
int len = 8;
int cnt = 0;

void color(int y, int x, char first, char second) {
	int tmp = 0;
	int same, cal;
	same = (y*len + x) % 2;
	for (int i = y; i < y + len; i++) {
		for (int j = x; j < x + len; j++) {
			if ((i - y) % 2 == 0)
				cal = i * len + j;
			else
				cal = i * len + j + 1;
			if (cal % 2 == same) {		//같은 색이여야 하는경우
				if (arr[i][j] != arr[y][x]) 		//같은 색이 아닌경우
					tmp++;
				
			}
			else {		//다른 색이여야 하는 경우
				if (arr[i][j] == arr[y][x])
					tmp++;
			}
		}
	}
	result = min(result, tmp);
	result = min(result, 64 - tmp);
}

void find(int y, int x) {
	char first = arr[y][x];
	if (first == 'B')
		color(y, x, 'B', 'W');
	else
		color(y, x, 'W', 'B');
}

int main() {
	cin >> row >> col;
	string str;
	for (int i = 0; i < row; i++) {
		cin >> str;
		for (int j = 0; j < col; j++)
			arr[i][j] = str[j];
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (i + len <= row && j + len <= col) {
				find(i, j);
			}
		}
	}
	cout << result;
	system("pause");
	return 0;
}