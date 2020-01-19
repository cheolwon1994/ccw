#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;
int arr[5][8];		//앞의 1~4를 사용
int dup[5][8];

void move(int idx, int right) {
	int cnt = 1;
	if (right == -1)		//왼쪽으로 회전시키는 경우
		cnt = 7;
	int tt;
	for (int i = 0; i < cnt; i++) {
		tt = dup[idx][7];
		for (int j = 7; j > 0; j--)
			dup[idx][j] = dup[idx][j - 1];
		dup[idx][0] = tt;
	}
}

void start(int loc, int dir) {
	memcpy(dup, arr, sizeof(arr));
	//해당 기어 회전
	move(loc, dir);
	//왼쪽 비교
	int tt = 0;
	while (1) {
		if (loc - (tt+1) <= 0)		//왼쪽 회전시킬게 없는 경우
			break;
		//같은 극이므로 끝
		if (arr[loc - tt][6] == arr[loc - (tt + 1)][2])
			break;
		if (tt % 2 == 0)		//반대방향
			move(loc - (tt + 1), -dir);
		else
			move(loc - (tt + 1), dir);
		tt++;
	}
	tt = 0;
	//오른쪽 비교
	while (1) {
		if (loc + (tt + 1) > 4)
			break;
		if (arr[loc + tt][2] == arr[loc + (tt + 1)][6])
			break;
		if (tt % 2 == 0)		//반대방향
			move(loc + (tt + 1), -dir);
		else
			move(loc + (tt + 1), dir);
		tt++;
	}
	memcpy(arr, dup, sizeof(arr));
}

int main() {
	int test, ins, loc, dir;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		cin >> ins;
		for (int i = 1; i <= 4; i++)
			for (int j = 0; j < 8; j++)
				cin >> arr[i][j];
		for (int i = 0; i < ins; i++) {
			cin >> loc >> dir;
			start(loc, dir);
		}
		int result = 0;
		for (int i = 1; i < 5; i++) {
			if (arr[i][0] == 1)
				result += pow(2, i - 1);
		}
		cout << "#" << t << " " << result << endl;
	}
	return 0;
}