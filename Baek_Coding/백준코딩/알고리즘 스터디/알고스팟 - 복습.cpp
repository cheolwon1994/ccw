#define MAX 987654321
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;
struct info {
	int x, y, val;
};
struct cmp {
	bool operator()(info &a, info &b) {
		return a.val > b.val;
	}
};
info tmp;
int arr[100][100];
int check[100][100];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int row, col;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str;
	cin >> col >> row;
	for (int i = 0; i < row; i++) {
		cin >> str;
		for (int j = 0; j < col; j++) {
			arr[i][j] = str[j] - '0';
			check[i][j] = MAX;
		}
	}
	priority_queue<info, vector<info>, cmp> pq;
	tmp.x = 0;
	tmp.y = 0;
	tmp.val = 0;
	pq.push(tmp);
	check[0][0] = 0;
	while (!pq.empty()) {
		int cx = pq.top().x;
		int cy = pq.top().y;
		int cv = pq.top().val;
		pq.pop();
		if (cx == col - 1 && cy == row - 1) {
			cout << cv;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && ny >= 0 && nx < col && ny < row) {
				if (arr[ny][nx] == 1 && check[ny][nx] > cv + 1) {
					check[ny][nx] = cv + 1;
					tmp.x = nx;
					tmp.y = ny;
					tmp.val = cv + 1;
					pq.push(tmp);
				}
				else if (arr[ny][nx] == 0 && check[ny][nx] > cv) {
					check[ny][nx] = cv;
					tmp.x = nx;
					tmp.y = ny;
					tmp.val = cv;
					pq.push(tmp);
				}
			}
		}
	}
	return 0;
}