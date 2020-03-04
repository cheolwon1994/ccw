#include <iostream>
using namespace std;
int main() {
	int test;
	cin >> test;
	bool arr[100][100] = { false, };
	for (int i = 0; i < test; i++) {
		int s, e;
		cin >> s >> e;
		for (int j = s; j < s + 10; j++)
			for (int k = e; k < e + 10; k++)
				arr[j][k] = true;
	}
	int result = 0;
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			if (arr[i][j]) result++;
	cout << result;
	system("pause");
	return 0;
}