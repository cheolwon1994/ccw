#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

struct info {
	int idx, arr_t, from;
};
info tmp;

struct cmp {
	bool operator()(info &a, info &b) {
		if (a.arr_t == b.arr_t)
			return a.from > b.from;
		else
			return a.arr_t > b.arr_t;
	}
};

int first[10][3000];
int first_time[10];
int second[10][3000];
int second_time[10];
int arrive[1001];
vector<int> p[1001];
int main() {
	int test, f, s, people, tf, ts, maxi, result;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		cin >> f >> s >> people >> tf >> ts;
		//초기화
		for (int i = 0; i < 10; i++) {
			memset(first[i], 0, sizeof(first[i]));
			memset(second[i], 0, sizeof(second[i]));
		}
		for (int i = 1; i <= people; i++)
			p[i].clear();
		result = 0;
		priority_queue<info, vector<info>, cmp> pq;

		for (int i = 1; i <= f; i++)
			cin >> first_time[i];
		for (int j = 1; j <= s; j++)
			cin >> second_time[j];
		for (int i = 1; i <= people; i++)
			cin >> arrive[i];

		for (int i = 1; i <= people; i++) {
			int at = arrive[i];
			bool avail = false;
			for (int j = at;; j++) {
				for (int k = 1; k <= f; k++) {		//창구 번호
					if (first[k][j] == 0) {
						p[i].push_back(k);
						maxi = max(maxi, j + first_time[k]);
						for (int m = 0; m < first_time[k]; m++)
							first[k][j + m] = i;
						avail = true;
						break;
					}
				}
				if (avail)
					break;
			}
		}

		for (int i = 1; i <= f; i++) {
			for (int j = 0; j < maxi; j++) {
				if (first[i][j] != first[i][j + 1] && first[i][j] != 0) {
					tmp.arr_t = j + 1;
					tmp.idx = first[i][j];
					tmp.from = i;
					pq.push(tmp);
				}
			}
		}
		int idx;
		while (!pq.empty()) {
			int at = pq.top().arr_t;
			idx = pq.top().idx;
			bool avail = false;
			for (int j = at;; j++) {
				for (int k = 1; k <= s; k++) {
					if (second[k][j] == 0) {
						p[idx].push_back(k);
						for (int m = 0; m < second_time[k]; m++)
							second[k][j + m] = idx;
						avail = true;
						break;
					}
				}
				if (avail)
					break;
			}
			pq.pop();
		}
		for (int i = 1; i <= people; i++) {
			if (p[i][0] == tf && p[i][1] == ts)
				result += i;
		}
		if (result == 0)
			cout << "#" << t << " " << -1 << endl;
		else
			cout << "#" << t << " " << result << endl;
	}
	system("pause");
	return 0;
}