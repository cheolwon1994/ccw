#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int arr[100][100];
int num;
struct info {
	int start;
	int end;
};
info tmp;
queue<info> q;

int main() {
	cin >> num;
	for (int i = 0; i < num; i++)
		for (int j = 0; j < num; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				tmp.end = j;
				tmp.start = i;
				q.push(tmp);
			}
		}
	//cout << endl;
	int cx, cy;
	while (!q.empty()) {
		cx = q.front().end;
		cy = q.front().start;
		q.pop();
		for (int i = 0; i < num; i++) {
			if (arr[cx][i] == 1) {
				if (arr[cy][i] == 0) {
					arr[cy][i] = 1;
					tmp.end = i;
					tmp.start = cy;
					q.push(tmp);
					tmp.start = cx;
					q.push(tmp);
				}
			}
		}
	}
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}