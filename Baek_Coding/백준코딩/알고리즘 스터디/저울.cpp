#include <iostream>
#include <algorithm>
using namespace std;
int arr[101][101];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int num, query, a, b;
	cin >> num >> query;
	for (int i = 0; i < query; i++) {
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = -1;
	}
	for (int k = 1; k <= num; k++) 
		for (int i = 1; i <= num; i++) 
			for (int j = 1; j <= num; j++) 
				if (arr[i][k] == arr[k][j] && arr[i][k] != 0)
					arr[i][j] = arr[i][k];

	for (int i = 1; i <= num; i++) {
		int cnt = num-1;
		for (int j = 1; j <= num; j++) 
			if (arr[i][j] != 0) cnt--;		
		cout << cnt << '\n';
	}			
	return 0;
}