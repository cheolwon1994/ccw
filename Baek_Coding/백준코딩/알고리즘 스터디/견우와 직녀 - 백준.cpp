#define MAX 987654321
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
struct info {
	int x, y, state, val, made;
};
info tmp;
int arr[10][10], num, bridge, result;
int check[10][10][2];		//0: �ֱⰡ M�� ���۱� ���� �ȸ���, 1: ����
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

int main() {
	cin >> num >> bridge;
	for (int i = 0; i < num; i++)
		for (int j = 0; j < num; j++) {
			cin >> arr[i][j];
			check[i][j][0] = MAX;
			check[i][j][1] = MAX;
		}
	for (int i = 0; i < num; i++)
		for (int j = 0; j < num; j++) {
			if (arr[i][j] == 0) {
				int r = 0;
				int c = 0;
				for (int k = 0; k < 4; k += 2) {
					int nx = j + dx[k];
					int ny = i + dy[k];
					if (nx >= 0 && ny >= 0 && nx < num && ny < num && arr[ny][nx] != 1)
						r++;
				}
				for (int k = 1; k < 4; k += 2) {
					int nx = j + dx[k];
					int ny = i + dy[k];
					if (nx >= 0 && ny >= 0 && nx < num && ny < num && arr[ny][nx] != 1)
						c++;
				}
				if (c > 0 && r > 0) arr[i][j] = -1;
			}
		}
	result = MAX;
	queue<info> q;
	tmp.x = 0;
	tmp.y = 0;
	tmp.state = 0;
	tmp.val = 0;
	tmp.made = 0;
	q.push(tmp);
	check[0][0][0] = 0;
	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		int cv = q.front().val;
		int cs = q.front().state;
		int cm = q.front().made;
		q.pop();
		if (cx == num - 1 && cy == num - 1) {
			result = min(result, cv);
			continue;
		}
		for (int k = 0; k < 4; k++) {
			int nx = cx + dx[k];
			int ny = cy + dy[k];
			if (nx >= 0 && ny >= 0 && nx < num && ny < num) {
				if (arr[ny][nx] == 1 && check[ny][nx][cm] > cv + 1) {
					check[ny][nx][cm] = cv + 1;
					tmp.x = nx;
					tmp.y = ny;
					tmp.val = cv + 1;
					tmp.state = 0;
					tmp.made = cm;
					q.push(tmp);
				}
				else if (arr[ny][nx] == -1) continue;	//�������� ���
				else if (arr[ny][nx] == 0) {
					if (cm == 1 || cs==1) continue;		//�̹� ���۱��� �ϳ� ���� ���
					int v = 0;
					if((cv + 1) % bridge != 0)
						v = bridge - (cv + 1) % bridge;
					if (check[ny][nx][1] > cv + v + 1) {
						check[ny][nx][1] = cv + v + 1;
						tmp.x = nx;
						tmp.y = ny;
						tmp.state = 1;
						tmp.val = cv + v + 1;
						tmp.made = 1;
						q.push(tmp);
					}
				}
				else if (arr[ny][nx] > 1) {
					//��� ���۱��� �ǳ԰ų�, ���� ���۱��� ���� ���� ���
					if (cs == 1) 	continue;					
					int v = 0;
					if ((cv + 1) % arr[ny][nx] != 0)
						v = arr[ny][nx] - (cv + 1) % arr[ny][nx];
					if (check[ny][nx][1] > cv + v + 1) {
						check[ny][nx][1] = cv + v + 1;
						tmp.x = nx;
						tmp.y = ny;
						tmp.state = 1;
						tmp.val = cv + v + 1;
						tmp.made = cm;
						q.push(tmp);
					}
				}
			}
		}
	}
	cout << result << '\n';
	system("pause");
	return 0;
}