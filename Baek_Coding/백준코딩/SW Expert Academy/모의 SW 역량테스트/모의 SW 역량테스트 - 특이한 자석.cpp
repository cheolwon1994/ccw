#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;
int arr[5][8];		//���� 1~4�� ���
int dup[5][8];

void move(int idx, int right) {
	int cnt = 1;
	if (right == -1)		//�������� ȸ����Ű�� ���
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
	//�ش� ��� ȸ��
	move(loc, dir);
	//���� ��
	int tt = 0;
	while (1) {
		if (loc - (tt+1) <= 0)		//���� ȸ����ų�� ���� ���
			break;
		//���� ���̹Ƿ� ��
		if (arr[loc - tt][6] == arr[loc - (tt + 1)][2])
			break;
		if (tt % 2 == 0)		//�ݴ����
			move(loc - (tt + 1), -dir);
		else
			move(loc - (tt + 1), dir);
		tt++;
	}
	tt = 0;
	//������ ��
	while (1) {
		if (loc + (tt + 1) > 4)
			break;
		if (arr[loc + tt][2] == arr[loc + (tt + 1)][6])
			break;
		if (tt % 2 == 0)		//�ݴ����
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