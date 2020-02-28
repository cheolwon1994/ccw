#define MAX 500001
#include <iostream>
#include <queue>
using namespace std;
int check[2][MAX];

int main() {
	int start, target;
	cin >> start >> target;
	if (start == target) {
		cout << 0;
		system("pause");
		return 0;
	}
	for (int i = 0; i < MAX; i++) {
		check[0][i] = -1;			//Â¦
		check[1][i] = -1;			//È¦
	}
	queue<int> q;
	q.push(start);
	check[0][start] = 0;
	int cnt = 0, result = -1;
	while (!q.empty()) {
		//µ¿»ý ÀÌµ¿		
		int len = q.size();
		for (int i = 0; i < len; i++) {
			int cloc = q.front();
			q.pop();
			if (cloc == target) {
				result = cnt;
				break;
			}
			if (cloc - 1 >= 0 && check[(cnt+1) % 2][cloc - 1] == -1) {
				check[(cnt + 1) % 2][cloc - 1] = cnt + 1;
				q.push(cloc - 1);
			}
			if (cloc + 1 < MAX && check[(cnt + 1) % 2][cloc + 1] == -1) {
				check[(cnt + 1) % 2][cloc + 1] = cnt + 1;
				q.push(cloc + 1);
			}
			if (cloc * 2 < MAX && check[(cnt + 1) % 2][cloc * 2] == -1) {
				check[(cnt + 1) % 2][cloc * 2] = cnt + 1;
				q.push(cloc *2);
			}
		}
		if (result > 0) break;
		cnt++;
		target += cnt;
		if (target > 500000)	break;
		if (check[cnt%2][target] != -1) {
			result = cnt;
			break;
		}
	}
	cout << result;
	system("pause");
	return 0;
}