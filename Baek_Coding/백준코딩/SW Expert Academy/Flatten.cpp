#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int arr[100];
int test, result;

void find() {
	int maxi, mini, maxi_val, mini_val;
	for (int j = 0; j <= test; j++) {
		maxi_val = arr[0];
		mini_val = arr[0];
		mini = 0;
		maxi = 0;
		for (int i = 1; i < 100; i++) {
			if (mini_val > arr[i]) {
				mini_val = arr[i];
				mini = i;
			}
			if (maxi_val < arr[i]) {
				maxi_val = arr[i];
				maxi = i;
			}
		}
		if (j != test) {
			arr[maxi] -= 1;
			arr[mini] += 1;
		}
		else 
			result = maxi_val - mini_val;			
	}

}
int main() {
	for (int t = 1; t <= 10; t++) {
		cin >> test;
		result = 0;
		memset(arr, 0, sizeof(arr));
		for (int i = 0; i < 100; i++)
			cin >> arr[i];
		find();
		cout << "#" << t << " " << result << endl;
	}
	system("pause");
	return 0;
}