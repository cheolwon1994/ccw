#define _CRT_NO_SECURE_WARNINGS
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <deque>
#include <queue>
#include <string>
#include <string.h>
#include <math.h>

using namespace std;
int arr[20];
int oper[20];		//* : 42, +: 43, -: 45
long long maximum = -9876543210;
int op_idx = 0;
int n_idx = 0;
//(num+1)/4 : 최대 괄호 개수

int cal(int n1, int n2, int op) {
	if (op == 42)
		return n1 * n2;
	else if (op == 43)
		return n1 + n2;
	else if (op == 45)
		return n1 - n2;
}

void dfs(int idx, long long sum) {
	if (idx == op_idx) {
		maximum = max(maximum, sum);
		return;
	}
	//순차적으로 가는 경우
	int tmp = cal(sum,arr[idx+1],oper[idx]);
	dfs(idx + 1, tmp);

	//뒤쪽에 괄호는 넣는 경우
	if (idx + 1 != op_idx) {
		int jump = cal(arr[idx + 1], arr[idx + 2], oper[idx + 1]);
		jump = cal(sum, jump, oper[idx]);
		dfs(idx + 2, jump);
	}
}

int main() {
	int num;

	string str;
	cin >> num;
	cin >> str;
	for (int i = 0; i <str.size(); i++) {
		if (i % 2 == 0)
			arr[n_idx++] = str[i]-'0';
		else
			oper[op_idx++] = str[i];
	}
	dfs(0, arr[0]);
	cout << maximum;
	system("PAUSE");	
	return 0;
}