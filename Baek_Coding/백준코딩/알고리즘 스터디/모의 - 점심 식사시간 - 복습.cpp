#define MAX 987654321
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
using namespace std;
int arr[10][10], num, people, result;
int order[10], px[10], py[10], sx[2], sy[2], sl[2];

int cal(int o) {
	vector<int> v;
	for (int i = 0; i < people; i++)
		if (order[i] == o) {
			int tx = abs(sx[o] - px[i]);
			int ty = abs(sy[o] - py[i]);
			v.push_back(tx + ty);
		}
	sort(v.begin(), v.end());
	int t_result = 0, idx = 0;		//현재 시간, 도착한 사람
	int escape = v.size();
	deque<int> dq;
	while (escape > 0) {
		while (idx < v.size() && t_result >= v[idx] && dq.size()<3) {
			dq.push_back(sl[o]);
			idx++;
		}
		for (int i = 0; i < dq.size(); i++) 
			dq[i]--;
		while (!dq.empty()) {
			if (dq[0] == 0) {
				dq.pop_front();
				escape--;
			}
			else
				break;
		}		
		t_result++;
	}
	return t_result + 1;
}

void dfs(int cnt) {
	if (cnt == people) {
		//계산
		result = min(result, max(cal(0), cal(1)));
		return;
	}
	for (int i = 0; i < 2; i++) {
		order[cnt] = i;
		dfs(cnt + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		cin >> num;
		//초기화
		people = 0;
		sx[0] = -1;
		result = MAX;

		for (int i = 0; i < num; i++)
			for (int j = 0; j < num; j++) {
				cin >> arr[i][j];
				if (arr[i][j] > 1) {
					if (sx[0] == -1) {
						sx[0] = j;
						sy[0] = i;
						sl[0] = arr[i][j];
					}
					else {
						sx[1] = j;
						sy[1] = i;
						sl[1] = arr[i][j];
					}
				}
				else if (arr[i][j] == 1) {
					px[people] = j;
					py[people++] = i;
				}
			}

		dfs(0);
		cout << "#" << t << " " << result << '\n';
	}
	return 0;
}