#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int test, row, col, tx, ty;

	cin >> test;
	for (int t = 0; t < test; t++) {
		cin >> row >> col >> ty >> tx;		
		ty += 1; tx += 1;
		int x1 = col - tx;
		int x2 = tx - 1;
		long long mx = x1 > x2 ? x1:x2;
		long long result = mx * row;
		int y1 = row - ty;
		int y2 = ty - 1;
		long long my = y1 > y2 ? y1 : y2;
		result = max(result, my*col);
		cout << result << '\n';
	}
	return 0;
}