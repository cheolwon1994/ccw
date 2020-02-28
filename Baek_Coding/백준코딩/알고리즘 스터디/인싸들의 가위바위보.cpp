#include <iostream>
using namespace std;
int idx[4] = { 0,0,0,0 };		//1~3번 선수
bool flag[10] = { false, };
int num, need_win, limit;
int arr[10][10];
int order[4][20];
int win[4] = { 0,0,0,0 };
bool finish = false;
void start(int player1, int player2, int cnt) {
	if (finish) return;
	if (win[1] == need_win) {
		finish = true;
		return;
	}
	if (win[2] == need_win || win[3]==need_win) return;		//다른 선수가 이긴경우
	if (cnt == limit) return;
	//이번턴에 무엇을 낼 차례인지
	int p2 = order[player2][idx[player2]];
	int p1 = player1;
	if (p1 == 1) {
		//이길수 있는 경우가 존재할 때
		for (int i = 1; i <= num; i++) {
			if (flag[i]) continue;
			if (arr[i][p2] == 2) {	
				flag[i] = true;
				if (player2 == 2) {
					idx[2]++;
					win[1]++;
					start(p1, 3, cnt + 1);
					idx[2]--;
					win[1]--;
				}
				else if (player2 == 3) {
					idx[3]++;
					win[1]++;
					start(p1, 2, cnt + 1);
					idx[3]--;
					win[1]--;
				}
				flag[i] = false;
			}
		}
		//무엇을 내도 질 때
		for (int i=1; i <=num; i++) {
			if (flag[i]) continue;
			flag[i] = true;
			if (player2 == 2) {
				idx[2]++;
				win[2]++;
				start(2, 3, cnt + 1);
				idx[2]--;
				win[2]--;
			}
			else if (player2 == 3) {
				idx[3]++;
				win[3]++;
				start(2, 3, cnt + 1);
				idx[3]--;
				win[3]--;
			}
			flag[i] = false;
		}
	}
	else if (p1 != 1) {			//지우가 경기하지 않는 경우
		p1 = order[player1][idx[player1]];
		if (arr[p1][p2] == 2 ) {		//p1이 이긴 경우
			idx[2]++;
			idx[3]++;
			win[player1]++;
			start(1, 2, cnt + 1);
			win[player1]--;
			idx[2]--;
			idx[3]--;
		}
		else if (arr[p1][p2] == 0 || arr[p1][p2] == 1) {		//p2가 이긴 경우
			idx[2]++;
			idx[3]++;
			win[player2]++;
			start(1, 3, cnt + 1);
			win[player2]--;
			idx[2]--;
			idx[3]--;
		}
	}
}

int main() {
	cin >> num >> need_win;
	for (int i = 1; i <= num; i++)
		for (int j = 1; j <= num; j++)
			cin >> arr[i][j];
	for (int i = 2; i < 4; i++)
		for (int j = 0; j < 20; j++)
			cin >> order[i][j];
	limit = 3 * (need_win - 1) + 1;
	start(1, 2, 0);
	if (finish) cout << 1;
	else cout << 0;
	system("pause");
	return 0;
}