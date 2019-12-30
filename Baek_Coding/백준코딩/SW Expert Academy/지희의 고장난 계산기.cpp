#define MAX 987654321
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
bool check[10];
int result, t_len, target;
vector<int> v;

int len(int num) {
	int tmp;
	for (int i = 1;; i++) {
		if (num / 10 > 0) {
			num /= 10;
		}
		else {
			tmp = i;
			break;
		}
	}
	return tmp;
}

void dfs(int cnt) {
	if (cnt > target)
		return;
	if (cnt <= target) {
		if (cnt == 0) {
			if (check[cnt]) {
				v.push_back(cnt);
			}
		}
		else {
			v.push_back(cnt);
		}
	}
	for (int i = 0; i < 10; i++) {
		if (check[i]) {
			if (cnt == 0 && i == 0)
				continue;
			dfs(cnt*10+i);
		}
	}
}
void divide(int cur_num, int t_result) {
	if (cur_num == 1) {
		result = min(result, t_result);
		return;
	}
	for (int i = 0; i < v.size(); i++) {
		if (v[i] < 2)
			continue;
		if (cur_num%v[i] == 0) 
			divide(cur_num / v[i], t_result + len(v[i])+1);	
		if (cur_num < v[i])
			break;
	}
}

int main() {
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		//ÃÊ±âÈ­
		memset(check, false, sizeof(check));
		result = MAX;
		v.clear();

		for (int i = 0; i < 10; i++)
			cin >> check[i];
		cin >> target;
		if (target == 1) {
			if (check[1]) 
				cout << "#" << t << " " << 2 << endl;			
			else
				cout << "#" << t << " " << -1 << endl;
			continue;
		}
		dfs(0);
		sort(v.begin(), v.end());	
		divide(target,0);
		if (result == MAX)
			cout << "#" << t << " " << -1 << endl;
		else
			cout << "#" << t << " " << result << endl;
	}
	system("pause");
	return 0;
}
