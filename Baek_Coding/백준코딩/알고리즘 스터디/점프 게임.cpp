#include <iostream>
#include <queue>
#include <string>
using namespace std;
struct info {
	int idx, ladder;		//���� ���° ĭ����(0~num-1), � ������(0~1)
};
info tmp;
bool check[2][100000] = { false, };

int main() {
	string str[2];
	int num, jmp;
	cin >> num >> jmp;
	cin >> str[0] >> str[1];
	queue<info> q;
	tmp.idx = 0;
	tmp.ladder = 0;
	q.push(tmp);
	check[0][0] = true;
	int result = 0;
	int banned = -1;		//����� ���� �� ����
	while (!q.empty()) {
		int len = q.size();
		for (int k = 0; k < len; k++) {
			int cidx = q.front().idx;
			int cl = q.front().ladder;
			q.pop();
			int limit = banned + 1;
			if (cidx - 1 > limit && !check[cl][cidx-1] && str[cl][cidx-1]=='1') {		//������ ������ ���
				check[cl][cidx - 1] = true;
				tmp.idx = cidx - 1;
				tmp.ladder = cl;
				q.push(tmp);
			}
			if (cidx + 1 > limit && !check[cl][cidx + 1] && str[cl][cidx + 1] == '1') {
				check[cl][cidx + 1] = true;
				tmp.idx = cidx + 1;
				tmp.ladder = cl;
				q.push(tmp);
			}
			if (cidx + jmp >= num) {
				result = 1;
				break;
			}
			if (cidx + jmp < num && !check[1 - cl][cidx + jmp] && str[1 - cl][cidx + jmp] == '1') {
				check[1 - cl][cidx + jmp] = true;
				tmp.idx = cidx + jmp;
				tmp.ladder = 1 - cl;
				q.push(tmp);

			}
		}
		banned += 1;
		if (result) break;
	}
	cout << result;
	system("pause");
	return 0;
}