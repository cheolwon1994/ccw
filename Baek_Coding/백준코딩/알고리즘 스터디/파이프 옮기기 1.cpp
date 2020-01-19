#include <iostream>
#include <vector>
using namespace std;
int num, result = 0;
int arr[17][17];
int dx[3] = { 1,0,1 };
int dy[3] = { 0,1,1 };

void start(int y, int x, int dir) {
	if (y == num && x == num) {
		result++;
		return;
	}
	int nx, ny;
	for (int i = 0; i < 3; i++) {
		if (dir == 0 && i == 1)
			continue;
		if (dir == 1 && i == 0)
			continue;
		nx = x + dx[i];
		ny = y + dy[i];
		if (ny <= num && nx <= num) {
			if(i<2 && arr[ny][nx]!=1)
				start(ny, nx, i);
			if (i == 2 && arr[ny][nx]!=1 && arr[y+1][x] != 1 && arr[y][x+1] != 1) 
				start(ny, nx, i);			
		}
	}
}

int main() {
	cin >> num;
	for (int i = 1; i <= num; i++)
		for (int j = 1; j <= num; j++)
			cin >> arr[i][j];
	start(1, 2, 0);
	cout << result;
	system("pause");
	return 0;
}