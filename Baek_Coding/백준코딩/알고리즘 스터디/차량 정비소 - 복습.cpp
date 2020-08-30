#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
struct info {
	int pidx, from, arrivetime;
};
struct info2 {
	int pidx, needTime, remain;
	bool fin;
};
struct cmp {
	bool operator()(info &a, info &b) {
		if (a.arrivetime == b.arrivetime) {
			return a.from > b.from;
		}
		return a.arrivetime > b.arrivetime;
	}
};
info tmp;
int p[1001][2], n, m, person, result, tn, tm;		//p[idx][]는 idx고객의 접수/수리 창구번호 저장
info2 reception[10], repair[10];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		//초기화
		result = 0;

		cin >> n >> m >> person >> tn >> tm;
		for (int i = 1; i <= n; i++) {
			cin >> reception[i].needTime;
			reception[i].fin = true;
		}
		for (int i = 1; i <= m; i++) {
			cin >> repair[i].needTime;
			repair[i].fin = true;
		}
		queue<info> q;
		for (int i = 1; i <= person; i++) {
			int val;
			cin >> val;
			tmp.arrivetime = val;
			tmp.pidx = i;
			q.push(tmp);
		}
		priority_queue<info, vector<info>, cmp> waiting;
		int ct = q.front().arrivetime;
		bool finish = false;
		int cnt = 0;
		while (cnt<person) {
			//새로운 손님이 창구에 도착했는가
			while (!q.empty()) {
				if (q.front().arrivetime <= ct) {			//창구에 도착
					bool avail = false;
					for (int i = 1; i <= n; i++) {			//접수 창구번호
						if (reception[i].fin) {
							reception[i].fin = false;
							reception[i].remain = reception[i].needTime;
							reception[i].pidx = q.front().pidx;		//사람 번호
							q.pop();
							avail = true;
							break;
						}
					}
					if (!avail) break;
				}
				else break;
			}
			//접수창구가 끝났는가
			for (int i = 1; i <=n; i++)	{	//시간을 줄인다
				if (!reception[i].fin) {		//사용중인 창구
					reception[i].remain--;
					if (reception[i].remain == 0) {
						int pidx = reception[i].pidx;
						p[pidx][0] = i;			//접수 창구번호 저장
						reception[i].fin = true;
						tmp.arrivetime = ct;
						tmp.from = i;
						tmp.pidx = pidx;
						waiting.push(tmp);
					}
				}
			}
			//수리창구가 비었는가
			while (!waiting.empty()) {
				bool avail = false;
				for (int i = 1; i <= m; i++) {			//접수 창구번호
					if (repair[i].fin) {
						repair[i].fin = false;
						repair[i].remain = repair[i].needTime;
						repair[i].pidx = waiting.top().pidx;		//사람 번호
						waiting.pop();
						avail = true;
						break;
					}
				}
				if (!avail) break;
			}

			//수리창구 끝났는가
			for (int i = 1; i <= m; i++) {	//시간을 줄인다
				if (!repair[i].fin) {		//사용중인 창구
					repair[i].remain--;
					if (repair[i].remain == 0) {
						int pidx = repair[i].pidx;
						p[pidx][1] = i;			//접수 창구번호 저장
						repair[i].fin = true;
						cnt++;
					}
				}
			}	
			ct++;
		}

		//계산
		for (int i = 1; i <= person; i++) {
			//cout << i + 1 << " " << p[i][0] << " " << p[i][1] << endl;
			if (p[i][0] == tn && p[i][1] == tm)
				result += i;
		}
		if (result == 0) result = -1;
		cout << "#" << t << " " << result << '\n';
	}
	return 0;
}