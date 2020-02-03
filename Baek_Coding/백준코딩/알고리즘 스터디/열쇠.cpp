#include <iostream>
#include <queue>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
using namespace std;
char arr[100][100];
int row, col, result;
bool key[26];
int avail_key;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
struct info {
	int x, y;
};
info tmp;
vector<info> v;

void start() {
	int cx, cy,nx, ny;
	while (1) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (i == 0 || i == row - 1 || j == 0 || j == col - 1) {
					if (arr[i][j] >= 'A' && arr[i][j] <= 'Z') {
						if (key[arr[i][j] - 'A']) {
							tmp.x = j;
							tmp.y = i;
							arr[i][j] = '.';
							v.push_back(tmp);
						}
					}
				}
			}
		}
		int t_avail_key = avail_key;
		bool check[100][100] = { false, };

		for (int i = 0; i < v.size(); i++) {
			queue<info> q;
			tmp.x = v[i].x;
			tmp.y = v[i].y;
			q.push(tmp);
			check[tmp.y][tmp.x] = true;
			if (arr[tmp.y][tmp.x] == '$') {
				arr[tmp.y][tmp.x] = '.';
				result++;
			}
			while (!q.empty()) {
				cx = q.front().x;
				cy = q.front().y;
				q.pop();
				for (int j = 0; j < 4; j++) {
					nx = cx + dx[j];
					ny = cy + dy[j];
					if (nx >= 0 && ny >= 0 && nx < col && ny < row && !check[ny][nx]) {
						if (arr[ny][nx] == '*') continue;
						else if (arr[ny][nx] == '$') {
							result++;
							arr[ny][nx] = '.';
						}
						else if (arr[ny][nx] >= 'A' && arr[ny][nx] <= 'Z') {
							if (key[arr[ny][nx] - 'A']) 
								arr[ny][nx] = '.';							
							else continue;
						}
						else if (arr[ny][nx] >= 'a' && arr[ny][nx] <= 'z') {
							key[arr[ny][nx] - 'a'] = true;
							avail_key++;
							arr[ny][nx] = '.';
						}
						check[ny][nx] = true;
						tmp.x = nx;
						tmp.y = ny;
						q.push(tmp);
					}
				}
			}
		}
		if (t_avail_key == avail_key)		//key가 추가된 경우 다시 탐색
			break;
	}
}

int main() {
	int test;
	string str;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		//초기화
		memset(key, false, sizeof(key));
		v.clear();
		result = 0;
		avail_key = 0;

		cin >> row >> col;
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++) {
				cin >> arr[i][j];
				if (i == 0 || i == row - 1 || j == 0 || j == col - 1) {
					if ((arr[i][j] == '.' || arr[i][j] == '$')) {
						tmp.x = j;
						tmp.y = i;
						v.push_back(tmp);
					}
					else if (arr[i][j] >= 'a' && arr[i][j] <= 'z') {
						key[arr[i][j] - 'a'] = true;
						tmp.x = j;
						tmp.y = i;
						arr[i][j] = '.';
						v.push_back(tmp);
					}
				}
			}
		cin >> str;
		if (str != "0") {
			for (int i = 0; i < str.size(); i++)
				key[str[i] - 'a'] = true;
			avail_key += str.size();
		}
		start();
		cout << result << endl;
	}
	system("pause");
	return 0;
}