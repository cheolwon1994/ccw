#include <iostream>
using namespace std;
char arr[8][8];		//. : 이동가능 #: 벽 ,w: 욱제
char next_arr[8][8];
int dx[8] = { 0,1,1,1,0,-1,-1,-1 };
int dy[8] = { -1,-1,0,1,1,1,0,-1 };

int main() {
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++) 
			cin >> arr[i][j];
	bool avail = true;
	int remain;
	arr[7][0] = 'w';
	int cnt = 8;
	while (cnt) {
		remain = 0;
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				next_arr[i][j] = '.';
		for(int i=0;i<8;i++)
			for (int j = 0; j < 8; j++) {
				if (arr[i][j] == 'w') {
					for (int k = 0; k < 8; k++) {
						int nx = j + dx[k];
						int ny = i + dy[k];
						if (nx >= 0 && ny >= 0 && nx < 8 && ny < 8 && arr[ny][nx] != '#' && next_arr[ny][nx]!='w')
							next_arr[ny][nx] = 'w';						
					}
					next_arr[i][j] = 'w';
				}
			}
		for (int i = 0; i < 7; i++) 
			for (int j = 0; j < 8; j++) 
				if (arr[i][j] == '#') 
					next_arr[i + 1][j] = '#';
				
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++) {
				arr[i][j] = next_arr[i][j];
				if (arr[i][j] == 'w')
					remain++;
			}
		if (remain == 0) 
			break;
		/*cout << endl;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++)
				cout << arr[i][j];
			cout << endl;
		}*/
		cnt--;
	}
	if (remain == 0) cout << 0;
	else cout << 1;
	system("pause");
	return 0;
}