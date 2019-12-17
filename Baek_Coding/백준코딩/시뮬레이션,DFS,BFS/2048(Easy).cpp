#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
int num;
int arr[21][21];
int dup[21][21];
int dir[5];		//위,오른,아래,왼
long long result = 0;

void move() {
	deque<int> dq;
	bool flag;
	for (int t = 0; t < 5; t++) {
		if (dir[t] == 0) {		//위로
			for (int i = 0; i < num; i++) {
				flag = false;
				for (int j = 0; j < num; j++) {	//arr[0][0] arr[1][0]  arr[2][0] 순으로
					if (arr[j][i] == 0)
						continue;
					else {
						if (dq.empty())
							dq.push_back(arr[j][i]);
						else {
							if (dq[dq.size() - 1] == arr[j][i] && flag == false) { //같은거 처음으로 나옴
								dq[dq.size() - 1] *= 2;
								flag = true;
							}
							else {
								dq.push_back(arr[j][i]);
								flag = false;
							}
						}
					}
				}
				for (int j = 0; j < num; j++)
					arr[j][i] = 0;
				for (int j = 0; j < dq.size(); j++)
					arr[j][i] = dq[j];
				dq.clear();
			}
		}
		else if (dir[t] == 1) {		//arr[0][num-1]  arr[0][num-2] ...arr[0][0]순으로
			for (int i = 0; i < num; i++) {
				flag = false;
				for (int j = num - 1; j >= 0; j--) {
					if (arr[i][j] == 0)
						continue;
					else {
						if (dq.empty())
							dq.push_back(arr[i][j]);
						else {
							if (dq[dq.size() - 1] == arr[i][j] && flag == false) {
								flag = true;
								dq[dq.size() - 1] *= 2;
							}
							else {
								dq.push_back(arr[i][j]);
								flag = false;
							}
						}
					}
				}
				int cnt = 0;
				for (int j = 0; j < num; j++)
					arr[i][j] = 0;
				for (int j = 1; j <= dq.size(); j++)
					arr[i][num - j] = dq[j - 1];
				dq.clear();
			}
		}
		else if (dir[t] == 2) {		//arr[num-1][0]  arr[num-2][0] ... arr[0][0]순으로
			for (int i = 0; i < num; i++) {
				flag = false;
				for (int j = num - 1; j >= 0; j--) {
					if (arr[j][i] == 0)
						continue;
					else {
						if (dq.empty())
							dq.push_back(arr[j][i]);
						else {
							if (dq[dq.size() - 1] == arr[j][i] && flag == false) {
								flag = true;
								dq[dq.size() - 1] *= 2;
							}
							else {
								dq.push_back(arr[j][i]);
								flag = false;
							}
						}
					}
				}
				int cnt = 0;
				for (int j = 0; j < num; j++)
					arr[j][i] = 0;
				for (int j = 1; j <= dq.size(); j++)
					arr[num - j][i] = dq[j - 1];
				dq.clear();
			}
		}
		else if (dir[t] == 3) {		//arr[0][0] arr[0][1] ... arr[0][num-1]순으로
			for (int i = 0; i < num; i++) {
				flag = false;
				for (int j = 0; j < num; j++) {
					if (arr[i][j] == 0)
						continue;
					if (dq.empty())
						dq.push_back(arr[i][j]);
					else {
						if (dq[dq.size() - 1] == arr[i][j] && flag == false) {
							flag = true;
							dq[dq.size() - 1] *= 2;
						}
						else {
							dq.push_back(arr[i][j]);
							flag = false;
						}
					}
				}
				for (int j = 0; j < num; j++)
					arr[i][j] = 0;
				for (int j = 0; j < dq.size(); j++)
					arr[i][j] = dq[j];
				dq.clear();
			}
		}
		long long tmp = 0;
		for (int i = 0; i < num; i++) {
			for (int j = 0; j < num; j++) {
				if (arr[i][j] > tmp)
					tmp = arr[i][j];
			}
		}
		if (result < tmp) 
			result = tmp;		
	}
}

void set_dir(int a) {
	if (a == 5) {
		for (int i = 0; i < num; i++)
			for (int j = 0; j < num; j++)
				arr[i][j] = dup[i][j];
		move();
		return;
	}
	for (int i = 0; i < 4; i++) {
		dir[a] = i;
		set_dir(a + 1);
		dir[a] = 0;
	}
}

int main() {
	cin >> num;
	for (int i = 0; i < num; i++)
		for (int j = 0; j < num; j++)
			cin >> dup[i][j];
	set_dir(0);
	cout << result;
	system("pause");
	return 0;
}