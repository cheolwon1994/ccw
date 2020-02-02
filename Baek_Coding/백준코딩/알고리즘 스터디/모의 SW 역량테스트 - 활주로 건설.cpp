#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;
int num, len, result;
int arr[20][20];
bool check[20];
int main() {
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		result = 0;
		cin >> num >> len;
		for (int i = 0; i < num; i++)
			for (int j = 0; j < num; j++)
				cin >> arr[i][j];
		int tt;
		for (int i = 0; i < num; i++) {
			bool line_avail = true;
			memset(check, false, sizeof(check));
			for (int j = 0; j < num-1; j++) {
				if (check[j] && arr[i][j] == arr[i][j + 1]) continue;
				if (arr[i][j] == arr[i][j + 1] + 1) {
					if (j + len < num) {
						tt = arr[i][j + 1];
						if (check[j + 1]) {
							line_avail = false;
							break;
						}
						for (int k = j + 2; k <= j + len; k++) {
							if (tt != arr[i][k] && !check[k]) {
								line_avail = false;
								break;
							}
						}
						if (line_avail) {
							for (int k = j + 1; k <= j + len; k++)
								check[k] = true;
						}											
					}
					else {
						line_avail = false;
						break;
					}
				}
				else if (arr[i][j] + 1 == arr[i][j + 1]) {		//오른쪽이 큰경우
					if (j - (len - 1) >= 0) {
						tt = arr[i][j];
						for (int k = j - 1; k >= j - (len - 1); k--) {
							if (tt != arr[i][k] ||check[k]) {
								line_avail = false;
								break;
							}
						}
						if (line_avail) {
							for (int k = j; k >= j - (len - 1); k--)
								check[k] = true;							
						}
					}
					else {
						line_avail = false;
						break;
					}
				}
				else if (abs(arr[i][j]-arr[i][j + 1])>1) {
					line_avail = false;
					break;
				}
			}
			if (line_avail) {
				for (int k = 0; k < num - 1; k++) {
					if (arr[i][k] == arr[i][k + 1]) continue;
					else if (arr[i][k] + 1 == arr[i][k + 1]) {
						if (!check[k]) {
							line_avail = false;
							break;
						}
					}
					else if (arr[i][k] == arr[i][k + 1] + 1) {
						if (!check[k + 1]) {
							line_avail = false;
							break;
						}
					}
				}
				if (line_avail) 
					result++;				
			}
		}

		for (int j = 0; j < num; j++) {
			bool line_avail = true;
			memset(check, false, sizeof(check));
			for (int i = 0; i < num-1; i++) {
				if (check[i] && arr[i][j]==arr[i+1][j]) continue;
				if (arr[i][j] == arr[i + 1][j] + 1) {	//위에가 더 큰경우
					if (i + len < num) {
						tt = arr[i + 1][j];
						if (check[i+1]) {
							line_avail = false;
							break;
						}
						for (int k = i + 2; k <= i + len; k++) {
							if (tt != arr[k][j] ||check[k]) {
								line_avail = false;
								break;
							}
						}
						if (line_avail) {
							for (int k = i + 1; k <= i + len; k++)
								check[k] = true;							
						}
					}
					else {
						line_avail = false;
						break;
					}
				}
				else if (arr[i][j] + 1 == arr[i + 1][j]) {		//밑이 큰경우
					if (i - (len - 1) >= 0) {
						tt = arr[i][j];
						for (int k = i - 1; k >= i - (len - 1); k--) {
							if (tt != arr[k][j] || check[k]) {
								line_avail = false;
								break;
							}
						}
						if (line_avail) {
							for (int k = i; k >= i - (len - 1); k--)
								check[k] = true;						
						}
					}
					else {
						line_avail = false;
						break;
					}
				}
				else if (abs(arr[i][j]-arr[i + 1][j])>1) {
					line_avail = false;
					break;
				}
			}
			if (line_avail) {
				for (int k = 0; k < num - 1; k++) {
					if (arr[k][j] == arr[k+1][j]) continue;
					else if (arr[k][j] +1 == arr[k + 1][j]) {
						if (!check[k]) {
							line_avail = false;
							break;
						}
					}
					else if (arr[k][j] == arr[k + 1][j]+1) {
						if (!check[k + 1]) {
							line_avail = false;
							break;
						}
					}
				}
				if (line_avail) 
					result++;				
			}
		}
		cout << "#" << t << " " << result << endl;
	}
	system("pause");
	return 0;
}