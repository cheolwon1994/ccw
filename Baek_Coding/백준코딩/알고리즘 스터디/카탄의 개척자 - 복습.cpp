#include <iostream>
using namespace std;
int num, t = 2;
int number[10001];		//n번 타일에 어떤 숫자가 저장되어 있는가
int freq[6] = { 0,1,0,0,0,0 };		//1~5번 몇번 사용했는지 저장
int arr[601][301];
int dx[6] = { 0,-1,-1,0,1,1 };
int dy[6] = { -2,-1,1,2,1,-1 };

void check(int y, int x) {
	bool used[6] = { false, };	//인접한곳에 사용된 숫자면 true,아니면 false
	for (int i = 0; i < 6; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (arr[ny][nx] != 0)
			used[arr[ny][nx]] = true;
	}
	int mini = 10001, idx;
	for (int i = 1; i < 6; i++) {
		if (!used[i]) {
			if (mini > freq[i]) {
				mini = freq[i];
				idx = i;
			}
		}
	}
	arr[y][x] = idx;
	number[t++] = idx;
	freq[idx]++;
}

void cal() {
	int layer = 1, x = 150, y = 300;
	arr[y][x] = 1;
	number[1] = 1;
	while (t <= 10000) {
		y += dy[5];
		x += dx[5];
		check(y, x);
		if (t > 10000) break;
		for (int i = 0; i < layer - 1; i++) {
			y += dy[0];
			x += dx[0];
			check(y, x);
			if (t > 10000) break;
		}
		for (int i = 1; i < 6; i++) {
			for (int j = 0; j < layer; j++) {
				y += dy[i];
				x += dx[i];
				check(y, x);
				if (t > 10000) break;
			}
			if (t > 10000) break;
		}
		if (t > 10000) break;
		layer++;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int test;
	cin >> test;
	cal();
	for (int t = 0; t < test; t++) {
		cin >> num;
		cout << number[num] << '\n';
	}
	return 0;
}