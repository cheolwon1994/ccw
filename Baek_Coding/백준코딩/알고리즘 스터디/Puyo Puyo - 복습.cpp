#include <iostream>
#include <queue>
#include <string>
#include <string.h>
#include <vector>
using namespace std;
int row = 12, col = 6, result = 0;
char arr[12][6];
bool finish;
bool check[12][6];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
struct info {
	int y, x;
};
info tmp;

void getDown() {
	for (int i = 0; i < 6; i++) {
		string str = "";
		for (int j = 11; j >= 0; j--) {
			if (arr[j][i] != '.') str += arr[j][i];
		}
		for (int j = 11; j > 11 - str.size(); j--)
			arr[j][i] = str[11-j];
		for (int j = 11 - str.size(); j >= 0; j--)
			arr[j][i] = '.';
	}
}

void puyo() {
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 6; j++)
			check[i][j] = false;

	for(int i=11;i>=0;i--)
		for (int j = 0; j < 6; j++) {
			if (arr[i][j] != '.' && !check[i][j]) {
				queue<info> q;
				vector<info> v;
				tmp.x = j;
				tmp.y = i;
				q.push(tmp);
				v.push_back(tmp);
				check[i][j] = true;
				while (!q.empty()) {
					int cx = q.front().x;
					int cy = q.front().y;
					q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = cx + dx[k];
						int ny = cy + dy[k];
						if (nx >= 0 && ny >= 0 && nx < 6 && ny < 12 && !check[ny][nx] && arr[ny][nx]==arr[i][j]) {
							check[ny][nx] = true;
							tmp.x = nx;
							tmp.y = ny;
							q.push(tmp);
							v.push_back(tmp);
						}
					}
				}
				if (v.size() > 3) {
					for (int k = 0; k < v.size(); k++)
						arr[v[k].y][v[k].x] = '.';
					finish = false;
				}
			}
		}
}

int main() {
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 6; j++)
			cin >> arr[i][j];
	while (1) {
		finish = true;
		puyo();
		if (finish) break;
		result++;
		getDown();
	}
	cout << result;
	system("pause");
	return 0;
}