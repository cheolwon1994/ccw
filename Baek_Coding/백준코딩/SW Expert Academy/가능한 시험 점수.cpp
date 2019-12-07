#define CRT_NO_SECURE_WARNINGS
#include <algorithm>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
int arr[100];
int check[100];
int num;
int tot = 0;
int flag[10001];
vector <int> v;

void select() {
	v.push_back(0);
	flag[0] = 1;
	for (int i = 0; i < num; i++) {
		int add_num = arr[i];
		int size = v.size();
		for (int j = 0; j < size; j++) {
			int sum_num = v[j];
			if (!flag[sum_num + add_num]) {
				flag[sum_num + add_num] = 1;
				v.push_back(sum_num + add_num);
			}
		}
	}
}
int main() {
	int test, temp, size;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		cin >> num;
		v.clear();
		memset(flag, 0, sizeof(flag));
		tot = 0;
		for (int i = 0; i < num; i++) 
			cin >> arr[i];		
		select();
		cout << "#" << i << " " << v.size() << endl;
	}
	system("PAUSE");
	return 0;
}