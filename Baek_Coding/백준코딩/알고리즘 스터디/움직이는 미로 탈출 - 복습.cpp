#include <iostream>
#include <queue>
using namespace std;
int dx[8] = { 0,1,1,1,0,-1,-1,-1 };
int dy[8] = { -1,-1,0,1,1,1,0,-1 };
char arr[8][8],next_arr[8][8];
bool avail = true;
int wook = 0;
struct info {
	int x, y;
};
info tmp;

void mv_down() {
	for (int j = 0; j < 8; j++) {
		for (int i = 7; i > 0; i--)
			arr[i][j] = arr[i - 1][j];
		arr[0][j] = '.';
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			cin >> arr[i][j];
	arr[7][0] = 'w';
	for (int t = 0; t < 8; t++) {
		//초기화
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				next_arr[i][j] = '.';
		wook = 0;

		//욱제 이동
		for(int i=0;i<8;i++)
			for (int j = 0; j < 8; j++) {
				if (arr[i][j] == 'w') {
					for (int k = 0; k < 8; k++) {
						int nx = j + dx[k];
						int ny = i + dy[k];
						if (nx >= 0 && ny >= 0 && nx < 8 && ny < 8 && arr[ny][nx] != '#' && next_arr[ny][nx] != 'w') 
							next_arr[ny][nx] = 'w';						
					}
					next_arr[i][j] = 'w';
				}
			}
		//벽 이동
		for (int i = 0; i < 7; i++)
			for (int j = 0; j < 8; j++)
				if (arr[i][j] == '#')
					next_arr[i + 1][j] = '#';
		for(int i=0;i<8;i++)
			for (int j = 0; j < 8; j++) {
				arr[i][j] = next_arr[i][j];
				if (arr[i][j] == 'w')
					wook++;
			}
		if (wook == 0) {
			avail = false;
			break;
		}
	}
	if (avail) cout << 1;
	else cout << 0;
	return 0;
}