#define _CRT_NO_SECURE_WARNINGS
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>

using namespace std;

int gear[5][8];
int result[5];		//gear[0]의 값비교, 0-> 0 // 1-> 1,2,4,8점

/*톱니바퀴 번호
701
6 2
543
*/

/*
1. 톱니바퀴 정보 입력받음
2. 지목된 톱니바퀴 기준으로 양옆 비교 -> 끝까지 감
2-1. 만약 같은 극 -> 그쪽방향으로 더 이상 회전x
2-2. 다른 극 -> 중앙 회전시킨 뒤, 방향은 반대로 해서 그쪽 방향으로 쭉 진행
3. 전부 완료하면 출력
*/

void rotate(vector <int> &check, int mid, int dir) {
	bool l = false;		//왼
	bool r = false;		//오
	if (mid == 2 || mid == 3) {
		//왼쪽
		if (check[mid - 1] != 1) {
			if (gear[mid][6] != gear[mid - 1][2])
				l = true;
			check[mid - 1] = 1;
		}
		//오른쪽
		if (check[mid + 1] != 1) {
			if (gear[mid][2] != gear[mid + 1][6])
				r = true;
			check[mid + 1] = 1;
		}
	}
	else if (mid == 1) {
		if (check[mid + 1] != 1) {
			if (gear[mid][2] != gear[mid + 1][6]) {
				r = true;
			}
			check[mid + 1] = 1;
		}
	}
	else if (mid == 4) {
		if (check[mid - 1] != 1) {
			if (gear[mid][6] != gear[mid - 1][2])
				l = true;
			check[mid - 1] = 1;
		}
	}
	//mid 회전
	if (dir == 1) {
		int tmp = gear[mid][7];
		for (int i = 7; i > 0; i--)
			gear[mid][i] = gear[mid][i - 1];
		gear[mid][0] = tmp;
	}
	else if (dir == -1) {
		int tmp = gear[mid][0];
		for (int i = 0; i < 7; i++)
			gear[mid][i] = gear[mid][i + 1];
		gear[mid][7] = tmp;
	}
	if (l)
		rotate(check, mid - 1, -dir);
	if (r)
		rotate(check, mid + 1, -dir);
}

int main() {
	string str;
	int num;
	int gear_num;
	int dir;
	int sum = 0;
	for (int i = 1; i <= 4; i++) {
		cin >> str;
		for (int j = 0; j < 8; j++)
			gear[i][j] = str[j] - 48;
	}
	cin >> num;
	//dir=1 : 시계방향, dir=-1 : 반시계방향
	for (int i = 0; i < num; i++) {
		cin >> gear_num >> dir;
		vector <int> check(5);
		check[0] = 1;
		check[gear_num] = 1;
		rotate(check, gear_num, dir);
	}
	//결과 계산
	for (int i = 1; i < 5; i++)
		if (gear[i][0] == 1)
			sum += pow(2, i - 1);
	cout << sum;

	system("PAUSE");
	return 0;
}
