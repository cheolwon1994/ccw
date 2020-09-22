#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;
struct info {
	int x, y;
};
info tmp;
char arr[100][100];
bool check[100][100];
int row, col, result;
vector<info> start;
bool alpha[26];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };


void bfs() {
	int cnt = 1;
	while (1) {
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				check[i][j] = false;
		bool change = false;		//맵의 변화 여부
		queue<info> q;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (i == 0 || i == row - 1 || j == col - 1 || j == 0) {
					char c = arr[i][j];
					if ('A' <= c && c <= 'Z' && alpha[c - 'A']) {
						arr[i][j] = '.';
						tmp.x = j;
						tmp.y = i;
						q.push(tmp);
						check[i][j] = true;
					}
					else if (c == '.') {
						tmp.x = j;
						tmp.y = i;
						q.push(tmp);
						check[i][j] = true;
					}
				}
			}
		}
		while (!q.empty()) {
			int cx = q.front().x;
			int cy = q.front().y;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if (nx >= 0 && ny >= 0 && nx < col && ny < row && !check[ny][nx]) {
					char c = arr[ny][nx];
					check[ny][nx] = true;
					if (c == '.') {

					}
					else if (c == '*') continue;
					else if (c == '$') {		//문서
						arr[ny][nx] = '.';
						result++;
					}
					else if ('a' <= c && c <= 'z') {		//열쇠
						arr[ny][nx] = '.';
						change = true;
						alpha[c - 'a'] = true;
					}
					else {		//문
						if (alpha[c - 'A']) {
							arr[ny][nx] = '.';
							change = true;
						}
						else continue;
					}
					tmp.x = nx;
					tmp.y = ny;
					q.push(tmp);
				}
			}
		}
		if (!change) break;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int test;
	cin >> test;
	for (int t = 0; t < test; t++) {
		cin >> row >> col;
		//초기화
		start.clear();
		result = 0;
		for (int i = 0; i < 26; i++)
			alpha[i] = false;

		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++) {
				cin >> arr[i][j];
				if (i == 0 || i == row - 1 || j == col - 1 || j == 0) {
					if (arr[i][j] == '.' || arr[i][j] == '$') {
						tmp.x = j;
						tmp.y = i;
						start.push_back(tmp);
						if (arr[i][j] == '$') {
							arr[i][j] = '.';
							result++;
						}
					}
				}
			}
		string str;
		cin >> str;
		if (str != "0") {
			for (int i = 0; i < str.size(); i++) {
				char c = str[i];
				alpha[c - 'a'] = true;
			}
		}
		bfs();
		cout << result << '\n';
	}
	return 0;
}