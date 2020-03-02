#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a, b, c, x, y, small,result = 0;
	cin >> a >> b >> c >> x >> y;
	small = a < b ? a : b;
	if (a + b < 2 * c) 		//반반을 아예 안시키는게 나은 경우
		result = a * x + b * y;
	else{
		if (x < y) {
			result += 2 * x*c;
			result += (y - x)*b;
			result = min(result, 2 * y*c);
		}
		else {
			result += 2 * y*c;
			result += (x - y)*a;
			result = min(result, 2 * x*c);
		}
	}
	cout << result;
	system("pause");
	return 0;
}