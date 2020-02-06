#include <iostream>
#include <algorithm>
using namespace std;
bool arr[101][101];
int main() {
	int test, result = 0;;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		int x, y;
		cin >> x >> y;
		for(int i=y;i<y+10;i++)
			for (int j = x; j < x + 10; j++) {
				if (!arr[i][j]) {
					arr[i][j] = true;
					result++;
				}
			}
	}
	cout << result;
	system("pause");
	return 0;
}