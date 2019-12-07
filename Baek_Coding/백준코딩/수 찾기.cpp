#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;
int first[100000];
int main() {
	int num, num2, tmp;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
		scanf("%d", &first[i]);
	sort(first, first+num);
	scanf("%d", &num2);
	bool flag = false;
	for (int i = 0; i < num2; i++) {
		scanf("%d", &tmp);
		flag = false;
		int low = 0;
		int high = num - 1;
		while (low <= high) {
			int mid = low + (high - low) / 2;
			if (tmp == first[mid]) {
				flag = true;
				break;
			}
			else if (tmp < first[mid])
				high = mid - 1;
			else if (tmp > first[mid])
				low = mid + 1;
		}
		if (flag)
			printf("%d\n",1);
		else
			printf("%d\n", 0);
	}	
	system("pause");
	return 0;
}