#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[101], num, start;
bool visit[101];
bool check[101] = { false, };
vector<int> ans;

void dfs(int idx) {
	//되돌아 오는 경우
	if (idx == start && visit[idx]) {
		for (int i = 1; i <= num; i++)
			if (visit[i] && !check[i]) {
				ans.push_back(i);
				check[i] = true;
			}
		return;
	}
	if (visit[idx]) return;
	visit[idx] = true;
	int next = arr[idx];
	dfs(next);
}

int main() {
	cin >> num;
	for (int i = 1; i <= num; i++)
		cin >> arr[i];
	for (int i = 1; i <= num; i++) {
		for (int j = 1; j <= num; j++)
			visit[j] = false;
		start = i;
		dfs(i);
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << "\n";
	system("pause");
	return 0;
}