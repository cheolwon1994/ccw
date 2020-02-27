#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <set>
using namespace std;
struct info {
	int x, y;
};
info tmp;
vector<int> v;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int check[1000][1000];
int arr[1000][1000];
int row, col;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string str;
	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		cin >> str;
		for (int j = 0; j < col; j++)
			arr[i][j] = str[j] - '0';
	}
	int cnt = 1;
	v.push_back(0);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (arr[i][j] == 0 && check[i][j] == 0) {
				int val = 1;
				queue<info> q;
				tmp.x = j;
				tmp.y = i;
				q.push(tmp);
				check[i][j] = cnt;
				while (!q.empty()) {
					int cx = q.front().x;
					int cy = q.front().y;
					q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = cx + dx[k];
						int ny = cy + dy[k];
						if (nx >= 0 && ny >= 0 && nx < col && ny < row && arr[ny][nx] == 0 && check[ny][nx] == 0) {
							check[ny][nx] = cnt;
							tmp.x = nx;
							tmp.y = ny;
							q.push(tmp);
							val++;
						}
					}
				}
				v.push_back(val%10);
				cnt++;
			}
		}
	}
	set<int> s;
	set<int> ::iterator it;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (arr[i][j] == 1) {			
				s.clear();
				for (int k = 0; k < 4; k++) {
					int nx = j + dx[k];
					int ny = i + dy[k];
					if (nx >= 0 && ny >= 0 && nx < col && ny < row)
						s.insert(check[ny][nx]);
				}
				int val = 1;
				for (it = s.begin(); it != s.end(); it++)
					val += v[*it];
				cout << val%10;
			}
			else
				cout << 0;
		}		
		cout << '\n';
	}
	system("pause");
	return 0;
}