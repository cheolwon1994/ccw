#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
struct info {
	int x, y;
};
info tmp;
int arr[1000][1000];
int row, col;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

int main() {
	cin >> row >> col;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) 
			cin >> arr[i][j];
		
	int cnt = 2;
	vector<int> v;		//2부터 사용
	v.push_back(0);
	v.push_back(0);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (arr[i][j] == 1) {
				int tt = 1;
				queue<info> q;
				tmp.x = j;
				tmp.y = i;
				q.push(tmp);
				arr[i][j] = cnt;
				while (!q.empty()) {
					int cx = q.front().x;
					int cy = q.front().y;
					q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = cx + dx[k];
						int ny = cy + dy[k];
						if (nx >= 0 && ny >= 0 && nx < col && ny < row && arr[ny][nx]==1) {
							tmp.x = nx;
							tmp.y = ny;
							q.push(tmp);
							arr[ny][nx] = cnt;
							tt++;
						}
					}
				}
				cnt++;
				v.push_back(tt);
			}
		}
	}
	int maxi = -1;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (arr[i][j] == 0) {
				int t_result = 0;
				vector<int> t;
				for (int k = 0; k < 4; k++) {
					int nx = j + dx[k];
					int ny = i + dy[k];
					if (nx >= 0 && ny >= 0 && nx < col && ny < row && arr[ny][nx] !=0) {
						if (t.empty())		t.push_back(arr[ny][nx]);
						else {
							bool avail = true;
							for (int m = 0; m < t.size(); m++) {
								if (arr[ny][nx] == t[m]) {
									avail = false;
									break;
								}
							}
							if (avail)	t.push_back(arr[ny][nx]);
						}
					}
				}
				for (int k = 0; k < t.size(); k++)
					t_result += v[t[k]];
				maxi = max(maxi, t_result + 1);
			}
		}
	}
	cout << maxi;
	system("pause");
	return 0;
}