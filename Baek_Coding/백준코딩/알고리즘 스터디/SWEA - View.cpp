#include <iostream>
#include <algorithm>
using namespace std;
int arr[1004];
int num, maxi, result;
bool flag;
int dx[4] = { -2,-1,1,2 };
int main() {
	for (int t = 1; t <= 10; t++) {
		//ÃÊ±âÈ­
		result = 0;

		cin >> num;
		for (int i = 2; i < num + 2; i++)
			cin >> arr[i];
		for (int i = 2; i < num + 2; i++) {
			flag = true;
			maxi = -1;
			for (int j = 0; j < 4; j++) {
				maxi = max(maxi, arr[i + dx[j]]);
				if (arr[i + dx[j]] >= arr[i]) {
					flag = false;
					break;
				}
			}
			if (flag)
				result += arr[i] - maxi;
		}
		cout << "#" << t << " " << result << endl;
	}
	system("pause");
	return 0;
}