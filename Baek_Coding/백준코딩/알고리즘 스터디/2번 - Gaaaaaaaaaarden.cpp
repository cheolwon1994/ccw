#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int arr[50][50];
int dup[50][50];		//������ �ɾ��� ��: 10, �ʷϻ� �ɾ��� ��: 20, ��: 100
int row, col, red, green, result = 0;
struct info {
	int x, y;
};
info tmp;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
vector<info> can_plant, r, g;
vector<int> v;			//� �κп� ������ ���� ������

void bfs() {
	int t_result = 0;
	vector<info> flower;
	queue<info> rr, gg;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			dup[i][j] = arr[i][j];
		
	for (int i = 0; i < r.size(); i++) {
		tmp.x = r[i].x;
		tmp.y = r[i].y;
		rr.push(tmp);
		dup[tmp.y][tmp.x] = 0;
	}
	for (int i = 0; i < g.size(); i++) {
		tmp.x = g[i].x;
		tmp.y = g[i].y;
		gg.push(tmp);
		dup[tmp.y][tmp.x] = 0;
	}
	while (1) {
		queue<info> nr, ng;
		//������ ��Ʈ����
		int len = rr.size();
		for (int i = 0; i < len; i++) {
			int cx = rr.front().x;
			int cy = rr.front().y;
			rr.pop();
			if (dup[cy][cx] == 100) continue;		//���� �Ǿ �ڸ���
			dup[cy][cx] = 0;		//�ʰ� �� �ʷ��̶� ���� ���� �ʵ��� �ϱ� ���� ������ ������ �ʱ�ȭ
			for (int k = 0; k < 4; k++) {
				int nx = cx + dx[k];
				int ny = cy + dy[k];
				if (nx >= 0 && ny >= 0 && nx < col && ny < row && dup[ny][nx] == 1) {
					tmp.x = nx;
					tmp.y = ny;
					nr.push(tmp);
					dup[ny][nx] = 10;
				}
			}
		}
		//�ʷϻ� ��Ʈ����
		len = gg.size();
		for (int i = 0; i < len; i++) {
			int cx = gg.front().x;
			int cy = gg.front().y;
			gg.pop();
			for (int k = 0; k < 4; k++) {
				int nx = cx + dx[k];
				int ny = cy + dy[k];
				if (nx >= 0 && ny >= 0 && nx < col && ny < row) {
					if (dup[ny][nx] == 1) {			//���� �湮���� ���� ��
						tmp.x = nx;
						tmp.y = ny;
						dup[ny][nx] = 0;		//���̻� ������ ������ �ٲ۴�
						ng.push(tmp);
					}
					else if (dup[ny][nx] == 10) {		//�� ����
						dup[ny][nx] = 100;
						t_result++;					
					}					
				}
			}
		}
		rr = nr;
		gg = ng;
		if (gg.empty() && rr.empty()) break;
	}
	result = max(result, t_result);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> row >> col >> green >> red;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				tmp.x = j;
				tmp.y = i;
				can_plant.push_back(tmp);
				arr[i][j] = 1;
			}
		}
	vector<int> t;
	for (int i = 0; i < can_plant.size() - red - green; i++)
		t.push_back(0);
	for (int i = 0; i < red + green; i++)
		t.push_back(1);
	do {
		v.clear();
		for (int i = 0; i < can_plant.size(); i++)
			if (t[i] == 1)
				v.push_back(i);
		vector<int> tt;
		for (int i = 0; i < red; i++)	tt.push_back(0);
		for (int i = 0; i < green; i++)	tt.push_back(1);
		do {
			r.clear();
			g.clear();
			for (int i = 0; i < tt.size(); i++) {
				if (tt[i] == 0) {			//������ ���� �����Ұ�
					tmp.x = can_plant[v[i]].x;
					tmp.y = can_plant[v[i]].y;
					r.push_back(tmp);
				}
				else {						//�ʷϻ� ���� �����Ұ�
					tmp.x = can_plant[v[i]].x;
					tmp.y = can_plant[v[i]].y;
					g.push_back(tmp);
				}
			}
			bfs();
		} while (next_permutation(tt.begin(), tt.end()));
	} while (next_permutation(t.begin(), t.end()));
	cout << result;
	system("pause");
	return 0;
}