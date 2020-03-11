#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> can_solve[11];		//index�� �л��� Ǯ �� �ִ� ����
vector<int> team;
int problem, people, val, num, result = 11;

void dfs(int cnt, int idx) {		//������ ��� ��, ���� ���
	if (cnt >= result) return;		//���� ����� ������ ���� ���� ����� �ʿ��� ��� return
	if (cnt > 0) {
		bool solved[11] = { false, };		
		for (int i = 0; i < cnt; i++) {
			int cidx = team[i];
			//���� ������ Ǯ �� �ִ� ���� �˻�
			for (int j = 0; j < can_solve[cidx].size(); j++)
				solved[can_solve[cidx][j]] = true;
		}
		bool avail = true;
		for (int i = 1; i <= problem; i++) {
			if (!solved[i]) {
				avail = false;
				break;
			}
		}
		//��� ������ Ǯ �� �ִٸ� �ּ� ���� ����
		if (avail)
			result = min(result, cnt);		
	}
	if (idx > people) return;
	for (int i = idx; i <= people; i++) {
		team.push_back(i);
		dfs(cnt + 1, i + 1);
		team.pop_back();
	}
}

int main() {
	cin >> problem >> people;
	for (int i = 1; i <= people; i++) {
		cin >> val;
		for (int j = 0; j < val; j++) {
			cin >> num;
			can_solve[i].push_back(num);
		}
	}
	dfs(0, 1);
	if (result == 11) result = -1;
	cout << result;
	system("pause");
	return 0;
}