#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
int num, arr[20];
set<int> s;

void cal(int idx, int sum) {
	if(idx == num) return;
	sum += arr[idx];
	if (s.find(sum) == s.end())		s.insert(sum);
	cal(idx + 1, sum);		//포함 하는 경우
	cal(idx + 1, sum-arr[idx]);		//포함 안하는 경우
}

int main() {
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> arr[i];
		s.insert(arr[i]);
	}
	cal(0, 0);
	set<int> ::iterator it1 = s.begin(), it2;
	if (*it1 != 1) cout << 1;
	else {
		bool avail = false;
		while (1) {
			it2 = ++it1;
			if (it2 == s.end()) break;
			--it1;
			int a = *it2;
			int b = *it1;
			if (a - b != 1) {
				cout << b + 1;
				avail = true;
				break;
			}
			else
				it1 = it2;
		}
		if (!avail) {
			it2 = s.end();
			--it2;
			int result = *it2;
			cout << result + 1;
		}
	}
	system("pause");
	return 0;
}