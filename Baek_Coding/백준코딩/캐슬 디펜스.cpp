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
1.궁수 3명 -> colC3으로 선택해야됨
while(적이 더이상 없을 때){
2. 적 공격
2-1. 거리가 D이하중 가장 가까운 적
2-2. 거리가 같으면, 가장 왼쪽에 있는 적
2-3. 같은 적 공격 가능
3. 공격한 적 수만큼 답에 추가
4. 적 이동
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
			//적이 있는곳을 따로 표시할 경우
			if (arr[i][j] == 1) {
				tmp.x = j;
				tmp.y = i;
				enemy.push_back(tmp);
			}
		}
	}
	//궁수 위치 배치
	vector<int> archer;
	for (int i = 0; i < col - 3; i++)
		archer.push_back(0);
	for (int i = col - 3; i < col; i++)
		archer.push_back(1);
	//궁수 배치
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
		//적이 없어질때까지 실행
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
					//최소 거리의 적이 있을 경우
					if (x_dist + y_dist < mini) {
						mini = x_dist + y_dist;
						enemy_X = dup_enemy[j].x;
						idx = j;
					}
					//같은 최소거리의 적이 있을 경우, 왼쪽
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
			//적 없애는 작업
			for (int i = 0; i < target.size(); i++) {
				dup_enemy.erase(dup_enemy.begin() + (target[i] - i));
				semi_result++;
			}
			if (dup_enemy.empty())
				break;

			//한칸씩 밑으로 이동
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