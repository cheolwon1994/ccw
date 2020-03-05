#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
char arr[2000][2000];
bool check[2000][2000];
string ans;
int row, col;
int dx[2] = { 0,1 };
int dy[2] = { 1,0 };
struct info {
	int x, y;
};
info tmp;
void start() {
	queue<info> q;
	queue<info> nq;
	tmp.x = 0;
	tmp.y = 0;
	q.push(tmp);
	while (ans.length() < row + col - 1) {
		char c = 'z' + 1;		
		while (!q.empty()) {
			int cx = q.front().x;
			int cy = q.front().y;
			q.pop();
			for (int i = 0; i < 2; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if (nx < col && ny < row && !check[ny][nx]) {
					check[ny][nx] = true;
					if (arr[ny][nx] < c) {
						c = arr[ny][nx];
						while (!nq.empty()) nq.pop();
						tmp.x = nx;
						tmp.y = ny;
						nq.push(tmp);
					}
					else if (arr[ny][nx] == c) {
						tmp.x = nx;
						tmp.y = ny;
						nq.push(tmp);
					}
				}
			}
		}
		ans += c;
		q = nq;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		cin >> row >> col;
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++) {
				cin >> arr[i][j];
				check[i][j] = false;
			}
		ans = "";
		ans += arr[0][0];
		check[0][0] = true;
		start();
		cout << "#" << t << " " << ans<<'\n';
	}
	system("pause");
	return 0;
}