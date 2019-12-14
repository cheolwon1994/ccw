#define MAX 1000000001
#include <iostream>
#include <algorithm>
using namespace std;
long long ans[10];		//자리수, 맨 뒤자리
long long num;

void cal(long long n, long long ten) {
	while (n > 0) {
		ans[n % 10] += ten;
		n /= 10;
	}
}
void solve(long long l, long long r, long long mul) {
	while(l%10!=0 && l<=r){
		cal(l, mul);
		l++;
	}
	while(r%10!=9 && r>=l){
		cal(r, mul);
		r -= 1;
	}
	if (l > r)
		return;
	else {
		long long much = (r / 10) - (l / 10) + 1;
		for (int i = 0; i < 10; i++)
			ans[i] += much * mul;
		solve((l / 10), (r / 10), mul * 10);
	}
}
int main() {
	cin >> num;
	solve(1, num, 1);
	for (int i = 0; i < 10; i++)
		cout << ans[i] << " ";
	system("pause");
	return 0;
}