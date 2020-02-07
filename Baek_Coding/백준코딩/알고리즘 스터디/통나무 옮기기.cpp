#define MAX 10000
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
char arr[50][50];
bool check[50][50][2];
int num;
int result = MAX;
struct info {
	int x, y, lay, val;		//lay =0 : 누워져있음, lay=1: 세워져있음
};
info tmp;
queue<info> q;

void bfs() {
	int cx, cy,cv, nx, ny, cl;
	while (!q.empty()) {
		cx = q.front().x;
		cy = q.front().y;
		cl = q.front().lay;
		cv = q.front().val;
		q.pop();
		if (arr[cy][cx] == 'E') {
			if (cl==0) {
				if (arr[cy][cx + 1] == 'E' && arr[cy][cx - 1] == 'E') {
					result = min(result, cv);
					break;
				}
			}
			else {
				if (arr[cy + 1][cx] == 'E' && arr[cy - 1][cx] == 'E') {
					result = min(result, cv);
					break;
				}
			}
		}
		if (cl==0) {		//눕혀있는 상태
			if (cy - 1 >= 0 && arr[cy - 1][cx] != '1' && arr[cy - 1][cx - 1] != '1' && arr[cy - 1][cx + 1] != '1' && !check[cy - 1][cx][cl]) {
				check[cy - 1][cx][cl] = true;
				tmp.x = cx;
				tmp.y = cy - 1;
				tmp.lay = cl;
				tmp.val = cv + 1;
				q.push(tmp);
			}
			if (cy + 1 < num && arr[cy + 1][cx] != '1' && arr[cy + 1][cx - 1] != '1' && arr[cy + 1][cx + 1] != '1' && !check[cy + 1][cx][cl]) {
				check[cy + 1][cx][cl] = true;
				tmp.x = cx;
				tmp.y = cy + 1;
				tmp.lay = cl;
				tmp.val = cv + 1;
				q.push(tmp);
			}
			if (cx + 2 < num && arr[cy][cx + 2] != '1' && !check[cy][cx + 1][cl]) {
				check[cy][cx + 1][cl] = true;
				tmp.x = cx+1;
				tmp.y = cy;
				tmp.lay = cl;
				tmp.val = cv + 1;
				q.push(tmp);
			}
			if (cx - 2 >= 0 && arr[cy][cx - 2] != '1' && !check[cy][cx - 1][cl]) {
				check[cy][cx - 1][cl] = true;
				tmp.x = cx - 1;
				tmp.y = cy;
				tmp.lay = cl;
				tmp.val = cv + 1;
				q.push(tmp);
			}
		}
		else {		//세워진 상태
			if (cx - 1 >= 0 && arr[cy][cx - 1] != '1' && arr[cy - 1][cx - 1] != '1' && arr[cy + 1][cx - 1] != '1' && !check[cy][cx - 1][cl]) {
				check[cy][cx - 1][cl] = true;
				tmp.x = cx - 1;
				tmp.y = cy;
				tmp.lay = cl;
				tmp.val = cv + 1;
				q.push(tmp);
			}
			if (cx + 1 < num && arr[cy][cx + 1] != '1' && arr[cy - 1][cx + 1] != '1' && arr[cy + 1][cx + 1] != '1' && !check[cy][cx + 1][cl]) {
				check[cy][cx + 1][cl] = true;
				tmp.x = cx + 1;
				tmp.y = cy;
				tmp.lay = cl;
				tmp.val = cv + 1;
				q.push(tmp);
			}
			if (cy - 2 >= 0 && arr[cy - 2][cx] != '1' && !check[cy - 1][cx][cl]) {
				check[cy - 1][cx][cl] = true;
				tmp.x = cx;
				tmp.y = cy-1;
				tmp.lay = cl;
				tmp.val = cv + 1;
				q.push(tmp);
			}
			if (cy + 2 < num && arr[cy + 2][cx] != '1' && !check[cy + 1][cx][cl]) {
				check[cy + 1][cx][cl] = true;
				tmp.x = cx;
				tmp.y = cy+1;
				tmp.lay = cl;
				tmp.val = cv + 1;
				q.push(tmp);
			}
		}
		if (cx - 1 >= 0 && cx + 1 < num && cy - 1 >= 0 && cy + 1 < num &&  arr[cy - 1][cx] != '1' && arr[cy - 1][cx - 1] != '1' && arr[cy - 1][cx + 1] != '1' && arr[cy][cx - 1] != '1' && arr[cy][cx + 1] != '1' && arr[cy + 1][cx] != '1' && arr[cy + 1][cx - 1] != '1' && arr[cy + 1][cx + 1] != '1') {
			if (cl == 0 && check[cy][cx][1]) continue;
			else if (cl == 1 && check[cy][cx][0]) continue;			
			tmp.x = cx;
			tmp.y = cy;
			tmp.val = cv + 1;
			if(cl==0)	tmp.lay = 1;
			else tmp.lay = 0;
			check[cy][cx][tmp.lay] = true;
			q.push(tmp);
		}
	}
}

int main() {
	string str;
	cin >> num;
	int fx, cnt = 0, lay;

	for (int i = 0; i < num; i++) {
		cin >> str;
		for (int j = 0; j < num; j++) {
			arr[i][j] = str[j];
			if (arr[i][j] == 'B') {
				if (cnt == 0) 
					fx = j;				
				else if (cnt == 1) {
					if (fx == j) lay = 1;		//세워져있다
					else lay = 0;				//눕혀져있다	
					tmp.x = j;
					tmp.y = i;
					tmp.lay = lay;
					tmp.val = 0;
					q.push(tmp);
					check[i][j][lay] = true;
				}
				cnt++;				
			}
		}
	}
	bfs();
	if (result == MAX) cout << 0;
	else cout << result;
	system("pause");
	return 0;
}