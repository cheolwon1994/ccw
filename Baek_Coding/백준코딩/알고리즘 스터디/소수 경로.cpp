#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
vector<int> prime;
int isPrime[10000];
bool visit[10000];
int mul[4] = { 1000,100,10,1 };

void cal() {
	for (int i = 2; i < 10000; i++)
		isPrime[i] = i;
	for (int i = 2; i < 10000; i++) {
		if (isPrime[i] == 0) continue;		
		for (int j = i * 2; j < 10000; j += i)
			isPrime[j] = 0;	
	}
	for (int i = 2; i < 10000; i++) {
		if (isPrime[i] != 0 && i >= 1000)
			prime.push_back(i);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cal();
	int num, start, dest;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> start >> dest;
		for (int j = 1000; j < 10000; j++)
			visit[j] = false;
		for (int j = 0; j < prime.size(); j++)
			visit[prime[j]] = true;
		queue<int> q;
		visit[start] = false;
		int cnt = 0;
		q.push(start);
		bool finish = false;
		while (!q.empty()) {
			int len = q.size();
			for (int k = 0; k < len; k++) {
				int cidx = q.front();
				q.pop();
				if (cidx == dest) {
					finish = true;
					break;
				}
				for (int m = 0; m < 4; m++) {
					int temp = 0;
					if (m == 0) temp = cidx % 1000;
					else if (m == 1) {
						temp = cidx / 1000;
						temp *= 1000;
						temp += cidx % 100;
					}
					else if (m == 2) {
						temp = cidx / 100;
						temp *= 100;
						temp += cidx % 10;
					}
					else if (m == 3) {
						temp = cidx / 10;
						temp *= 10;
					}
					int add;
					for (int l = 0; l < 10; l++) {
						add = mul[m] * l;
						add += temp;
						if (visit[add]) {
							visit[add] = false;
							q.push(add);
						}
					}
				}
			}
			if (finish)
				break;
			cnt++;
		}
		if (finish) cout << cnt << '\n';
		else cout << "Impossible\n";
	}
	system("pause");
	return 0;
}