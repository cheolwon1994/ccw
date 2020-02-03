#include <iostream>
#include <algorithm>
using namespace std;
int sx, sy, ex, ey;
/****
2n * 2n + 1	-(i+j)		(2n)(2n-1) +1
= 4ij+1		(1)		= 2i *(1-2j)+1
+(i-j)	(2)	       1	    (4) 	+(j-i)

		(3)
4n^2+2n+1	+(i+j)		(2i+1)*(2j+1) = (2n+1)(2n+1)
= 2i(1-2j)+1				4ij+2i+2j+1

****/
int main() {
	cin >> sy >> sx >> ey >> ex;
	int mini;
	for (int i = sy; i <= ey; i++) {
		for (int j = sx; j <= ex; j++) {
			mini = min(i, j);

		}
	}
	system("pause");
	return 0;
}