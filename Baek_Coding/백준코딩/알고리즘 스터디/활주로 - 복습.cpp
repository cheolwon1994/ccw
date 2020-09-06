#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int num, result, len, val;
int arr[20][20], dup[20];
bool check[20], avail;

void init(int idx, int flag) {
	for (int i = 0; i < num; i++) {
		check[i] = false;
		if (flag == 0)	dup[i] = arr[idx][i];
		else dup[i] = arr[i][idx];
	}
}

bool cal() {
	for (int i = 1; i < num; i++) {
		if (abs(dup[i] - val) > 1) 	//높이차가 1보다 큰 경우
			return false;		
		else if (dup[i] == val) continue;//높이가 같은 경우
		else if (dup[i] > val) {		//오른쪽 높이가 1 더 큰 경우
			if (i < len) 		//왼쪽에 경사 만들 공간이 없는 경우
				return false;
			for (int j = i - 1; j > i - 1 - len; j--) 
				if (check[j] || dup[j]!=val) 
					return false;
			for (int j = i - 1; j > i - 1 - len; j--)		//경사로 설정
				check[j] = true;
			val = dup[i];		//현 높이 변경
		}
		else if (dup[i] < val) {		//왼쪽 높이가 1 더 큰 경우
			if (i + len > num) 		//오른쪽에 경사 만들 공간이 없는 경우
				return false;
			for (int j = i; j < i + len; j++)
				if (check[j] || dup[j] != dup[i])
					return false;
			for (int j = i; j < i + len; j++)		//경사로 설정
				check[j] = true;
			val = dup[i];
			i += len - 1;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		cin >> num >> len;
		for (int i = 0; i < num; i++)
			for (int j = 0; j < num; j++)
				cin >> arr[i][j];
		//초기화
		result = 0;
		for (int i = 0; i < num; i++) {
			//가로
			init(i, 0);
			val = dup[0];
			avail = true;
			if (cal()) 
				result++;
			//세로
			init(i, 1);
			val = dup[0];
			avail = true;
			if (cal()) 
				result++;
		}
		cout << "#" << t << " " << result << '\n';
	}
	return 0;
}