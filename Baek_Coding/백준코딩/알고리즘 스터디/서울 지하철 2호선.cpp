#define MAX 987654321
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct info {
	int pre, now;
};
info tmp;
vector<int> v[3001];
int num, s, e, start = -1;
int check[3001];
int before[3001];
int dist[3001];

void cal(int pre, int cur) {
	check[cur] = check[pre] + 1;
	for (int i = 0; i < v[cur].size(); i++) {
		if (check[v[cur][i]] == 0)
			cal(cur, v[cur][i]);
	}	
}

void find_cycle() {
	for (int i = 1; i <= num; i++) {
		check[i] = 0;
		dist[i] = -1;
	}
	check[start] = 1;
	queue<info> q;
	queue<int> ans;
	tmp.pre = start;
	before[start] = start;
	for (int i = 0; i < v[start].size(); i++) {
		int next = v[start][i];
		check[next] = 1;
		tmp.now = next;
		q.push(tmp);
		before[next] = start;
	}
	bool finish = false;
	while (!q.empty()) {
		int cp = q.front().pre;
		int cn = q.front().now;
		q.pop();
		for (int i = 0; i < v[cn].size(); i++) {
			int next = v[cn][i];
			if (next != cp) {
				if (check[next] != 0) {		//반대에서 만나는 지점
					ans.push(next);
					ans.push(cn);
					finish = true;
					break;
				}
				else {
					check[next] = 1;
					tmp.pre = cn;
					tmp.now = next;
					q.push(tmp);
					before[next] = cn;
				}
			}
		}
		if (finish) break;
	}

	while (!ans.empty()) {
		int cidx = ans.front();
		ans.pop();
		dist[cidx] = 0;
		if (cidx == start) continue;
		else
			ans.push(before[cidx]);
	}
}

//내부 순환선에 속하는 역을 1개 찾는다
void find_dup() {
	queue<info> q;
	tmp.pre = 1;
	check[1] = 1;
	for (int i = 0; i < v[1].size(); i++) {
		tmp.now = v[1][i];
		q.push(tmp);
		check[v[1][i]] = 1;
	}
	while (!q.empty()) {
		int cp = q.front().pre;
		int cn = q.front().now;
		q.pop();
		for (int i = 0; i < v[cn].size(); i++) {
			int next = v[cn][i];
			if (next != cp) {
				if (check[next] == 1) {
					start = next;
					break;
				}
				else {
					check[next] = true;
					tmp.now = next;
					tmp.pre = cn;
					q.push(tmp);
				}
			}
		}
		if (start > 0) break;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> s >> e;
		v[s].push_back(e);
		v[e].push_back(s);
	}
	queue<int> transfer, result;
	//환승지점을 구해놓는다
	for(int i=1;i<=num;i++)
		if (v[i].size() > 2) {
			transfer.push(i);
		}
	find_dup();
	find_cycle();

	//순환선이면서 환승인 지점 Result에 넣기
	while (!transfer.empty()) {
		int cidx = transfer.front();
		transfer.pop();
		if (dist[cidx] == 0)
			result.push(cidx);
	}
	//거리 구하기
	while (!result.empty()) {
		int cidx = result.front();
		result.pop();
		for (int i = 0; i < v[cidx].size(); i++) {
			int next = v[cidx][i];
			if (dist[next] == -1) {
				dist[next] = dist[cidx] + 1;
				result.push(next);
			}
		}
	}
	for (int i = 1; i <= num; i++)
		cout << dist[i] << " ";
	return 0;
}