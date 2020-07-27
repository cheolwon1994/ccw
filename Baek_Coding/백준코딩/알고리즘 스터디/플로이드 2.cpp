#define MAX 9876543210
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long arr[101][101];
vector<int> v[101][101];
int node, edge, s, e, val;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> node >> edge;
	for(int i=1;i<=node;i++)
		for (int j = 1; j <= node; j++) {
			if (i == j) arr[i][j] = 0;
			else arr[i][j] = MAX;
			v[i][j].push_back(i);
			v[i][j].push_back(j);
		}
	for (int i = 0; i < edge; i++) {
		cin >> s >> e >> val;
		if(arr[s][e]>val)
			arr[s][e] = val;
	}

	for (int k = 1; k <= node; k++) {
		for (int i = 1; i <= node; i++) {
			for (int j = 1; j <= node; j++) {
				if (arr[i][j] > arr[i][k] + arr[k][j]) {
					arr[i][j] = arr[i][k] + arr[k][j];
					vector<int> t = v[k][j];
					v[i][j].clear();
					v[i][j] = v[i][k];
					for (int m = 1; m < t.size(); m++)
						v[i][j].push_back(t[m]);
				}
			}
		}
	}

	for (int i = 1; i <= node; i++) {
		for (int j = 1; j <= node; j++) {
			if (arr[i][j] == MAX) arr[i][j]=0;
			cout << arr[i][j] << " ";
		}
		cout << '\n';
	}

	for (int i = 1; i <= node; i++) {
		for (int j = 1; j <= node; j++) {
			if (arr[i][j] == 0)	cout << 0 << " ";
			else {
				cout << v[i][j].size() << " ";
				for (int k = 0; k < v[i][j].size(); k++)
					cout << v[i][j][k] << " ";
			}
			cout << '\n';
		}
	}
	return 0;
}