#define _CRT_NO_SECURE_WARNINGS

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <string.h>
#include <string>
using namespace std;


/************************************
1.�ü� 3�� -> colC3���� �����ؾߵ�
while(���� ���̻� ���� ��){
2. �� ����
2-1. �Ÿ��� D������ ���� ����� ��
2-2. �Ÿ��� ������, ���� ���ʿ� �ִ� ��
2-3. ���� �� ���� ����
3. ������ �� ����ŭ �信 �߰�
4. �� �̵�
}
************************************/

int result = 0;

struct info {
	int x;
	int y;
};
info tmp;
vector<info> enemy;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int row, col, dist;
	cin >> row >> col >> dist;
	vector<vector <int>> arr(row, vector<int>(col, 0));
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> arr[i][j];
			//���� �ִ°��� ���� ǥ���� ���
			if (arr[i][j] == 1) {
				tmp.x = j;
				tmp.y = i;
				enemy.push_back(tmp);
			}
		}
	}
	//�ü� ��ġ ��ġ
	vector<int> archer;
	for (int i = 0; i < col - 3; i++)
		archer.push_back(0);
	for (int i = col - 3; i < col; i++)
		archer.push_back(1);
	//�ü� ��ġ
	do {
		vector<info> dup_enemy;
		dup_enemy = enemy;

		vector<info> arc;
		for (int i = 0; i < col; i++)
			if (archer[i] == 1) {
				tmp.x = i;
				tmp.y = row;
				arc.push_back(tmp);
			}

		int semi_result = 0;
		//���� ������������ ����
		while (!dup_enemy.empty()) {
			vector<int> target;
			for (int i = 0; i < 3; i++) {
				int x_dist, y_dist;
				int idx = 0;
				int enemy_X = dup_enemy[0].x;
				int mini = abs(arc[i].x -dup_enemy[0].x) + abs(arc[i].y -dup_enemy[0].y);
				for (int j = 1; j < dup_enemy.size(); j++) {
					x_dist = abs(arc[i].x - dup_enemy[j].x);
					y_dist = abs(arc[i].y - dup_enemy[j].y);
					//�ּ� �Ÿ��� ���� ���� ���
					if (x_dist + y_dist < mini) {
						mini = x_dist + y_dist;
						enemy_X = dup_enemy[j].x;
						idx = j;
					}
					//���� �ּҰŸ��� ���� ���� ���, ����
					else if (x_dist + y_dist == mini) {
						if (enemy_X > dup_enemy[j].x) {
							enemy_X = dup_enemy[j].x;
							idx = j;
						}
					}
				}
				if (mini <= dist) 
					target.push_back(idx);
			}
			target.erase(unique(target.begin(), target.end()), target.end());
			sort(target.begin(), target.end());
			//�� ���ִ� �۾�
			for (int i = 0; i < target.size(); i++) {
				dup_enemy.erase(dup_enemy.begin() + (target[i] - i));
				semi_result++;
			}
			if (dup_enemy.empty())
				break;

			//��ĭ�� ������ �̵�
			vector<info> dup2_enemy;
			for (int i = 0; i < dup_enemy.size(); i++) {
				if (dup_enemy[i].y + 1 != row) {
					tmp.y = dup_enemy[i].y + 1;
					tmp.x = dup_enemy[i].x;
					dup2_enemy.push_back(tmp);
				}
			}
			dup_enemy = dup2_enemy;
		}
		result = max(semi_result, result);
	} while (next_permutation(archer.begin(), archer.end()));

	cout << result;
	system("PAUSE");
	return 0;
}