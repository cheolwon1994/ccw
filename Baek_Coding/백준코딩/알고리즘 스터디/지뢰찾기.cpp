#include <iostream>
#include <string>
using namespace std;
int arr[100][100];		//Áö·Ú°¡ ¾ø´Â Ä­:0, Áö·Ú°¡ ÀÖ´Â Ä­: 9
int dx[8] = { 0,1,1,1,0,-1,-1,-1 };
int dy[8] = { -1,-1,0,1,1,1,0,-1 };

int main() {
	int num;
	string str;
	char c;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> str;
		for (int j = 0; j < num; j++) {
			c = str[j];
			if (c == '#') arr[i][j] = -1;
			else arr[i][j] = str[j] - '0';			
		}
	}
	int result = 0;
	if (num>2) {
		result = (num - 2)*(num - 2);
		for (int i = 1; i < num - 1; i++) {
			for (int j = 1; j < num - 1; j++) {
				if (arr[i][j] == -1) {
					bool mine = true;
					for (int k = 0; k < 8; k++) {
						int nx = j + dx[k];
						int ny = i + dy[k];
						if (arr[ny][nx] == 0) {
							mine = false;
							result--;
							break;
						}
					}
					if (mine) {
						for (int k = 0; k < 8; k++) {
							int nx = j + dx[k];
							int ny = i + dy[k];
							if (0 < arr[ny][nx] && arr[ny][nx] < 9)
								arr[ny][nx]--;
						}
					}
				}
			}
		}
	}
	cout << result;
	system("pause");
	return 0;
}