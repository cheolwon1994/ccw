#define MAX 987654321
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
struct info {
	int len, val, copy;
};
info tmp;
int check[1001][1001], num;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	for (int i = 1; i <= 1000; i++)
		for(int j=0;j<=1000;j++)
			check[i][j] = MAX;
	cin >> num;
	int result = MAX;
	if (num == 1) cout << 0;	
	else {
		queue<info> q;
		tmp.len = 1;
		tmp.val = 0;
		tmp.copy = 0;
		check[1][0] = 0;
		q.push(tmp);
		while (!q.empty()) {
			int cl = q.front().len;
			int cv = q.front().val;
			int cp = q.front().copy;
			q.pop();
			if (cl == num) 
				result = min(result, cv);			
			if (cl - 1 > 0 && check[cl - 1][cp] > cv + 1) {
				check[cl - 1][cp] = cv + 1;
				tmp.len = cl - 1;
				tmp.val = cv + 1;
				tmp.copy = cp;
				q.push(tmp);
			}
			if (cp>0 && cp+cl<=1000 && check[cp+cl][cp]>cv+1) {
				check[cp + cl][cp] = cv + 1;
				tmp.len = cp + cl;
				tmp.val = cv + 1;
				tmp.copy = cp;
				q.push(tmp);
			}
			if (check[cl][cl]>cv+1 && cv + 1 < result) {
				tmp.copy = cl;
				tmp.val = cv + 1;
				tmp.len = cl;
				q.push(tmp);
			}
		}
		cout << result;
	}
	return 0;
}