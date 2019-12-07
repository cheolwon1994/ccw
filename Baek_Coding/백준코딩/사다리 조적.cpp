#define CRT_NO_SECURE_WARNINGS
#define MAX 987654321
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int arr[31][11];
int n, m, h;
int answer = MAX;
int cnt = 0;
bool flag = false;
/*
void dfs(int y, int take) {
	if (flag)
		return;

	if (take == cnt) {
		bool avail = true;
		for (int i = 1; i <= n; i++) {
			int test = i;
			for (int j = 1; j <= h; j++) {				
				//오른쪽
				if (arr[j][test])
					test++;
				//왼쪽
				else if (test > 1 && arr[j][test - 1] == 1)
					test--;
			}
			if (test != i) {
				avail = false;
				break;
			}
		}
		if (avail)
			flag = true;
		return;
	}

	for (int i = y; i <= h; i++) {
		for (int j = 2; j <= n; j++) {
			if (arr[i][j - 1] != 1 && arr[i][j] != 1 && arr[i][j + 1] != 1) {
				arr[i][j] = 1;
				dfs(i, take + 1);
				arr[i][j] = 0;
			}
		}
	}
	return;
}
*/
void dfs(int y, int t) {
	if (flag)
		return;
	//검사
	if (t == cnt) {
		/*for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= n; j++)
				cout << arr[i][j];
			cout << endl;
		}
		cout << endl;
		*/
		bool test;
		for (int i = 1; i <= n; i++) {
			test = true;
			int row;
			row = i;
			for (int j = 1; j <= h; j++) {
				//오른쪽
				if (arr[j][row] == 1) 
					row++;				
				//왼쪽
				else if (row != 1 && arr[j][row - 1] == 1)
					row--;
			}
			if (row != i) {
				test = false;
				break;
			}

		}
		if (test) {
			flag = true;
			return;
		}
	}
	if (t < cnt) {
		for (int i = y; i <= h; i++) {
			for (int j = 1; j <= n; j++) {
				if (arr[i][j] != 1 && arr[i][j - 1] != 1 && arr[i][j + 1] != 1) {
					arr[i][j] = 1;
					dfs(i, t + 1);
					arr[i][j] = 0;
				}
			}
		}
	}

}

int main() {
	cin >> n >> m >> h;
	int line, loc;
	for (int i = 0; i < m; i++) {
		cin >> loc >> line;
		arr[loc][line]=1;
	}	
	for (int i = 0; i <= 3; i++) {
		cnt = i;
		dfs(1, 0);
		if (flag) {
			cout << cnt;
			system("PAUSE");
			return 0;
		}
	}
	if (!flag)
		cout << -1;
	system("PAUSE");
	return 0;
}