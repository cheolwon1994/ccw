#define MAX 100000001
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
int num[12];
bool check[11];
vector<int> op;
vector<int> v;
int len;
long long maxi, mini;

void dfs(int a) {
	if (a == len-1) {
		long long sum = num[0];
		for (int i = 0; i < a; i++) {
			if (v[i] == 0) sum += num[i+1];
			else if (v[i] == 1) sum -= num[i + 1];
			else if (v[i] == 2) sum *= num[i + 1];
			else if (v[i] == 3) sum = (int)(sum / num[i + 1]);
		}
		maxi = max(maxi, sum);
		mini = min(mini, sum);
		return;
	}
	bool used[10] = { false, };
	for (int i = 0; i < len-1; i++) {
		if (check[i] != 1 && !used[op[i]]) {
			v.push_back(op[i]);
			check[i] = true;
			used[op[i]] = true;
			dfs(a + 1);
			v.pop_back();
			check[i] = false;
		}
	}
}

int main() {
	int test, tt;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		//ÃÊ±âÈ­
		op.clear();
		v.clear();
		memset(check, false, sizeof(check));
		maxi = -MAX;
		mini = MAX;

		cin >> len;
		for (int i = 0; i < 4; i++) {
			cin >> tt;
			for (int j = 0; j < tt; j++)
				op.push_back(i);
		}
		for (int i = 0; i < len; i++) 
			cin >> num[i];
		dfs(0);
		cout << "#" << t << " " << maxi-mini << endl;
	}
	system("pause");
	return 0;
}