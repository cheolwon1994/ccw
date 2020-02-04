#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int sx, sy, ex, ey;
int maxi = -1;
int len = 1;
/***************************************************************
2n * 2n + 1							(2n)(2n-1) +1
= 4ij+1				(1)				= 2i *(1-2j)+1
			(2)	       1	    (4)
					(3)
4n^2+2n+1							(2i+1)*(2j+1) = (2n+1)(2n+1)
= 2i(1-2j)+1						= 4ij+2i+2j+1
**************************************************************/
struct info {
	int x, y;
};
info tmp;
void cal_max_len() {
	int cnt = 0;
	int tt = maxi;
	while (tt > 0) {
		tt /= 10;
		cnt++;
	}
	len = max(len, cnt);
}
int cal_len(int num) {
	int cnt = 0;
	while (num > 0) {
		num /= 10;
		cnt++;
	}
	return cnt;
}
vector<info> v;
int main() {
	cin >> sy >> sx >> ey >> ex;
	tmp.x = sx;
	tmp.y = sy;
	v.push_back(tmp);
	tmp.y = ey;
	v.push_back(tmp);
	tmp.x = ex;
	v.push_back(tmp);
	tmp.y = sy;
	v.push_back(tmp);
	for (int k = 0; k < 4; k++) {
		int i = v[k].y;
		int j = v[k].x;
		if (i < 0 && i < j && j <= -i) 	maxi = max(maxi, 4 * i*i + 1 + (i - j));		
		else if (j < 0 && j <= i && i <= -j) maxi = max(maxi, 4 * j*j + 1 + (i - j));
		else if (i > 0 && -i < j && j <= i) maxi = max(maxi, 2 * i*(1 + 2 * i) + 1 + (i + j));
		else 	maxi = max(maxi, -2 * j*(1 - 2 * j) + 1 - (i + j));
	}
	cal_max_len();
	for (int i = sy; i <= ey; i++) {
		for (int j = sx; j <= ex; j++) {
			if (i < 0 && i < j && j <= -i) {		//À§ ±¸°£
				int tt = cal_len(4 * i*i + 1 + (i - j));
				for (int k = 0; k < len - tt; k++)
					cout << " ";
				cout << 4 * i*i + 1 + (i - j)<<" ";
			}
			else if (j < 0 && j <= i && i <= -j) {
				int tt = cal_len(4 * j*j + 1 + (i - j));
				for (int k = 0; k < len - tt; k++)
					cout << " ";
				cout << 4 * j*j + 1 + (i - j) << " ";
			}
			else if (i > 0 && -i < j && j <= i) {
				int tt = cal_len(2 * i*(1 + 2 * i) + 1 + (i + j));
				for (int k = 0; k < len - tt; k++)
					cout << " ";
				cout << 2 * i*(1 + 2 * i) + 1 + (i + j) << " ";
			}
			else {
				int tt = cal_len(-2 * j*(1 - 2 * j) + 1 - (i + j));
				for (int k = 0; k < len - tt; k++)
					cout << " ";
				cout << -2 * j*(1 - 2 * j) + 1 - (i + j) << " ";
			}
		}
		cout << endl;
	}
	system("pause");
	return 0;
}