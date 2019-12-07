#define MAX 987654321
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int arr[100][100];
int check[100][100];
int num, result, tmp, idx;
int dx[2] = { 1,-1 };
int dy[2] = { 0,0 };
int len = 100;
void flow(int y, int x, int val) {
	int cy, cx, cv;
	cy = y;
	cx = x;
	cv = val;
	if (cy == len - 1) {
		tmp = val;
		//cout << tmp;
		return;
	}
	bool flag = false;
	int ny, nx, nd, ni;
	//옆으로 갈 수 있는지 확인
	for (int i = 0; i < 2; i++) {
		ny = cy + dy[i];
		nx = cx + dx[i];
		if (nx >= 0 && nx < len) {
			if (arr[ny][nx] == 1 && check[ny][nx] != 1) {
				//얼마만큼 이동하는지
				nd = 0;
				ni = i;
				nx = cx;
				for (int j = 0;; j++) {
					nx += dx[i];
					if (nx == 0 || nx == len - 1) {
						nd++;
						break;
					}
					if (arr[ny][nx] == 0)
						break;
					else {
						nd++;
						check[ny][nx] = 1;
					}
				}
				flag = true;
				break;
			}
		}
	}
	//옆으로 갈 수 있다면
	if (flag) {
		if (ni == 0)
			flow(ny, cx + nd, cv + nd);
		else
			flow(ny, cx - nd, cv + nd);
	}
	//옆으로 갈 수 없다면
	else if (!flag) {
		check[cy + 1][cx] = 1;
		flow(cy + 1, cx, cv + 1);
	}
}

int main() {
	for (int t = 1; t < 11; t++) {
		cin >> num;
		result = MAX;
		idx = 0;
		for (int i = 0; i < len; i++)
			for (int j = 0; j < len; j++)
				cin >> arr[i][j];
		for (int i = 0; i < len; i++) {
			if (arr[0][i] == 1) {
				//넣는다
				for (int j = 0; j < len; j++)
					memset(check[j], 0, sizeof(check[j]));
				check[0][i] = 1;
				flow(0, i, 1);
				//비교한다
				if (result > tmp) {
					result = tmp;
					idx = i;
				}
			}
		}
		cout << "#" << t << " " << idx << endl;
	}
	system("pause");
	return 0;
}