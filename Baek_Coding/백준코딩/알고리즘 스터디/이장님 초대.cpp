#include <iostream>
#include <algorithm>
using namespace std;
int result = 0;
int arr[100000];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int num, tt;
	cin >> num;
	for (int i = 0; i < num; i++) 
		cin >> arr[i];
	sort(arr, arr + num);
	int cnt = 2;
	for (int i = num-1; i >=0; i--) {
		result = max(result, cnt + arr[i]);
		cnt++;
	}
	cout << result;
	system("pause");
	return 0;
}