#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int inning;
int arr[50][9];		//각 이닝마다 1~9 선수의 결과
vector<int> order;
bool check[10] = { false, };
int result = 0;

void start() {
	int idx = 0;
	int score = 0;
	deque<int> dq;		//출루한사람
	for (int t = 0; t < inning; t++) {
		//초기화
		int out = 0, hitter;
		dq.clear();
		
		while (out < 3) {
			hitter = order[idx] - 1;
			if (arr[t][hitter] > 0) {		//안타 이상 친 경우
				for (int k = 0; k < dq.size(); k++)
					dq[k] += arr[t][hitter];
				dq.push_back(arr[t][hitter]);
				while (!dq.empty()) {
					if (dq[0] >= 4) {
						dq.pop_front();
						score++;
					}
					else
						break;
				}
			}
			else if (arr[t][hitter] == 0)
				out++;
			idx = (idx + 1) % 9;
		}
	}
	result = max(result, score);
}

void dfs(int cnt) {
	if (cnt == 9) {
		if (order[3] == 1) 
			start();		
		return;
	}
	if (cnt == 3) {
		order.push_back(1);
		dfs(cnt + 1);
		order.pop_back();
	}
	for (int i = 1; i < 10; i++) {
		if (!check[i]) {
			check[i] = true;
			order.push_back(i);
			dfs(cnt + 1);
			check[i] = false;
			order.pop_back();
		}
	}
}

int main() {
	cin >> inning;
	for (int i = 0; i < inning; i++)
		for (int j = 0; j < 9; j++)
			cin >> arr[i][j];
	check[1] = true;
	dfs(0);
	cout << result;
	system("pause");
	return 0;
}