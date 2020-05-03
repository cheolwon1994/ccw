#include <iostream>
#include <algorithm>
using namespace std;
char arr[1000];
int check[1000], num, result = 0;
bool number[1001] = { false, };
int dfs(int idx, int cnt) {
	if (check[idx] != -1) return check[idx];
	int temp = check[idx];
	check[idx] = cnt;
	if (arr[idx] == 'E') {
		if (idx + 1 == num) return cnt;
		else
			temp = dfs(idx + 1, cnt);
	}
	else if (arr[idx] == 'W') {
		if (idx == 0) return cnt;
		else
			temp = dfs(idx - 1, cnt);
	}
	check[idx] = temp;
	return temp;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> num;
	int vv = 0;
	for (int i = 0; i < num; i++)
		cin >> arr[i];
	for (int i = 0; i < num; i++)
		check[i] = -1;
	for (int i = 0; i < num; i++)
		if (check[i] == -1) 
			dfs(i, ++vv);	
	for (int i = 0; i < num; i++) {
		if (!number[check[i]]) {
			number[check[i]] = true;
			result++;
		}
	}		
	cout << result;
	system("pause");
	return 0;
}