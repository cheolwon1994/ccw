#include <iostream>
#include <algorithm>
using namespace std;
int price[4], use[13], result;

void dfs(int idx, int sum) {		//���� ��, ���� ���
	if (idx > 11) {
		result = min(result, sum);
		return;
	}
	if (use[idx] == 0)		//�ش� �޿� ������ ���� �ʴ� ���
		dfs(idx + 1, sum);
	else {
		int mini = min(price[1], use[idx] * price[0]);
		dfs(idx + 1, sum + mini);
		dfs(idx + 3, sum + price[2]);
	}
}

int main() {
	int test, cnt;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		result = 0;
		cnt = 0;
		for (int i = 0; i < 4; i++)
			cin >> price[i];
		for (int i = 0; i < 12; i++) {
			cin >> use[i];
			result += use[i] * price[0];		//�Ϸ�ġ
			if (use[i] > 0)		//1��ġ
				cnt += price[1];
		}
		result = min(result, cnt);				//1��ġ�� �Ϸ�ġ ��
		result = min(result, price[3]);			//1��ġ

		dfs(0, 0);
		cout << "#" << t << " " << result << '\n';
	}
	return 0;
}