#define CRT_NO_SECURE_WARNINGS
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;
long long arr[100000];
int num, people;
long long mini,maxi;
long long result = 0;

int main() {
	int test;
	cin >> test;
	for (int k = 1; k <= test; k++) {
		cin >> num >> people;

		mini = 1;
		maxi = 0;
		for (int i = 0; i < num; i++) {
			cin >> arr[i];
			maxi = max(maxi, arr[i]);
		}
		maxi *= people;
		result = maxi;
		while (mini <= maxi) {
			long long mid = (mini + maxi) / 2;
			long long total = 0;
			for (int i = 0; i < num; i++)			
				total += mid / arr[i];		
			if (total < people) 
				mini = mid + 1;			
			else {
				result = min(result, mid);
				maxi = mid - 1;
			}
		}
		cout << "#" << k << " " << result << endl;
	}
	system("PAUSE");
	return 0;
}