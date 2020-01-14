#include <iostream>
#include <algorithm>
using namespace std;
long long A[4000];
long long B[4000];
long long C[4000];
long long D[4000];
long long temp[16000000];
long long temp2[16000000];

int main() {
	int num, cnt = 0;
	long long tt, result = 0;
	cin >> num;
	for (int i = 0; i < num; i++){
			cin >> A[i];
			cin >> B[i];
			cin >> C[i];
			cin >> D[i];
	}
	for (int i = 0; i < num; i++) 
		for (int j = 0; j < num; j++) {
			temp[cnt] = A[i] + B[j];
			temp2[cnt] = C[i] + D[j];
			cnt++;
		}
	sort(temp, temp + cnt);
	for (int i = 0; i < cnt; i++) {
		auto range = equal_range(temp, temp + cnt, (-1*temp2[i]));
		result += (range.second - range.first);
	}
	cout << result;
	system("pause");
	return 0;
}