#define CRT_NO_SECURE_WARNINGS
#define MAX 987654321
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <math.h>
using namespace std;
int arr[21][21];
int row;
int result = MAX;

void cal(int y, int x, int d1, int d2) {
	vector <int> v(5, 0);
	int check[21][21];
	for (int i = 1; i <= row; i++) 
		for (int j = 1; j <= row; j++)
			check[i][j] = 0;
	//1锅 备开
	int cnt = 0;
	for (int i = 1; i <y; i++) {
		for (int j = 1; j <= x+d1; j++) {
			if (i + j == x + y)
				break;
			else {
				cnt += arr[i][j];
				check[i][j] = 1;
				
			}
		}
	}
	v[0] = cnt;
	//2锅 备开
	cnt = 0;
	for (int i = 1; i <= y+d2-d1; i++) {
		for (int j = x+d1+1; j <=row; j++) {
			if (i - j >= y - d1 - (x + d1))
				continue;
			else {
				cnt += arr[i][j];
				check[i][j] = 2;
			}
		}
	}
	v[1] = cnt;
	//3锅 备开
	cnt = 0;
	for (int i = y; i <= row; i++) {
		for (int j = 1; j < x + d2; j++) {
			if (i - j == y-x)
				break;
			else {
				cnt += arr[i][j];
				check[i][j] = 3;
			}
		}
	}
	v[2] = cnt;
	//4锅 备开
	cnt = 0;
	for (int i = y+1-(d1-d2); i <= row; i++) {
		for (int j = x+d2; j <=row; j++) {
			if (i + j <= x + d2 + d2 + y)
				continue;
			else {
				cnt += arr[i][j];
				check[i][j] = 4;
			}
		}
	}
	v[3] = cnt;
	//5锅 备开
	cnt = 0;
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= row; j++) {
			if (check[i][j] != 1&& check[i][j] != 2 &&check[i][j] != 3 &&check[i][j] != 4)
				cnt += arr[i][j];
		}
	}
	v[4] = cnt;
	sort(v.begin(), v.end());
	int temp = v[4] - v[0];
	result = min(result, temp);
}
void set_std(int y, int x) {
	for (int d1 = 1; d1 < y; d1++) {
		for (int d2 = 1; d2 < row - y; d2++) {
			if (x + d1 + d2 <= row) {
				cal(y, x, d1, d2);
			}
		}
	}
}

int main() {
	cin >> row;
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= row; j++)
			cin >> arr[i][j];
	for (int y = 2; y <= row - 1; y++) {
		for (int x = 1; x <= row - 1; x++) {
			set_std(y, x);
		}
	}
	cout << result;
	system("PAUSE");
	return 0;
}