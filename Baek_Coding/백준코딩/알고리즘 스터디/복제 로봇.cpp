#define MAX 987654321
#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
int arr[50][50];	//벽: -1, 시작위치와 키 위치>=1
int check[50][50];
bool visit[252] = { false, };
int num, key;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

struct info {
	int idx, val;
};
struct cmp {
	bool operator()(info &a, info &b) {
		return a.val > b.val;
	}
};
struct info2 {
	int x, y;
};
info tmp;
info2 tmp2;
vector<info> v[252];
vector<info2> node;		//각 Node에 대한 정보를 담고 있다

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> num >> key;
	int cnt = 1, sidx;
	char c;
	string str;
	for (int i = 0; i < num; i++) {
		cin >> str;
		for (int j = 0; j < num; j++) {
			c = str[j];
			if (c == '1') arr[i][j] = -1;
			else if (c == '0') arr[i][j] = 0;
			else {
				if (c == 'S') sidx = cnt;
				arr[i][j] = cnt++;
				tmp2.x = j;
				tmp2.y = i;
				node.push_back(tmp2);
			}
		}
	}
	//prim 알고리즘을 사용하기 위해 각 Node에서 서로 다른 Node까지의 거리를 구한다
	for (int t = 1; t <= key + 1; t++) {
		for (int i = 0; i < num; i++)
			for (int j = 0; j < num; j++)
				check[i][j] = MAX;
		queue<info2> q;
		tmp2.x = node[t - 1].x;
		tmp2.y = node[t - 1].y;
		q.push(tmp2);
		check[tmp2.y][tmp2.x] = 0;
		while (!q.empty()) {
			int cx = q.front().x;
			int cy = q.front().y;
			int cv = check[cy][cx];
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if (nx >= 0 && ny >= 0 && nx < num && ny < num && arr[ny][nx]!=-1) {
					if (check[ny][nx] == MAX) {
						check[ny][nx] = cv + 1;
						if (arr[ny][nx] != 0) {		//다른 node인 경우
							tmp.idx = arr[ny][nx];
							tmp.val = cv + 1;
							v[t].push_back(tmp);
							continue;
						}
						//node도 벽도 아닌 경우
						tmp2.x = nx;
						tmp2.y = ny;					
						q.push(tmp2);
					}
				}
			}
		}
	}
	//prim 알고리즘
	priority_queue<info, vector<info>, cmp> pq;
	queue<int> q;
	int result = 0;
	q.push(sidx);
	while (!q.empty()) {
		int cidx = q.front();
		q.pop();
		visit[cidx] = true;
		for (int i = 0; i < v[cidx].size(); i++) {
			int next = v[cidx][i].idx;
			int nv = v[cidx][i].val;
			if (!visit[next]) {
				tmp.idx = next;
				tmp.val = nv;
				pq.push(tmp);
			}
		}
		while (!pq.empty()) {
			int next = pq.top().idx;
			int nv = pq.top().val;
			pq.pop();
			if (visit[next]) continue;
			result += nv;
			q.push(next);
			break;
		}
	}
	//모두 방문이 불가능한 경우 처리
	for (int i = 1; i <= key + 1; i++) {
		if (!visit[i]) {
			result = -1;
			break;
		}
	}
	cout << result;
	system("pause");
	return 0;
}