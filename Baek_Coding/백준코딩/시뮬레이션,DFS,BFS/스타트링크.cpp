#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;
int arr[1000001];
int cur, destination, total, up, down, idx;
int result = 0;
queue<int> q;
int main() {
	cin >> total >> cur >> destination >> up >> down;
	memset(arr, -1, sizeof(arr));
	if (cur == destination) {
		cout << result;
		system("pause");
		return 0;
	}
	arr[cur] = 0;
	q.push(cur);
	while (!q.empty()) {
		idx = q.front();
		q.pop();
		if (idx + up <= total && arr[idx + up] == -1) {
			arr[idx + up] = arr[idx] + 1;
			q.push(idx + up);			
		}
		if(idx - down > 0 && arr[idx - down] == -1){
			arr[idx - down] = arr[idx] + 1;
			q.push(idx - down);
		}
	}
	if (arr[destination] != -1)
		cout << arr[destination];
	else
		cout << "use the stairs";
	system("pause");
	return 0;
}