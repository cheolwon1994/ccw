#define MAX 987654321
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
using namespace std;
struct info {
	int idx;
	double val;
};
struct cmp {
	bool operator()(info &a, info &b) {
		return a.val > b.val;
	}
};
info tmp;
vector<info> v[102];		//대포 최대 100개+시작+끝
double arr[102][2];
double cost[102][102];
double dist[102];
int pre[102];
int num;

double cal(int from, int to) {
	double x = fabs(arr[from][0] - arr[to][0]);
	double y = fabs(arr[from][1] - arr[to][1]);
	double val = hypot(x, y);
	return val;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	double sx, sy, ex, ey;
	cin >> arr[0][0] >> arr[0][1] >> ex >> ey;
	cin >> num;
	for (int i = 1; i <= num; i++) 
		cin >> arr[i][0] >> arr[i][1];	
	arr[num + 1][0] = ex;
	arr[num + 1][1] = ey;

	for (int i = 0; i <= num + 1; i++)
		dist[i] = MAX;
	priority_queue<info, vector<info>, cmp> pq;
	dist[0] = 0;
	tmp.idx = 0;
	tmp.val = 0;
	pq.push(tmp);
	bool first = true;
	while (!pq.empty()) {
		int cidx = pq.top().idx;
		double cv = pq.top().val;
		pq.pop();
		if (dist[cidx] < cv) continue;
		for (int i = 1; i <= num + 1; i++) {
			if (cidx == i) continue;
			double val = cal(cidx, i);
			double nv;
			if (first)
				nv = val / 5;
			else
				nv = min(val / 5, fabs(val - 50) / 5 + 2);
			if (dist[i] > cv + nv) {
				dist[i] = cv + nv;
				tmp.idx = i;
				tmp.val = cv + nv;
				pre[i] = cidx;
				pq.push(tmp);
			}
		}
		first = false;
	}
	cout << dist[num + 1];
	system("pause");
	return 0;
}