#define CRT_NO_SECURE_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
/*******************************
해당 행에 퀸이 놓여져 있으면 다음 행으로 넘어간다
해당 열에 퀸이 놓여져 있으면 다음 열(열+2)로 넘어간다
해당 대각선에 퀸이 놓여져 있으면 다음 열로 넘어간다.

*******************************/
int row;
int check[10];
int result = 0;

bool avail(int n, int num) {
	bool f = true;
	for (int i = 0; i < n; i++) {
		if (check[i] == num || i + check[i] == n + num || check[i] - i == num - n) {
			f = false;
			break;
		}
	}
	return f;
}

void n_queen(int n) {
	if (n == row)
		result+=1;
	else {
		for (int i = 0; i < row; i++) {
			if (avail(n, i)) {
				check[n] = i;
				n_queen(n + 1);
			}
		}
	}
}

int main() {
	int test;
	cin >> test;
	for (int k = 1; k <= test; k++) {
		cin >> row;
		result = 0;
		memset(check, -1, sizeof(check));
		
		n_queen(0);
		cout << "#" << k << " " << result<<endl;
	}
	return 0;
}