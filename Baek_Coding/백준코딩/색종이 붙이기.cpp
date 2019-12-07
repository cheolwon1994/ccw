#define _CRT_NO_SECURE_WARNINGS

#include <iostream>
#include <algorithm>

using namespace std;

int paper[6] = { 0,5,5,5,5,5 };		//������ ���� ���ʴ�� 0,1*1,2*2,3*3,4*4,5*5
int arr[100];		//�Է¹޴� �迭
int result = 101;

//check�� �ٲ��ִ� �Լ�
void change(int a, int num, int col) {
	int x = a % 10;
	int y = a / 10;
	for (int i = y; i < y + num; i++) 
		for (int j = x; j < x + num; j++) 
			arr[i*10 + j] = col;	
}
bool test(int a, int num) {
	int x = a % 10;
	int y = a / 10;
	if (x + num > 10 || y + num > 10)
		return false;
	bool flag = true;
	for (int i = y; i < y+num; i++) {
		for (int j = x; j < x+num; j++) {
			if (arr[i*10 +j] == 1)
				continue;
			else {
				flag = false;
				break;
			}
		}
		if (!flag)
			break;
	}
	return flag;
}

void bfs(int num) {
	if (num == 100) {
		int semi_result = 0;
		for (int i = 1; i < 6; i++)
			semi_result += 5 - paper[i];
		result = min(semi_result, result);
		return;
	}
	if (arr[num] == 1) {
		int a = 0;
		for (int k = 1; k < 6; k++) {
			if (paper[k] <= 0)
				continue;
			if (test(num, k)) {
				a = 1;
				change(num, k, 0);
				paper[k] -= 1;
				bfs(num + k);
				change(num, k, 1);
				paper[k] += 1;
			}
		}
		if (a == 0)
			return;
	}
	else
		bfs(num + 1);
	
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < 100; i++)
			cin >> arr[i];
	bfs(0);
	if (result == 101)
		cout << -1;
	else
		cout << result;

	system("PAUSE");
	return 0;
}