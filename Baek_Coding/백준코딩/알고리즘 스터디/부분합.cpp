#include <iostream>
#include <algorithm>
using namespace std;
int result = 100001, num;
long long sum;
int arr[100000];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> num >> sum;
	for (int i = 0; i < num; i++)
		cin >> arr[i];
	long long tot = arr[0];
	int lidx = 0, ridx = 0;
	while (lidx <= ridx && lidx < num) {
		if (tot >= sum) {
			result = min(result, (ridx - lidx) + 1);
			if (lidx < ridx) {
				tot -= arr[lidx];
				lidx++;
			}
			else if (lidx == ridx) {
				if (ridx == num - 1) break;
				else {
					ridx++;
					tot += arr[ridx];
				}
			}
		}
		else {		//더 추가해야 하는 경우
			if (ridx == num - 1) 		//더 추가할 원소가 없는 경우
				break;
			else {			//더 추가할 원소가 있는 경우
				ridx++;
				tot += arr[ridx];
			}
		}
	}
	if (result == 100001) result = 0;
	cout << result;
	system("pause");
	return 0;
}