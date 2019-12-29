#define MAX 987654321
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <math.h>
#include <string.h>
using namespace std;
int house, plant, result;
int arr[100000];

int main() {
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		cin >> house >> plant;
		for (int i = 0; i < house; i++)
			cin >> arr[i];
		if (house <= plant) {
			cout << "#" << t << " " << 0 << endl;
			continue;
		}
		priority_queue<int, vector<int>, greater<int>> pq;
		for (int i = 0; i < house - 1; i++) 
			pq.push(arr[i + 1] - arr[i]);	
		result = 0;
		for (int i = 0; i < house-plant; i++) {
			result += pq.top();
			pq.pop();
		}
		cout << "#" << t << " " << result << endl;
	}
	system("pause");
	return 0;
}