#include <iostream>
using namespace std;
int arr[601][301];
int number[10001];
int level = 1, sx = 150, sy = 300, cnt = 1;
int dx[6] = { 0,-1,-1,0,1,1 };
int dy[6] = { -2,-1,1,2,1,-1 };
int num[6] = { 0,1,0,0,0,0 };		//사용한 숫자
bool avail[6];

void check() {
	for (int i = 1; i < 6; i++)
		avail[i] = false;
	//인접한것들 true로 전환
	for (int i = 0; i < 6; i++) {
		int nx = sx + dx[i];
		int ny = sy + dy[i];
		int val = arr[ny][nx];
		if (val != 0) avail[val] = true;
	}
	int maxi = 10000;
	int idx = 0;
	for (int i = 1; i < 6; i++) {
		if (!avail[i]) {				//인접하지 않으면서
			if (num[i] < maxi) {		//사용한 갯수가 가장 적으면서, i값이 작은거
				maxi = num[i];
				idx = i;
			}
		}
	}
	arr[sy][sx] = idx;
	num[idx]++;
	number[++cnt] = idx;
}

void cal() {
	while (level < 61) {
		sx += 1;
		sy -= 1;
		check();
		if (cnt == 10001) break;
		for (int i = 0; i < level - 1; i++) {
			sx += dx[0];
			sy += dy[0];
			check();
			if (cnt == 10001) break;
		}
		for (int k = 1; k <= 5; k++) {
			for (int i = 0; i < level; i++) {
				sx += dx[k];
				sy += dy[k];
				check();
				if (cnt == 10001) break;
			}
		}
		level++;
	}
}

int main() {
	int test, target;
	cin >> test;
	arr[sy][sx] = 1;
	number[1] = 1;
	cal();
	for (int t = 0; t < test; t++) {
		cin >> target;
		cout << number[target] << '\n';
	}
	system("pause");
	return 0;
}
