#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> v[32001];
int connection[32001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int num, edge, start, end;
	cin >> num >> edge;
	for (int i = 0; i < edge; i++) {
		cin >> start >> end;
		v[start].push_back(end);
		connection[end]++;
	}
	queue<int> q;
	for (int i = 1; i <= num; i++)
		if (connection[i] == 0)
			q.push(i);
	for(int i=0;i<num;i++){
		int cidx = q.front();
		q.pop();
		cout << cidx << " ";
		for (int j = 0; j < v[cidx].size(); j++) {
			connection[v[cidx][j]]--;
			if (connection[v[cidx][j]] == 0)
				q.push(v[cidx][j]);
		}
	}
	system("pause");
	return 0;
}