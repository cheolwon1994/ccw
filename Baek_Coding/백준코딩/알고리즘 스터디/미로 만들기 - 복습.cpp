#define MAX 987654321
#include <iostream>
#include <string>
#include <queue>
using namespace std;
struct info {
	int x, y, val;
};
info tmp;
int num, arr[50][50];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int check[50][50];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> str;
		for (int j = 0; j < num; j++) {
			arr[i][j] = str[j] - '0';
			check[i][j] = MAX;
		}
	}
	queue<info> q;
	int result = MAX;
	tmp.x = 0;
	tmp.y = 0;
	tmp.val = 0;
	q.push(tmp);
	check[0][0] = 0;
	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		int cv = q.front().val;
		q.pop();
		if (cy == num - 1 && cx == num - 1) {
			result = min(result, cv);
			continue;
		}
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && ny >= 0 && nx < num && ny<num) {
				bool avail = false;
				if (arr[ny][nx] == 0 && check[ny][nx] > cv + 1) {
					check[ny][nx] = cv + 1;
					tmp.val = cv + 1;
					avail = true;
				}
				else if(arr[ny][nx]==1 && check[ny][nx] > cv){
					check[ny][nx] = cv;
					tmp.val = cv;
					avail = true;
				}
				if (avail) {
					tmp.x = nx;
					tmp.y = ny;
					q.push(tmp);
				}
			}
		}
	}
	cout << result;
	return 0;
}