#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int cnt, tt;
	for (int t = 1; t <= 10; t++) {
		int arr[100];
		cin >> cnt;
		for (int i = 0; i < 100; i++) {
			cin >> arr[i];
		}
		cnt += 1;
		int maxi, mini;
		while (cnt--) {
			int max_idx = 0;
			maxi = arr[0];
			int min_idx = 0;
			mini = arr[0];
			for (int i = 1; i < 100; i++) {
				if (arr[i] > maxi) {
					maxi = arr[i];
					max_idx = i;
				}
				if (arr[i] < mini) {
					mini = arr[i];
					min_idx = i;
				}
			}
			if (cnt == 0 || mini+1==maxi || mini==maxi) break;
			arr[max_idx] -= 1;
			arr[min_idx] += 1;
		}
		cout << "#" << t << " " << maxi - mini << endl;
	}
	system("pause");
	return 0;
}