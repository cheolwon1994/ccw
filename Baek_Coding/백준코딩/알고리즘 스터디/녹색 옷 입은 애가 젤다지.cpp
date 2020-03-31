#define MAX 987654321
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct info {
	int x, y, val;
};
struct cmp {
	bool operator()(info &a, info &b) {
		return a.val > b.val;
	}
};
info tmp;
int num;
int arr[125][125];
bool check[125][125];
int dist[125][125];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int result;
	for(int k=1;;k++) {
		cin >> num;
		if (num == 0) break;
		result = 0;
		for (int i = 0; i < num; i++)
			for (int j = 0; j < num; j++) {
				cin >> arr[i][j];
				check[i][j] = false;
				dist[i][j] = MAX;
			}

		priority_queue<info, vector<info>, cmp> pq;
		tmp.x = 0;
		tmp.y = 0;
		tmp.val = arr[0][0];
		pq.push(tmp);
		dist[0][0] = arr[0][0];
		while (!pq.empty()) {
			int cx = pq.top().x;
			int cy = pq.top().y;
			int cv = pq.top().val;
			pq.pop();
			if (cy == num - 1 && cx == num - 1) {
				result = cv;
				break;
			}
			if (check[cy][cx]) continue;
			check[cy][cx] = true;
			for (int i = 0; i < 4; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if (nx >= 0 && ny >= 0 && nx < num && ny < num && !check[ny][nx]) {
					if (dist[ny][nx] > cv + arr[ny][nx]) {
						dist[ny][nx] = cv + arr[ny][nx];
						tmp.x = nx;
						tmp.y = ny;
						tmp.val = dist[ny][nx];
						pq.push(tmp);
					}
				}
			}
		}
		cout << "Problem "<<k<<": "<<result << '\n';
	}
	system("pause");
	return 0;
}