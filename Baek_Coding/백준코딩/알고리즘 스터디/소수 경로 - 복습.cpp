#define MAX 987654321
#include <iostream>
#include <math.h>
#include <string>
#include <string.h>
#include <queue>
using namespace std;
struct info {
	string str;
	int cnt;
};
info tmp;

int isPrimary[10000];
int check[10000];
void cal() {
	for (int i = 2; i < 10000; i++)
		isPrimary[i] = i;
	for (int i = 2; i < 100; i++) {
		if (isPrimary[i] > 0) {
			for (int j = i + i; j <10000; j += i)
				isPrimary[j] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cal();
	int test, va, vb;
	cin >> test;
	string a, b;
	for (int t = 0; t < test; t++) {
		cin >> a >> b;
		for (int i = 1000; i < 10000; i++)
			check[i] = MAX;
		va = atoi(a.c_str());
		vb = atoi(b.c_str());
		check[va] = 0;
		queue<info> q;
		tmp.cnt = 0;
		tmp.str = a;
		q.push(tmp);
		while (!q.empty()) {
			string cs = q.front().str;
			int cc = q.front().cnt;
			q.pop();
			if (atoi(cs.c_str()) == vb)
				break;
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 10; j++) {
					if (i==0 && j==0) continue;
					if (i == 3 && (j % 2 == 0)) continue;
					string ss = cs;
					ss[i] = j + '0';
					va = atoi(ss.c_str());
					if (isPrimary[va] > 0 && check[va] > cc + 1) {
						check[va] = cc + 1;
						tmp.str = ss;
						tmp.cnt = cc + 1;
						q.push(tmp);
					}
				}
			}
		}
		if (check[vb] == MAX) cout << "Impossible\n";
		else cout << check[vb] << '\n';
	}
	return 0;
}