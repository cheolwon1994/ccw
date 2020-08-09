#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int arr[100001], num;
bool check[100001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		cin >> num;
		for (int i = 1; i <= num; i++) {
			cin >> arr[i];
			check[i] = false;
		}
		int cnt = 0;
		for (int i = 1; i <= num; i++) {
			if (!check[i]) {		//아직 검사 안한 경우
				if (arr[i] == i) {		//1인 팀을 이룰 경우
					check[i] = true;
					continue;
				}
				deque<int> dq;
				dq.push_back(i);
				check[i] = true;
				bool cycle = false;
				while (!dq.empty()) {
					int idx = dq[dq.size() - 1];
					int next = arr[idx];
					if (!check[next]) {
						check[next] = true;
						dq.push_back(next);
						continue;
					}
					while (!dq.empty()) {
						if (next == dq[0]) {		//cycle 생성
							cycle = true;
							break;
						}
						else {
							dq.pop_front();
							cnt++;
						}
					}
					if (cycle) break;
				}
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}