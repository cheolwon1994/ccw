#include <iostream>
using namespace std;
int x[4], y[4];

int ccw(int a, int b, int c) {
	int da[2] = { y[b] - y[a],x[b] - x[a] };
	int db[2] = { y[c] - y[a],x[c] - x[a] };
	int temp = da[1] * db[0] - da[0] * db[1];
	if (temp < 0) return -1;
	else if(temp>0) return 1;
	else return 0;
}

int main() {
	int dx, dy, result;
	for (int i = 0; i < 4; i++) 
		cin >> x[i] >> y[i];
	result = ccw(0, 1, 2);
	result *= ccw(0, 1, 3);
	(result == -1) ? cout << 1 : cout << 0;
	return 0;
}