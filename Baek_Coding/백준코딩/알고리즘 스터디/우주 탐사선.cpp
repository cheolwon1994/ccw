#define MAX 9876543210
#include <iostream>
#include <algorithm>
using namespace std;
int node, start, arr[10][10], ans = MAX;
bool visit[10] = { false, };

void dfs(int idx, int dist, int planet) {
	if (ans < dist) return;
	if (planet == node) {
		ans = min(ans, dist);
		return;
	}
	for (int i = 0; i < node; i++) {
		if (visit[i] || i == idx) continue;
		visit[i] = true;
		dfs(i, dist + arr[idx][i], planet + 1);
		visit[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> node >> start;
	for (int i = 0; i < node; i++)
		for (int j = 0; j < node; j++) 
			cin >> arr[i][j];		
	visit[start] = true;

	for (int k = 0; k < node; k++) 
		for (int i = 0; i < node; i++)
			for (int j = 0; j < node; j++)
				if (arr[i][j] > arr[i][k] + arr[k][j])
					arr[i][j] = arr[i][k] + arr[k][j];
	dfs(start, 0, 1);
	cout << ans;
	return 0;
}