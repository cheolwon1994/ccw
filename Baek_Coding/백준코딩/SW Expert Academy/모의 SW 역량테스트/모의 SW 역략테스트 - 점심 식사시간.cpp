#define MAX 987654321
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string.h>
#include <math.h>
using namespace std;
struct info {
	int x, y, val;
};
info tmp;
vector<info> stair;
vector<info> people;
int arr[10][10];
int num, result;
int which_stair[10];

void start() {
	deque <int> s[2];
	int dist;
	for (int i = 0; i < people.size(); i++) {
		if (which_stair[i] == 0) {
			dist = abs(people[i].x - stair[0].x) + abs(people[i].y - stair[0].y);
			s[0].push_back(dist);
		}
		else {
			dist = abs(people[i].x - stair[1].x) + abs(people[i].y - stair[1].y);
			s[1].push_back(dist);
		}
	}
	for (int i = 0; i < 2; i++)
		sort(s[i].begin(), s[i].end());
	int t[2] = { 0,0 };
	for (int i = 0; i < 2; i++) {
		int sv = stair[i].val;
		deque <int> dq;
		while (!s[i].empty()) {
			if (!dq.empty()) {
				for (int j = 0; j < dq.size(); j++)
					dq[j] -= 1;
				int dq_len = dq.size();
				while (!dq.empty()) {
					if (dq[0] == 0)
						dq.pop_front();
					else
						break;
				}
			}
			while (!s[i].empty()) {
				if (s[i][0] + 1 > t[i] || dq.size() == 3)
					break;
				if (s[i][0] + 1 <= t[i]) {
					dq.push_back(sv);
					s[i].pop_front();
				}
			}
			if (s[i].empty())
				break;
			t[i]++;
		}
		t[i] += sv;
	}
	int temp = max(t[0], t[1]);
	result = min(result, temp);
}

void dfs(int cnt, int maxi) {
	if (cnt == maxi) {
		start();
		return;
	}
	which_stair[cnt] = 0;
	dfs(cnt + 1, maxi);
	which_stair[cnt] = 1;
	dfs(cnt + 1, maxi);
}

int main() {
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		cin >> num;
		//√ ±‚»≠
		stair.clear();
		people.clear();
		result = MAX;
		memset(which_stair, -1, sizeof(which_stair));
		for (int i = 0; i < num; i++)
			for (int j = 0; j < num; j++) {
				cin >> arr[i][j];
				if (arr[i][j] > 1) {
					tmp.x = j;
					tmp.y = i;
					tmp.val = arr[i][j];
					stair.push_back(tmp);
				}
				else if (arr[i][j] == 1) {
					tmp.x = j;
					tmp.y = i;
					people.push_back(tmp);
				}
			}
		dfs(0, people.size());
		cout << "#" << t << " " << result << endl;
	}
	system("pause");
	return 0;
}