#define MAX 987654321
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct info {
	int idx, val;
};
info tmp;
int arr[101][101];
int dist[101];
int main() {
	int num, instruction, start, end;
	cin >> num >> instruction;
	for (int i = 1; i <= num; i++)
		for (int j = 1; j <= num; j++)
			arr[i][j] = MAX;
	for (int i = 0; i < instruction; i++) {
		cin >> start >> end;
		arr[start][end] = 1;
		arr[end][start] = 1;
	}
	int kevin = 0, amount = MAX;
	for (int k = 1; k <= num; k++) {
		for (int i = 1; i <= num; i++)
			dist[i] = MAX;
		dist[k] = 0;
		queue<int> q;
		for (int i = 1; i <=num; i++) {
			if (arr[k][i] !=MAX) {
				q.push(i);
				dist[i] = arr[k][i];
			}
		}
		while (!q.empty()) {
			int cidx = q.front();
			q.pop();
			for (int i = 1; i <=num; i++) {
				if (i == cidx) continue;
				if (arr[cidx][i] != MAX && dist[i] > arr[cidx][i] + dist[cidx]) {
					dist[i] = arr[cidx][i] + dist[cidx];
					q.push(i);
				}				
			}
		}
		int sum = 0;
		for (int i = 1; i <= num; i++) 
			sum += dist[i];
		if (sum < amount) {
			amount = sum;
			kevin = k;
		}			
	}
	cout << kevin;
	system("pause");
	return 0;
}