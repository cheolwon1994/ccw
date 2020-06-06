#define MAX 987654321
#include <iostream>
#include <algorithm>
using namespace std;

int arr[20][20],dup[20][20];
int num, result = MAX, tot = 0;
int pop[6];

void start(int y, int x, int d1, int d2) {
	for (int i = 1; i < 6; i++)
		pop[i] = 0;
	int maxi = 0, mini = MAX;
	for (int i = 0; i < num; i++)
		for (int j = 0; j < num; j++)
			dup[i][j] = 5;
	
	//1备开
	for (int i = 0; i < y; i++) {
		for (int j = 0; j <= x+d1; j++) {
			if (x + y == i + j) break;
			else {
				dup[i][j] = 1;
				pop[1] += arr[i][j];
			}
		}
	}
	//2备开
	for (int i = 0; i <= y+d2-d1; i++) {
		for (int j = x+d1+1; j < num; j++) {
			if (i - j >= y - x - 2 * d1) continue;
			else {
				dup[i][j] = 2;
				pop[2] += arr[i][j];
			}
		}
	}
	//3备开	
	for (int i = y; i <num; i++) {
		for (int j = 0; j < x+d2; j++) {
			if (i - j == y - x) break;
			else {
				dup[i][j] = 3;
				pop[3] += arr[i][j];
			}
		}
	}

	//4备开
	for (int i = y + d2-d1+1; i <num; i++) {
		for (int j = x+d2; j < num; j++) {
			if (i + j <= x + y + 2 * d2) continue;
			else {
				dup[i][j] = 4;
				pop[4] += arr[i][j];
			}
		}
	}
	pop[5] = tot - (pop[1] + pop[2] + pop[3] + pop[4]);
	for (int i = 1; i < 6; i++) {
		maxi = max(maxi, pop[i]);
		mini = min(mini, pop[i]);
	}	
	result = min(result, maxi - mini);
}

void dfs(int y, int x) {
	for (int i = 1; i < num; i++) {				//d1
		for (int j = 1; j < num; j++) {			//d2
			if (y - i >= 0 && y + j < num && x + i + j < num)
				start(y, x, i, j);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> num;
	for (int i = 0; i < num; i++)
		for (int j = 0; j < num; j++) {
			cin >> arr[i][j];
			tot += arr[i][j];
		}

	for(int i=1;i<num-1;i++)
		for (int j = 0; j < num - 2; j++) {
			dfs(i, j);
		}
	cout << result;
	return 0;
}