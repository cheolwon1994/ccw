#include <iostream>
#include <algorithm>
using namespace std;
int arr[3];
int maxi[2][3], mini[2][3];		//[0][]: pre, [1][]: cur
int num;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> num;
	for (int t = 0; t < num; t++) {
		for (int i = 0; i < 3; i++)
			cin >> arr[i];
		if (t == 0) {
			for (int i = 0; i < 3; i++)
				maxi[1][i] = mini[1][i] = arr[i];
		}
		else {
			maxi[1][0] = max(maxi[0][0], maxi[0][1]) + arr[0];
			maxi[1][1] = max(max(maxi[0][0], maxi[0][1]), maxi[0][2]) + arr[1];
			maxi[1][2] = max(maxi[0][2], maxi[0][1]) + arr[2];

			mini[1][0] = min(mini[0][0], mini[0][1]) + arr[0];
			mini[1][1] = min(min(mini[0][0], mini[0][1]), mini[0][2]) + arr[1];
			mini[1][2] = min(mini[0][2], mini[0][1]) + arr[2];
		}
		for (int i = 0; i < 3; i++) {
			maxi[0][i] = maxi[1][i];
			mini[0][i] = mini[1][i];
		}
	}
	int maxR = max(max(maxi[0][0], maxi[0][1]), maxi[0][2]);
	int minR = min(min(mini[0][0], mini[0][1]), mini[0][2]);
	cout << maxR << " " << minR;
	return 0;
}