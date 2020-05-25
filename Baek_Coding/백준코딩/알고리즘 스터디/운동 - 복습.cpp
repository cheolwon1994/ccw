#define MAX 9876543210
#include <iostream>
#include <algorithm>
using namespace std;
int node, edge, s, e, val;
long long arr[401][401];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> node >> edge;
	for(int i=1;i<=node;i++)
		for (int j = 1; j <= node; j++) {
			if (i == j) arr[i][j] = 0;
			else arr[i][j] = MAX;
		}
	for (int i = 0; i < edge; i++) {
		cin >> s >> e >> val;
		arr[s][e] = val;
	}
	for (int k = 1; k <= node; k++) {
		for (int i = 1; i <= node; i++) {
			for (int j = 1; j <= node; j++) {
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}
	long long result = MAX;
	for (int i = 1; i <= node; i++) 
		for (int j = 1; j <= node; j++) {
			if (i == j) continue;
			result = min(result, arr[i][j] + arr[j][i]);
		}	
	if (result == MAX) result = -1;
	cout << result;
	system("pause");
	return 0;
}