#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct info {
	int x, y;
	char c;
};
info tmp;
int num;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
char arr[100][100][2];
bool check[100][100];

void bfs(int a) {
	int cnt = 0;
	queue<info> q;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			if (!check[i][j]) {
				cnt++;
				tmp.x = j;
				tmp.y = i;
				tmp.c = arr[i][j][a];
				q.push(tmp);
				check[i][j] = true;
				while (!q.empty()) {
					int cx = q.front().x;
					int cy = q.front().y;
					char cc = q.front().c;
					q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = cx + dx[k];
						int ny = cy + dy[k];
						if (nx >= 0 && ny >= 0 && nx < num && ny < num && !check[ny][nx] && arr[ny][nx][a] == cc) {
							check[ny][nx] = true;
							tmp.x = nx;
							tmp.y = ny;
							tmp.c = cc;
							q.push(tmp);
						}
					}
				}
			}
		}
	}
	cout << cnt << " ";
}

int main() {
	string str;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> str;
		for (int j = 0; j < num; j++) {
			arr[i][j][0] = str[j];
			arr[i][j][1] = str[j];
			if (str[j] == 'G')
				arr[i][j][1] = 'R';
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < num; j++)
			for (int k = 0; k < num; k++)
				check[j][k] = false;
		bfs(i);
	}
	return 0;
}