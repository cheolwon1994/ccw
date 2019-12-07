#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
char arr[20][20];
int check[20][20];
int row, col;
int result = 1;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int alpha[26];
struct info {
	int x;
	int y;
};
info tmp;
vector<info> v;

void find() {
	int cx, cy, nx, ny;
	cx = v[v.size() - 1].x;
	cy = v[v.size() - 1].y;
	for (int i = 0; i < 4; i++) {
		nx = cx + dx[i];
		ny = cy + dy[i];
		if (nx >= 0 && ny >= 0 && nx < col && ny < row && check[ny][nx] != 1) {
			if (alpha[arr[ny][nx] - 'A'] != 1) {
				tmp.x = nx;
				tmp.y = ny;
				v.push_back(tmp);
				alpha[arr[ny][nx] - 'A'] = 1;
				check[ny][nx] = 1;
				find();
				check[ny][nx] = 0;
				alpha[arr[ny][nx] - 'A'] = 0;
				v.pop_back();
			}
		}
	}
	int vs = v.size();
	result = max(result, vs);
	return;
}

int main() {
	string str;
	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		cin >> str;
		for (int j = 0; j < col; j++)
			arr[i][j] = str[j];
	}
	alpha[arr[0][0] - 'A'] = 1;
	check[0][0] = 1;
	tmp.x = 0;
	tmp.y = 0;
	v.push_back(tmp);
	find();
	cout << result;
	system("pause");
	return 0;
}