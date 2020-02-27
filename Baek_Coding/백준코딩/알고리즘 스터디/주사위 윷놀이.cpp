#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[6][21] = { {0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40},
{10,13,16,19,25},
{20,22,24,25},
{30,28,27,26,25},
{25,30,35,40},
{40} };
int order[10];
int player[10];
int result = 0;

void play() {
	int t_result = 0;
	bool err = false;
	int row[4] = { 0,0,0,0 };
	int col[4] = { 0,0,0,0 };
	for (int i = 0; i < 10; i++) {
		int cidx = player[i];
		int cval = order[i];
		int cr = row[cidx];
		int cc = col[cidx];
		int nr, nc;
		if (cr == -1 && cc == -1) continue;		//이미 도착지점인 경우
		if (cr == 0) {
			if (cc + cval >= 21) {	//도착지점을 넘어가는 경우
				row[cidx] = -1;
				col[cidx] = -1;
				continue;
			}
			if (cc+cval == 5) {		//9시 방향 10에 도착한 경우
				nr = 1;
				nc = 0;
			}
			else if (cc+cval == 10) {		//6시 방향 20에 도착한 경우
				nr = 2;
				nc = 0;
			}
			else if (cc+ cval == 15) {		//3시 방향 30에 도착한 경우
				nr = 3;
				nc = 0;
			}
			else if (cc+cval == 20) {		//12시 방향 40에 도착한 경우
				nr = 5;
				nc = 0;
			}
			else {
				nr = cr;
				nc = cc + cval;
			}
		}
		else if (cr == 1 || cr == 3) {
			if (cc + cval == 8) {		//도착지점에 도착하는 경우
				row[cidx] = -1;
				col[cidx] = -1;
				continue;
			}
			else if (cc + cval == 7) {		//40에 도착하는 경우
				nr = 5;
				nc = 0;
			}
			else if (3 < cc + cval && cc + cval < 7) {		//25~35사이에 도착하는 경우
				nr = 4;
				nc = cc + cval - 4;
			}
			else {
				nr = cr;
				nc = cc + cval;
			}
		}
		else if (cr == 2) {
			if (cc + cval == 7) {		//도착지점에 도착하는 경우
				row[cidx] = -1;
				col[cidx] = -1;
				continue;
			}
			else if (cc + cval == 6) {		//40에 도착하는 경우
				nr = 5;
				nc = 0;
			}
			else if (2 < cc + cval && cc + cval < 6) {		//25~35사이에 도착하는 경우
				nr = 4;
				nc = cc + cval - 3;
			}
			else {
				nr = cr;
				nc = cc + cval;
			}
		}
		else if (cr == 4) {	
			if (cc + cval >= 4) {		//도착지점 넘어가는 경우
				row[cidx] = -1;
				col[cidx] = -1;
				continue;
			}
			else if (cc+cval == 3) {		//40에 도착하는 경우
				nr = 5;
				nc = 0;
			}
			else {			//30이나 35에 안착하는 경우
				nr = cr;
				nc = cc + cval;
			}
		}
		else if (cr == 5) {
			row[cidx] = -1;
			col[cidx] = -1;
			continue;
		}
		for (int j = 0; j < 4; j++) {
			if (cidx == j) continue;
			if (row[j] == nr && col[j] == nc) {
				err = true;
				break;
			}
		}
		if (err)	break;
		row[cidx] = nr;
		col[cidx] = nc;
		t_result += arr[nr][nc];
	}
	if (!err) 
		result = max(result, t_result);
}

void set_player(int cnt) {
	if (cnt == 10) {
		play();
		return;
	}
	for (int i = 0; i <min(cnt+1,4); i++) {
		player[cnt] = i;
		set_player(cnt + 1);
		player[cnt] = 0;
	}
}

int main() {
	for (int i = 0; i < 10; i++)
		cin >> order[i];
	set_player(0);
	cout << result;
	system("pause");
	return 0;
}
