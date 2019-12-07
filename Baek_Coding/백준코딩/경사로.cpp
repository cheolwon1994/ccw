#define CRT_NO_SECURE_WARNINGS
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
int arr[100][100];
int check[100][100];
int row, len, result=0;

void test(int col, int num) {
	if (num == row - 1) {
		result++;
	}
	else {
		if (num != row - 1) {
			int temp = arr[col][num];
			int temp2 = arr[col][num + 1];
			if (temp == temp2 )		//같은 경우
				test(col, num + 1);
			else {
				int nx;
				bool flag = true;
				vector <int> v;
				if (temp == temp2-1) {		//왼쪽이 작은 경우
					for (int i = 0; i < len; i++) {
						nx = num - i;
						if (nx >= 0 && check[col][nx] != 1 && arr[col][nx] == temp) {
							v.push_back(nx);
							continue;
						}
						else {
							flag = false;
							break;
						}
					}
					if (flag) {		//가능한 경우
						for (int i = 0; i < v.size(); i++)
							check[col][v[i]] = 1;
						v.clear();
						test(col, num + 1);
					}
					else {		//불가능한 경우
						v.clear();
						return;
					}
				}
				else if (temp - 1 == temp2) {		//오른쪽이 1 작은 경우
					for (int i = 1; i <= len; i++) {
						nx = num + i;
						if (nx < row && check[col][nx] != 1 && arr[col][nx] == temp2) {
							v.push_back(nx);
							continue;
						}
						else {
							flag = false;
							break;
						}
					}
					if (flag) {		//가능한 경우
						for (int i = 0; i < v.size(); i++)
							check[col][v[i]] = 1;
						v.clear();
						test(col, num + 1);
					}
					else {		//불가능한 경우
						v.clear();
						return;
					}
				}
			}
		}
	}
}
void test2(int r, int num) {
	if (num == row - 1) 
		result++;
	
	else {
		if (num != row - 1) {
			int temp = arr[num][r];
			int temp2 = arr[num+1][r];
			if (temp == temp2)		//같은 경우
				test2(r, num + 1);
			else {
				int ny;
				bool flag = true;
				vector <int> v;
				if (temp == temp2 - 1) {		//위가 작은 경우
					for (int i = 0; i < len; i++) {
						ny = num - i;
						if (ny >= 0 && check[ny][r] != 1 && arr[ny][r] == temp) {
							v.push_back(ny);
							continue;
						}
						else {
							flag = false;
							break;
						}
					}
					if (flag) {		//가능한 경우
						for (int i = 0; i < v.size(); i++)
							check[v[i]][r] = 1;
						v.clear();
						test2(r, num + 1);
					}
					else {		//불가능한 경우
						v.clear();
						return;
					}
				}
				else if (temp - 1 == temp2) {		//밑이 1 작은 경우
					for (int i = 1; i <= len; i++) {
						ny = num + i;
						if (ny < row && check[ny][r] != 1 && arr[ny][r] == temp2) {
							v.push_back(ny);
							continue;
						}
						else {
							flag = false;
							break;
						}
					}
					if (flag) {		//가능한 경우
						for (int i = 0; i < v.size(); i++)
							check[v[i]][r] = 1;
						v.clear();
						test2(r, num + 1);
					}
					else {		//불가능한 경우
						v.clear();
						return;
					}
				}
			}
		}
	}
}
int main() {
	cin >> row >> len;
	result = 0;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < row; j++)
			cin >> arr[i][j];
	int x = row;
	//가로
	for (int i = 0; i < row; i++) 
		test(i, 0);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < row; j++)
			check[i][j] = 0;

	//세로
	for (int i = 0; i < row; i++) 
		test2(i, 0);
	
	cout << result;
	system("pause");
	return 0;
}