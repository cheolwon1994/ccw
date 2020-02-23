#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <string.h>
using namespace std;
struct info {
	int num;
	string s;
};
info tmp;
bool arr[10001];
char order[4] = { 'D','S','L','R' };

int cal(int num, int idx) {
	int temp = 0;
	if (idx == 0) 	//D
		temp = (2 * num) % 10000;
	else if (idx == 1)		//S
		temp = (num + 9999) % 10000;
	else if (idx == 2) {		//L
		int tt = num / 1000;
		temp = (num % 1000) * 10 + tt;
	}
	else if (idx == 3) {		//R
		int tt = num % 10;
		temp = tt * 1000 + num / 10;
	}
	return temp;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test, sx, tx;
	cin >> test;
	for (int t = 0; t < test; t++) {
		cin >> sx >> tx;
		for (int i = 0; i < 10001; i++)
			arr[i] = false;
		queue<info> q;
		tmp.num = sx;
		tmp.s = "";
		q.push(tmp);
		arr[sx] = true;
		while (!q.empty()) {
			int cnum = q.front().num;
			string cs = q.front().s;
			q.pop();
			if (cnum == tx) {
				cout << cs << '\n';
				break;
			}
			for (int i = 0; i < 4; i++) {
				int tnum = cal(cnum,i);
				if (!arr[tnum]) {
					arr[tnum] = true;
					tmp.num = tnum;
					tmp.s = cs + order[i];
					q.push(tmp);
				}
			}
		}
	}
	system("pause");
	return 0;
}