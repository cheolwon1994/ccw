#define CRT_NO_SECURE_WARNINGS
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
using namespace std;
int arr[51][51];
int temp_arr[51][51];
long long result;

int x[4] = { 0,1,0,-1 };
int y[4] = { -1,0,1,0 };

struct info {
	int x;
	int y;
};
info tmp;
vector<info> air_cleaner;

int row, col, time_left;

void spread() {
	int nx, ny, sum, t;
	int cnt[4];
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			if (arr[i][j] == 0)
				continue;
			if (arr[i][j] == -1)
				temp_arr[i][j] = -1;
			else {
				memset(cnt, 0, sizeof(cnt));
				sum = 0;
				t = arr[i][j] / 5;
				for (int k = 0; k < 4; k++) {
					nx = j + x[k];
					ny = i + y[k];
					if (nx >= 1 && ny >= 1 && nx <= col && ny <= row) {
						if (arr[ny][nx] != -1) {
							cnt[k] = 1;
							sum++;
						}
					}
				}
				for (int k = 0; k < 4; k++) {
					if (cnt[k] == 1)
						temp_arr[i + y[k]][j + x[k]] += t;
				}

				temp_arr[i][j] += (arr[i][j] - sum * t);
			}
		}
	}
}

void clean_up() {
	int a = air_cleaner[0].y;
	for (int i = a - 1; i > 1; i--)
		temp_arr[i][1] = temp_arr[i - 1][1];
	for (int i = 1; i < col; i++)
		temp_arr[1][i] = temp_arr[1][i + 1];
	for (int i = 1; i < a; i++)
		temp_arr[i][col] = temp_arr[i+1][col];
	for (int i = col; i > 1; i--) {
		if (i == 2)
			temp_arr[a][i] = 0;
		else
			temp_arr[a][i] = temp_arr[a][i - 1];
	}
}

void clean_down() {
	int a = air_cleaner[1].y;
	for (int i = a + 1; i < row; i++)
		temp_arr[i][1] = temp_arr[i + 1][1];
	for (int i = 0; i < col; i++)
		temp_arr[row][i] = temp_arr[row][i + 1];
	for (int i = row; i > a; i--)
		temp_arr[i][col] = temp_arr[i - 1][col];
	for (int i = col; i > 1; i--) {
		if (i == 2)
			temp_arr[a][i] = 0;
		else
			temp_arr[a][i] = temp_arr[a][i - 1];
	}
}

void dup() {
	memset(arr, 0, sizeof(arr));

	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++)
			arr[i][j] = temp_arr[i][j];
	memset(temp_arr, 0, sizeof(temp_arr));
}

int main() {
	cin >> row >> col >> time_left;
	memset(arr, 0, sizeof(arr));
	memset(temp_arr, 0, sizeof(temp_arr));
	air_cleaner.clear();
	result = 0;
	for (int i = 1; i <= row; i++) 
		for (int j = 1; j <= col; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == -1) {
				tmp.y = i; 
				tmp.x = j;
				air_cleaner.push_back(tmp);
			}
		}
	int cnt = 0;
	while (time_left>0) {
		spread();
		clean_up();
		clean_down();
		dup();
		time_left--;
	}
	for (int i = 1; i <= row; i++) 
		for (int j = 1; j <= col; j++) 
			if (arr[i][j] != -1 && arr[i][j]!=0)
				result += arr[i][j];
		
	cout << result;
	system("PAUSE");
	return 0;
}