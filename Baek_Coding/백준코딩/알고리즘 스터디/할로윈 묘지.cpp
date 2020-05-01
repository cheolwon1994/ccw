#define MAX 987654321
#include <iostream>
#include <vector>
using namespace std;
struct info {
	int to,val;
};
info tmp;
int row, col, tomb, tx, ty, hole, ex, ey, ax, ay, t;
int arr[31][31];
bool ghost[31][31];
bool cycle;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
vector<info> v[901];		//row*col+col
int dist[901];

void make_graph() {
	//한 노드에서 다른 노드로 갈 수 있는 경우 v[]에 추가
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (arr[i][j] == -1 || (i*col+j==row*col-1) || ghost[i][j]) continue;
			for (int k = 0; k < 4; k++) {
				int nx = j + dx[k];
				int ny = i + dy[k];
				if (nx >= 0 && ny >= 0 && nx < col && ny < row && arr[ny][nx] != -1) {
					int a = i * col + j;
					int b = ny * col + nx;
					tmp.to = b;
					tmp.val = 1;
					v[a].push_back(tmp);
				}
			}
		}
	}
}

void bellman_ford() {
	//Node의 수+1 만큼 수행
	for (int i = 0; i <= row * col; i++) {
		for (int j = 0; j < row * col; j++) {
			if (dist[j] == MAX) continue;
			for (int k = 0; k < v[j].size(); k++) {
				int to = v[j][k].to;
				int val = v[j][k].val;
				int d = dist[j] + val;
				if (d != MAX && dist[to] > d) {
					if (i == (row * col)) 	cycle = true;					
					dist[to] = d;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (1) {
		cin >> col >> row;
		if (row == 0 && col == 0) break;			
		//초기화
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++) {
				ghost[i][j] = false;
				arr[i][j] = 0;
			}
		cycle = false;
		for (int i = 0; i <= row * col; i++) {
			dist[i] = MAX;
			v[i].clear();
		}
		dist[0] = 0;

		cin >> tomb;
		for (int i = 0; i < tomb; i++) {
			cin >> tx >> ty;
			arr[ty][tx] = -1;
		}
		cin >> hole;
		for (int i = 0; i < hole; i++) {
			cin >> ex >> ey >> ax >> ay >> t;
			int a = ey * col + ex;
			int b = ay * col + ax;
			tmp.to = b;
			tmp.val = t;
			v[a].push_back(tmp);
			ghost[ey][ex] = true;
		}
		make_graph();
		bellman_ford();
		if (cycle) cout << "Never\n";
		else if (dist[row*col-1] == MAX) cout << "Impossible\n";
		else cout << dist[row*col - 1] << '\n';
	}
	system("pause");
	return 0;
}