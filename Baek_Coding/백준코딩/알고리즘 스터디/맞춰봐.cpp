#include <iostream>
using namespace std;
int num, arr[11], sum[11]; //길이, 정답, 1~idx까지의 합
char result[11][11];
bool finish = false;

int cal(int idx) {
	for (int r = 1; r < idx; r++) {
		if (result[r][idx] == '+' && sum[idx] <= sum[r - 1]) return 0;
		if (result[r][idx] == '-' && sum[idx] >= sum[r - 1]) return 0;
		if (result[r][idx] == '0' && sum[idx] != sum[r - 1]) return 0;
	}
	return 1;
}

void back_tracking(int idx) {
	if (finish) return;
	if (idx > num) {
		finish = true;
		for (int i = 1; i <= num; i++)
			cout << arr[i] << " ";
		return;
	}
	//우선 숫자부터 대입
	if (result[idx][idx] == '0') {
		arr[idx] = 0;
		sum[idx] = sum[idx - 1];
		back_tracking(idx + 1);
	}	
	else {
		int s = 1;
		if (result[idx][idx] == '-')
			s = -1;
		for (int i = 1; i <= 10; i++) {
			arr[idx] = i * s;
			sum[idx] = sum[idx - 1] + arr[idx];
			if (cal(idx))
				back_tracking(idx + 1);
		}
	}
}

int main() {
	cin >> num;
	for (int j = 1; j <= num; j++) 
		for (int i = j; i <= num; i++)
			cin >> result[j][i];
	back_tracking(1);
	system("pause");
	return 0;
}