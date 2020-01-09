#include <iostream>
using namespace std;
int num, f, s, f_idx, s_idx;
int arr[3] = { 1,2,3 };

int main() {
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> f >> s;
		for (int i = 0; i < 3; i++) {
			if (arr[i] == f)
				f_idx = i;
			else if (arr[i] == s)
				s_idx = i;
		}
		arr[f_idx] = s;
		arr[s_idx] = f;
	}
	cout << arr[0];
	system("pause");
	return 0;
}