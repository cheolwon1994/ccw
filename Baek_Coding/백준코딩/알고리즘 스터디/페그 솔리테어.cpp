#include <iostream>
#include <algorithm>
using namespace std;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
char arr[5][9];
int result, pin;

void back_tracking() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) {
			if(arr[i][j]=='o'){
				for (int k = 0; k < 4; k++) {
					int nx = j + dx[k];
					int ny = i + dy[k];
					if (nx >= 0 && ny >= 0 && nx < 9 && ny < 5 && arr[ny][nx] == 'o') {
						int nnx = nx + dx[k];
						int nny = ny + dy[k];
						if (nnx >= 0 && nny >= 0 && nnx < 9 && nny < 5 && arr[nny][nnx] == '.') {
							arr[nny][nnx] = 'o';
							arr[ny][nx] = '.';
							arr[i][j] = '.';
							back_tracking();
							arr[nny][nnx] = '.';
							arr[ny][nx] = 'o';
							arr[i][j] = 'o';
						}
					}
				}
			}
		}
	}
	int temp = 0;
	for (int i = 0; i < 5; i++) 
		for (int j = 0; j < 9; j++) 
			if (arr[i][j] == 'o') 
				temp++;
	result = min(result, temp);
}

int main() {
	int test;
	cin >> test;
	for (int t = 0; t < test; t++) {
		result = 9;
		pin = 0;
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 9; j++) {
				cin >> arr[i][j];
				if (arr[i][j] == 'o') pin++;
			}
		back_tracking();
		cout << result << " " << pin - result << '\n';
	}
	system("pause");
	return 0;
}