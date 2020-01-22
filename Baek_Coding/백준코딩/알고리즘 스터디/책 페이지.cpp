#include <iostream>
using namespace std;
int answer[10] = { 0, };
long long finish, start, temp;

void solve(int tt) {
	for (int j = tt; j > 0; j /= 10) 
		answer[j % 10]+=temp;	
}

int main() {
	cin >> finish;
	temp = 1;
	start = 1;
	while (start <= finish) {
		while (start % 10 != 0 && start <= finish) {
			solve(start);
			start++;
		}
		if (start > finish)
			break;
		while (finish % 10 != 9 && start <= finish) {
			solve(finish);
			finish--;
		}
		long long sub = (finish / 10) - (start / 10) + 1;
		for (int i = 0; i < 10; i++)
			answer[i] += (sub * temp);
		temp *= 10;
		start /= 10;
		finish /= 10;
	}
	for (int i = 0; i < 10; i++)
		cout << answer[i] << " ";
	system("pause");
	return 0;
}