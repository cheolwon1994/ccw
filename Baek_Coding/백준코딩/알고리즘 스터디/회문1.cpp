#include <iostream>
#include <string>
using namespace std;
int dx[2] = { 0,1 };
int dy[2] = { 1,0 };
int result, num;
char arr[8][8];

void start(int y, int x, int dir) {
	bool avail = true;
	for (int k = 0; k < num / 2; k++) {
		if (arr[y + dy[dir] * k][x + dx[dir] * k] != arr[y + dy[dir] * (num - 1 - k)][x + dx[dir] * (num - 1 - k)]) {
			avail = false;
			break;
		}
	}
	if (avail)
		result++;	
}

int main() {
	for (int t = 1; t <= 10; t++) {
		result = 0;
		cin >> num;
		string str;
		for (int i = 0; i < 8; i++) {
			cin >> str;
			for (int j = 0; j < 8; j++)
				arr[i][j] = str[j];
		}
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				for (int k = 0; k < 2; k++) {
					if (k == 0 && i + num <= 8)
						start(i, j, k);
					if (k == 1 && j + num <= 8)
						start(i, j, k);
				}
			}
		}	
		cout << "#" << t << " " << result << endl;
	}
	system("pause");
	return 0;
}