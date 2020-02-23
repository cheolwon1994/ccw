#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;
int arr[101][101];
int ans[101];
bool flag[101] = { false, };
struct info {
	int idx, val;
};
info tmp;
int main() {
	int num, relation, start, end;
	cin >> num >> relation;
	memset(arr, 0, sizeof(arr));
	memset(ans, 0, sizeof(ans));
	for (int i = 0; i < relation; i++) {
		cin >> start >> end;
		arr[start][end] = 1;
		arr[end][start] = 1;			
	}
	for (int i = 1; i <= num; i++) {
		queue<info> q;
		memset(flag, false, sizeof(flag));
		tmp.idx = i;
		tmp.val = 0;
		int sum = 0;
		flag[i] = true;
		q.push(tmp);
		while (!q.empty()) {
			int cidx = q.front().idx;
			int cv = q.front().val;
			q.pop();
			for (int j = 1; j <= num; j++) {
				if (cidx == j) continue;
				if (arr[cidx][j] != 0 && !flag[j]) {
					sum += (cv + 1);
					tmp.idx = j;
					tmp.val = cv + 1;
					flag[j] = true;
					q.push(tmp);
				}
			}
		}
		ans[i] = sum;
	}
	int idx = 0, result = 987654321;
	for (int i = 1; i <= num; i++) {
		if (result > ans[i]) {
			result = ans[i];
			idx = i;
		}
	}
	cout << idx;
	system("pause");
	return 0;
}