#include <iostream>
#include <algorithm>
#include <deque>
#include <string.h>
using namespace std;
int test;
int num;
int arr[100001];
int check[100001];
int result;
deque<int> dq;
//1 ->2, 2,3,4팀인 경우 생각해줘야됨 2->3, 3->4, 4->2

int main() {
	cin >> test;
	int cv;
	for (int t = 0; t < test; t++) {
		cin >> num;
		result = 0;
		for (int i = 1; i <= num; i++)
			cin >> arr[i];
		memset(check, 0, sizeof(check));
		for (int i = 1; i <= num; i++) {
			if (check[i] != 1) {
				if (arr[i] == i) {		//1인 팀
					check[i] = 1;
					continue;
				}
				else {		//다른 팀원을 가르키는 경우
					bool flag = false;
					dq.push_back(i);
					check[i] = 1;
					while (!dq.empty()) {
						cv = dq[dq.size() - 1];
						if (check[arr[cv]] == 1) {		//이미 팀이거나, 팀을 구성중이거나, 혼자서 하는 경우
							while (!dq.empty()) {
								if (dq[0] == arr[cv]) {		//이뤄지는 경우
									flag = true;
									break;
								}
								else {
									dq.pop_front();
									result++;
								}
							}
						}
						else if (check[arr[cv]] != 1) {
							check[arr[cv]] = 1;
							dq.push_back(arr[cv]);
						}
						if (flag)
							break;
					}
					if (!dq.empty())
						dq.clear();
				}
			}
		}
		cout << result << endl;
	}

	system("pause");
	return 0;
}