#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int row, col, num, sr, sc;
int arr[40][40];
int sticker[100][10][10];
bool avail;

struct info {
	int row, col;
};
info tmp;
vector<info> s;

void rotate(int s_num) {		//90도 회전하는 함수, 스티커 번호
	int dup[10][10];
	int r = s[s_num].row;
	int c = s[s_num].col;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++) {
			dup[j][r - 1 - i] = sticker[s_num][i][j];
			sticker[s_num][i][j] = 0;
		}
	for (int i = 0; i < c; i++)
		for (int j = 0; j < r; j++)
			sticker[s_num][i][j] = dup[i][j];
	s[s_num].row = c;
	s[s_num].col = r;
}

void check(int s_num) {		//스티커를 붙일 수 있는지 확인 하는 함수, 스티커 번호
	int sr = s[s_num].row;
	int sc = s[s_num].col;
	for (int i = 0; i <= row - sr; i++) {
		for (int j = 0; j <= col - sc; j++) {
			bool add = true;
			for (int k = 0; k < sr; k++) {
				for (int m = 0; m < sc; m++) {
					if (sticker[s_num][k][m] == 1 && arr[i + k][j + m] != 0) {
						add = false;
						break;
					}
				}
				if (!add) break;
			}
			if (add) {
				avail = true;
				for (int k = 0; k < sr; k++)
					for (int m = 0; m < sc; m++)
						if (sticker[s_num][k][m] == 1)
							arr[i + k][j + m] = 1;
				break;
			}
		}
		if (avail) 	break;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> row >> col >> num;
	for (int k = 0; k < num; k++) {
		cin >> sr >> sc;
		tmp.col = sc;
		tmp.row = sr;
		s.push_back(tmp);
		for (int i = 0; i < sr; i++)
			for (int j = 0; j < sc; j++)
				cin >> sticker[k][i][j];
	}
	for (int k = 0; k < num; k++) {
		avail = false;		//붙일 수 있는지 여부
		check(k);				//현재 상태로 붙일 수 있는가
		if (avail) continue;
		for (int i = 0; i < 3; i++) {
			rotate(k);			//90도 회전
			check(k);
			if (avail) break;		//붙일 수 있다면 붙이고 다음 스티커	
		}
	}
	int result = 0;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			if (arr[i][j] == 1)
				result++;
	cout << result;
	return 0;
}