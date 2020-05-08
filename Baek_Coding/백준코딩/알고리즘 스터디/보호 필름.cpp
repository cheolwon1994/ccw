#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
int arr[13][20], dup[13][20];
vector<int> changeRow, color;
int test, row, col, limit, result;
bool finish;

bool change() {
	bool avail = true;
	memcpy(dup, arr, sizeof(arr));
	int d = 0;
	for (int i = 0; i < changeRow.size(); i++) 
		if (changeRow[i] == 1) {
			for (int j = 0; j < col; j++)
				dup[i][j] = color[d];
			d++;
		}				
			
	for (int j = 0; j < col; j++) {
		int cnt = 1;
		if (cnt >= limit)
			return true;
		int val = dup[0][j];
		for (int i = 1; i < row; i++) {
			if (dup[i][j] != val) {
				val = dup[i][j];
				cnt = 1;
			}
			else if (dup[i][j] == val) {
				cnt++;
				if (cnt >= limit)
					break;
			}
		}
		if (cnt < limit) 
			return false;		
	}
	return avail;
}

void dfs(int maxi, int idx) {
	if (idx == maxi) {
		if (change()) {
			result = maxi;
			finish = true;
		}
		return;
	}
	for (int i = 0; i < 2; i++) {
		color.push_back(i);
		dfs(maxi, idx + 1);
		color.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> test;
	for (int t = 1; t <= test; t++) {
		cin >> row >> col >> limit;
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				cin >> arr[i][j];
		result = 0;
		finish = false;
		for (int i = 0; i < row; i++) {
			changeRow.clear();
			for (int j = 0; j < row - i; j++)
				changeRow.push_back(0);
			for (int j = 0; j < i; j++)
				changeRow.push_back(1);
			do {
				color.clear();
				dfs(i,0);
				if (finish) break;
			} while (next_permutation(changeRow.begin(), changeRow.end()));
			if (finish) break;
		}
		cout << "#" << t << " " << result << '\n';
	}
	system("pause");
	return 0;
}