#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
long long prim[1003002];
int arr[7];
void primary() {
	for (int i = 2; i <=1003002; i++)
		prim[i] = 1;
	
	for (int i = 2; i <= sqrt(1003002); i++) {
		if (prim[i]==0) // 이미 체크된 수의 배수는 확인하지 않는다
			continue;
		for (int j = i + i; j <= 1003002; j += i)  // i를 제외한 i의 배수들은 0으로 체크
			prim[j] = 0;		
	}
}

bool check(int idx) {
	int tt = idx;
	int cnt = 0;
	while (tt != 0) {
		tt /= 10;
		cnt++;
	}
	for (int i = cnt-1; i >=0; i--) {
		arr[i] = idx % 10;
		idx /= 10;
	}
	bool test = true;
	for (int i = 0; i < cnt / 2; i++) {
		if (arr[i] != arr[cnt - 1 - i]) {
			test = false;
			break;
		}
	}
	return test;
}

int main() {
	int num, result=-1;
	cin >> num;
	primary();
	bool find = false;
	for (int i = num;i< 1003002; i++) {
		if (prim[i]==0) continue;
		if (check(i)) {
			result = i;
			break;
		}		
	}
	cout << result;
	system("pause");
	return 0;
}