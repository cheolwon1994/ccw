#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
int row, col, con, result;
int arr[13][20], dup[13][20];
int order[13];
vector<int> vv;
bool finish;

bool cal(int k) {
	memcpy(dup, arr, sizeof(arr));
	for (int i = 0; i < row; i++) {		//변환
		if (order[i] == 1) {
			for (int j = 0; j < col; j++)
				dup[i][j] = 0;
		}
		else if (order[i] == 2) {
			for (int j = 0; j < col; j++)
				dup[i][j] = 1;
		}
	}
	//검사
	bool avail = true;
	for (int j = 0; j < col; j++) {
		int val = dup[0][j];
		bool t_avail = false;
		vector<int> v;
		int cnt = 1;
		for (int i = 1; i <= row; i++) {
			if (i == row) {
				v.push_back(cnt);
				break;
			}
			if (val == dup[i][j]) 		//같은 색
				cnt++;			
			else {
				v.push_back(cnt);
				cnt = 1;
				val = dup[i][j];
			}
		}
		for (int i = 0; i < v.size(); i++) {
			if (v[i] >= con) {
				t_avail = true;
				break;
			}
		}
		if (!t_avail) 
			return false;		
	}
	return true;
}

void dfs(int idx, int k) {
	if (finish) return;
	if (idx == row) {
		if (cal(k)) {
			result = k;
			finish = true;
		}
		return;
	}
	if (vv[idx] == 0) {
		order[idx] = 0;
		dfs(idx + 1, k);
	}
	else {
		order[idx] = 1;
		dfs(idx + 1, k);
		order[idx] = 2;
		dfs(idx + 1, k);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		cin >> row >> col >> con;
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				cin >> arr[i][j];
		if (con == 1) {
			cout << "#" << t << " " << 0 << '\n';
			continue;
		}
		//초기화
		result = row;
		finish = false;

		for (int k = 0; k < row; k++) {			//바꿀 횟수
			vv.clear();
			for (int i = 0; i < row - k; i++)
				vv.push_back(0);
			for (int i = 0; i < k; i++)
				vv.push_back(1);
			do {
				for (int i = 0; i < row; i++)
					order[i] = 0;
				dfs(0, k);
				if (finish)		break;
			} while (next_permutation(vv.begin(), vv.end()));
			if (finish) break;
		}
		cout << "#" << t << " " << result << '\n';
	}
	return 0;
}