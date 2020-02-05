#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int num, loc, maxi = 1;
int tt, tmp;
int main() {
	cin >> num >> loc;
	for (int i = 0; i < num; i++) {
		cin >> tt;
		if (i == 0) {maxi = abs(loc - tt); continue;}
		tt = abs(loc - tt);
		while (tt != 0) {
			tmp = maxi % tt;
			maxi = tt;
			tt = tmp;
		}
	}
	cout << maxi;
	system("pause");
	return 0;
}