#include <iostream>
#include <string>
using namespace std;
int arr[9][9], mv, kx, ky, rx, ry, order;
int dx[8] = { 0,1,1,1,0,-1,-1,-1 };
int dy[8] = { -1,-1,0,1,1,1,0,-1 };

void go() {
	int nx = kx + dx[order];
	int ny = ky + dy[order];
	if (nx > 0 && ny > 0 && nx < 9 && ny < 9) {
		if (nx == rx && ny == ry) {		//돌과 겹치는 경우
			int nnx = nx + dx[order];
			int nny = ny + dy[order];
			if (nnx > 0 && nny > 0 && nnx < 9 && nny < 9) {
				rx = nnx;
				ry = nny;
				kx = nx;
				ky = ny;
			}
		}
		else {
			kx = nx;
			ky = ny;
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s1, s2, ss, ans;
	cin >> s1 >> s2 >> mv;
	kx = s1[0] - 'A' + 1;
	ky = 8 - (s1[1] - '0') + 1;
	rx = s2[0] - 'A' + 1;
	ry = 8 - (s2[1] - '0') + 1;
	for (int i = 0; i < mv; i++) {
		cin >> ss;
		if (ss == "T") order = 0;
		else if (ss == "RT") order = 1;
		else if (ss == "R") order = 2;
		else if (ss == "RB") order = 3;
		else if (ss == "B") order = 4;
		else if (ss == "LB") order = 5;
		else if (ss == "L") order = 6;
		else if (ss == "LT") order = 7;
		go();
	}
	ans = kx + 'A' - 1;
	ans += (9 - ky + '0');
	cout << ans << '\n';
	ans = rx + 'A' - 1;
	ans += (9 - ry + '0');
	cout << ans;
	return 0;
}