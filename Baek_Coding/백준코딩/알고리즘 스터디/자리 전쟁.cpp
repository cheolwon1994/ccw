#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct info {
	int cidx, pidx, val;
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
int row, col, result = 0;
char arr[100][100];
vector<info2> chair;
vector<info2> people;
int seated[10000];						//의자에 앉거나
bool finished[10000] = { false, };      //people
vector<int> v;

void cal() {
	for (int i = 0; i < v.size(); i++) {
		int cidx = v[i];
		seated[cidx]++;
		if (seated[cidx] == 2) result++;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	priority_queue<info, vector<info>, cmp> pq;
	cin >> row >> col;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) {
			char c;
			cin >> c;
			arr[i][j] = c;
			if (c == 'L') {     //좌석
				tmp2.x = j;
				tmp2.y = i;
				chair.push_back(tmp2);
			}
			else if (c == 'X') {
				tmp2.x = j;
				tmp2.y = i;
				people.push_back(tmp2);
			}
		}
	for (int i = 0; i < people.size(); i++) {
		int px = people[i].x;
		int py = people[i].y;
		tmp.pidx = i;
		for (int j = 0; j < chair.size(); j++) {
			int cx = chair[j].x;
			int cy = chair[j].y;
			int dist = (cx - px)*(cx - px) + (cy - py)*(cy - py);
			tmp.cidx = j;
			tmp.val = dist;
			pq.push(tmp);
		}
	}
	int cidx = pq.top().cidx;
	int pidx = pq.top().pidx;
	int dist = pq.top().val;
	v.push_back(cidx);
	finished[pidx] = true;
	pq.pop();

	while (!pq.empty()) {
		int nc = pq.top().cidx;
		int np = pq.top().pidx;
		int nd = pq.top().val;
		pq.pop();
		if (dist != nd) {		//거리가 다르다면
			dist = nd;
			if (!v.empty()) {
				cal();
				v.clear();
			}
		}
		if (seated[nc] == 0 && !finished[np]) {		//해당 의자가 비었고, 이미 다른 의자에 앉은 사람이 아니라면
			v.push_back(nc);
			finished[np] = true;
		}			
	}
	if(!v.empty())
		cal();
	cout << result;
	return 0;
}