#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int row, col, limit;
char arr[200][200];
int dup[200][200];

struct info {
	int x, y;
};
info tmp;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

int main() {
	cin >> row >> col >> limit;
	int cnt = 0;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) {
			cin >> arr[i][j];
			if(arr[i][j]=='O')
				dup[i][j] = cnt + 3;
		}
	vector<info> v;
	while (cnt<limit) {
		cnt++;
		if (cnt % 2 == 0) {
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++)
					if (arr[i][j] == '.') {
						arr[i][j] = 'O';
						dup[i][j] = cnt + 3;
					}
			}
		}
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (cnt == dup[i][j]) {
					tmp.x = j;
					tmp.y = i;
					v.push_back(tmp);
				}
			}
		}
		
		for (int i = 0; i < v.size(); i++) {
			int cx = v[i].x;
			int cy = v[i].y;
			for (int j = 0; j < 4; j++) {
				int nx = cx + dx[j];
				int ny = cy + dy[j];
				if (nx >= 0 && ny >= 0 && nx < col && ny < row) 
					if (arr[ny][nx] == 'O') 
						arr[ny][nx] = '.';				
			}
			arr[cy][cx] = '.';
		}
		v.clear();
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			cout << arr[i][j];
		cout << endl;
	}

	system("pause");
	return 0;
}