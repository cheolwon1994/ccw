#include <iostream>
#include <queue>
using namespace std;
int row, col;
char arr[26][26];
//4,10,15,6,2,8,12
char ans[16] = { '0','0','0','2','0','|','1','0','0','3','-','0','4','0','0','+' };
bool check[26][26] = { false, };
int tx, ty;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
struct info {
	int x, y;
};
info tmp;

int main() {
	cin >> row >> col;
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++) 
			cin >> arr[i][j];
	int nx, ny;
	bool avail = true;
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			if (arr[i][j] == '.') continue;
			else if (arr[i][j] == '-') {
				if (arr[i][j - 1] == '|' || arr[i][j - 1] == '3' || arr[i][j - 1] == '4' || arr[i][j - 1] == '.') {
					avail = false;
					tx = j - 1; ty = i;
					break;
				}
				if (arr[i][j + 1] == '|' || arr[i][j + 1] == '1' || arr[i][j + 1] == '2' || arr[i][j + 1] == '.') {
					avail = false;
					tx = j + 1; ty = i;
					break;
				}
			}
			else if (arr[i][j] == '|') {
				if (arr[i - 1][j] == '-' || arr[i - 1][j] == '2' || arr[i - 1][j] == '3' || arr[i-1][j]=='.') {
					avail = false;
					tx = j; ty = i - 1;
					break;
				}
				if (arr[i + 1][j] == '-' || arr[i + 1][j] == '1' || arr[i + 1][j] == '4' || arr[i + 1][j] == '.') {
					avail = false;
					tx = j; ty = i + 1;
					break;
				}
			}
			else if (arr[i][j] == '+') {
				if (arr[i - 1][j] == '-' || arr[i - 1][j] == '2' || arr[i - 1][j] == '3' || arr[i - 1][j] == '.') {
					avail = false;
					tx = j; ty = i - 1;
					break;
				}
				if (arr[i + 1][j] == '-' || arr[i + 1][j] == '1' || arr[i + 1][j] == '4' || arr[i + 1][j] == '.') {
					avail = false;
					tx = j; ty = i + 1;
					break;
				}
				if (arr[i][j - 1] == '|' || arr[i][j - 1] == '3' || arr[i][j - 1] == '4' || arr[i][j-1] == '.') {
					avail = false;
					tx = j-1; ty = i;
					break;
				}
				if (arr[i][j + 1] == '|' || arr[i][j + 1] == '1' || arr[i][j + 1] == '2' || arr[i][j+1] == '.') {
					avail = false;
					tx = j + 1; ty = i;
					break;
				}
			}
			else if (arr[i][j] == '1') {
				if (arr[i][j + 1] == '|' || arr[i][j + 1] == '1' || arr[i][j + 1] == '2' || arr[i][j+1] == '.') {
					avail = false;
					tx = j + 1; ty = i;
					break;
				}
				if (arr[i + 1][j] == '-' || arr[i + 1][j] == '1' || arr[i + 1][j] == '4' || arr[i + 1][j] == '.') {
					avail = false;
					tx = j; ty = i + 1;
					break;
				}
			}
			else if (arr[i][j] == '2') {
				if (arr[i - 1][j] == '-' || arr[i - 1][j] == '2' || arr[i - 1][j] == '3' || arr[i - 1][j] == '.') {
					avail = false;
					tx = j; ty = i - 1;
					break;
				}
				if (arr[i][j + 1] == '|' || arr[i][j + 1] == '1' || arr[i][j + 1] == '2' || arr[i][j+1] == '.') {
					avail = false;
					tx = j + 1; ty = i;
					break;
				}
			}
			else if (arr[i][j] == '3') {
				if (arr[i - 1][j] == '-' || arr[i - 1][j] == '2' || arr[i - 1][j] == '3' || arr[i - 1][j] == '.') {
					avail = false;
					tx = j; ty = i - 1;
					break;
				}
				if (arr[i][j - 1] == '|' || arr[i][j - 1] == '3' || arr[i][j - 1] == '4' || arr[i][j-1] == '.') {
					avail = false;
					tx = j - 1; ty = i;
					break;
				}
			}
			else if (arr[i][j] == '4') {
				if (arr[i][j - 1] == '|' || arr[i][j - 1] == '3' || arr[i][j - 1] == '4' || arr[i][j-1] == '.') {
					avail = false;
					tx = j - 1; ty = i;
					break;
				}
				if (arr[i + 1][j] == '-' || arr[i + 1][j] == '1' || arr[i + 1][j] == '4' || arr[i + 1][j] == '.') {
					avail = false;
					tx = j; ty = i + 1;
					break;
				}
			}
			
		}
		if (!avail)
			break;
	}
	int result = 0;
	if (ty - 1 > 0 && (arr[ty - 1][tx] == '|' || arr[ty - 1][tx] == '+' || arr[ty - 1][tx] == '1' || arr[ty - 1][tx] == '4'))
		result += 1;
	if (tx + 1 <= col && (arr[ty][tx + 1] == '-' || arr[ty][tx + 1] == '+' || arr[ty][tx + 1] == '3' || arr[ty][tx + 1] == '4'))
		result += 2;
	if (ty + 1 <= row && (arr[ty + 1][tx] == '|' || arr[ty + 1][tx] == '+' || arr[ty + 1][tx] == '2' || arr[ty + 1][tx] == '3'))
		result += 4;
	if (tx - 1 > 0 && (arr[ty][tx - 1] == '-' || arr[ty][tx - 1] == '+' || arr[ty][tx - 1] == '1' || arr[ty][tx - 1] == '2'))
		result += 8;
	cout << ty << " " << tx <<" " << ans[result];
	system("pause");
	return 0;
}