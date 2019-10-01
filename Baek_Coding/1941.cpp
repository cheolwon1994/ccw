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
char arr[5][5];
int check[25];
int result = 0;

//ĥ���� ���
struct p7 {
	int x;
	int y;
	char type;
};
struct info {
	int x;
	int y;
};
deque <p7> dq;
queue <info> d;
p7 tmp;
info temp;

//���� ���� ����Ȯ�� ���� ���
int x[4] = { 0,1,0,-1 };
int y[4] = { -1,0,1,0 };

/*
���� �� �ܰ�
1. �� 7�� �̱�
2. 1�� ������, 7���� �̴ټ��� 4���̻� �ִ��� Ȯ��
3. 2�� ������ ���� �������ִ��� Ȯ��
*/
void checkSide() {
	int side_Check[7];
	memset(side_Check, 0, sizeof(side_Check));
	temp.x = dq[0].x;
	temp.y = dq[0].y;
	d.push(temp);
	side_Check[0] = 1;
	while (!d.empty()) {
		int cur_x = d.front().x;
		int cur_y = d.front().y;
		d.pop();
		for (int i = 1; i < 7; i++) {
			if (side_Check[i] != 1) {
				int next_x, next_y;
				for (int j = 0; j < 4; j++) {
					next_x = cur_x + x[j];
					next_y = cur_y + y[j];
					if (next_x < 0 || next_y < 0 || next_x == 5 || next_y == 5)
						continue;
					if (dq[i].x == next_x && dq[i].y == next_y) {
						temp.x = next_x;
						temp.y = next_y;
						d.push(temp);
						side_Check[i] = 1;
					}
				}
			}
		}
	}
	bool flag = true;
	for(int i=0;i<7;i++)
		if (side_Check[i] != 1) {
			flag = false;
			break;
		}
	if (flag)
		result++;
	return;
}

//a�� b�� ������ ���� ����
void dfs(int a) {
	//2�� ����
	if (dq.size() == 7) {
		int sum = 0;
		for (int i = 0; i < dq.size(); i++) 
			if (dq[i].type == 'S')
				sum++;
		if (sum >= 4)
			checkSide();
		return;
	}
	//1�� ����
	for(int i=a;i<25;i++){
		if (check[i] != 1) {
			tmp.x = i%5;
			tmp.y = i/5;
			tmp.type = arr[i / 5][i % 5];
			check[i] = 1;
			dq.push_back(tmp);
			dfs(i);
			check[i] = 0;
			dq.pop_back();
		}		
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	for (int i = 0; i < 5; i++) {
		cin >> s;
		for (int j = 0; j < 5; j++) 
			arr[i][j] = s[j];		
	}
	dfs(0);
	cout << result;
	return 0;
}