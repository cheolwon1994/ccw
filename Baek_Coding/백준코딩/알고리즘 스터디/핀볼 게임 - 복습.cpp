#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct info {
	int x, y;
};
info tmp;
int arr[102][102], num, result;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int block[6][4] = { {0,0,0,0}, {-1,-1,1,0},{1,-1,-1,2},{3,2,-1,-1},{-1,0,3,-1},{-1,-1,-1,-1} };
vector<info> warmhole[11];

void dfs(int y, int x, int dir) {
	int nx = x, ny = y, nd = dir, val = 0;
	while (1) {
		nx += dx[nd];
		ny += dy[nd];
		int v = arr[ny][nx];
		if (v== 0 && val == 0) break;		//웜홀에 의한 무한루프
		if ((nx==x && ny==y)|| v == -1) {		//종료조건
			result = max(result, val);
			break;
		}
		if (0 < v && v < 6) {		//블록
			nd = block[v][nd];
			if (nd == -1) {
				result = max(result, val * 2 + 1);
				break;
			}
			else
				val++;
		}
		else if (v > 5) {		//웜홀
			if (nx == warmhole[v][0].x && ny == warmhole[v][0].y) {
				nx = warmhole[v][1].x;
				ny = warmhole[v][1].y;
			}
			else {
				nx = warmhole[v][0].x;
				ny = warmhole[v][0].y;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		cin >> num;
		//초기화
		for (int i = 0; i < num + 2; i++) {		//외곽을 벽5랑 같게 세팅
			arr[0][i] = 5;
			arr[i][0] = 5;
			arr[num + 1][i] = 5;
			arr[i][num + 1] = 5;
		}
		for (int i = 6; i < 11; i++)
			warmhole[i].clear();
		result = 0;

		for (int i = 1; i <= num; i++) 
			for (int j = 1; j <= num; j++) {
				cin >> arr[i][j];
				if (arr[i][j] > 5) {
					tmp.x = j;
					tmp.y = i;
					warmhole[arr[i][j]].push_back(tmp);
				}
			}
		for (int i = 1; i <= num; i++) 
			for (int j = 1; j <= num; j++) {
				if (arr[i][j] == 0) {
					for (int k = 0; k < 4; k++)
						dfs(i, j, k);
				}
			}		
		cout << "#" << t << " " << result << '\n';
	}
	return 0;
}