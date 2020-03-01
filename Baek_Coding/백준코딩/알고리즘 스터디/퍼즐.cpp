#include <iostream>
#include <map>
#include <queue>
using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int finish = 123456780;
struct info {
	int num, val;
};
info tmp;

int main() {
	int tt, start = 0;
	for (int i = 0; i < 9; i++) {
		cin >> tt;	
		start *= 10;
		start += tt;	
	}
	map<int, int> m;
	m[start] = 0;
	queue<info> q;
	tmp.num = start;
	tmp.val = 0;
	q.push(tmp);
	int result = -1;
	while (!q.empty()) {
		int cnum = q.front().num;
		int cv = q.front().val;
		q.pop();
		if (cnum == finish) {
			result = cv;
			break;
		}
		int arr[3][3];
		int sx = 0, sy = 0;
		for(int i=2;i>=0;i--)
			for (int j = 2; j >= 0; j--) {
				arr[i][j] = cnum % 10;
				if (arr[i][j] == 0) {
					sx = j;
					sy = i;
				}
				cnum /= 10;
			}
		for (int i = 0; i < 4; i++) {
			int nx = sx + dx[i];
			int ny = sy + dy[i];
			if (nx >= 0 && ny >= 0 && nx < 3 && ny < 3) {
				int next = 0;
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						next *= 10;
						if (i == sy && j == sx) 	next += arr[ny][nx];
						else if (i == ny && j == nx)		next += arr[sy][sx];
						else next += arr[i][j];						
					}
				}
				if (m[next] == 0) {
					m[next] = cv + 1;
					tmp.num = next;
					tmp.val = cv + 1;
					q.push(tmp);
				}
			}
		}
	}
	cout << result;
	system("pause");
	return 0;
}