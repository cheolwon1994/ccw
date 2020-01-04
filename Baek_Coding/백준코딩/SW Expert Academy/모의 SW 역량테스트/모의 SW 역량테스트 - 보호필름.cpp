#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
int arr[13][20];
int d_arr[13][20];
int row, col, limit, result;
bool finish;
vector<int> change;

void start(int ch) {
	memcpy(d_arr, arr, sizeof(d_arr));
	for (int i = 0; i < row; i++) {
		if (change[i] == 1) {
			for (int j = 0; j < col; j++)
				d_arr[i][j] = ch;
		}
	}
	bool non_avail = false;
	for (int j = 0; j < col; j++) {
		bool flag = false;
		int contin = 1;	//몇번 연속됐는지
		if (contin >= limit) {
			flag = true;
			break;
		}
		int dup = d_arr[0][j];		//연속되는 숫자
		for (int i = 1; i < row; i++) {
			if (d_arr[i][j] == dup) {
				contin++;
				if (contin >= limit) {
					flag = true;
					break;
				}
			}
			else {
				contin = 1;
				dup = d_arr[i][j];
			}
		}
		if (!flag) {
			non_avail = true;
			break;
		}
	}
	if (!non_avail) 		//모두 통과한 경우
		finish = true;
}

int main() {
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		//초기화
		result = 0;
		finish = false;

		cin >> row >> col >> limit;
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				cin >> arr[i][j];

		for (int i = 0; i < row; i++) {
			change.clear();		//교체할 행
			for (int j = 0; j < row - i; j++)
				change.push_back(0);
			for (int j = row - i; j < row; j++)
				change.push_back(1);
			do {
				start(0);
				if (finish) {
					result = i;
					break;
				}
				start(1);
				if (finish) {
					result = i;
					break;
				}
			} while (next_permutation(change.begin(), change.end()));
			if (finish)
				break;
		}
		cout << "#" << t << " " << result << endl;
	}
	system("pause");
	return 0;
}