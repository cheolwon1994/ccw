#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int num, cur = -1, idx;
bool finish = false;
vector<string> v[11];

void dfs(int cnt) {
	if(cnt == 11) return;		//더이상 감소하는 수가 존재x
	if (cur >= num) {				//이미 N번째 감소하는 수 찾은 경우
		idx = cnt;
		finish = true;
		return;
	}
	for (int i = 0; i < v[cnt].size(); i++) {
		string ss = v[cnt][i];
		char c;
		if (ss == "") c = 'a';
		else c = ss[ss.size() - 1];
		for (int i = 0; i < 10; i++) {
			char c2 = i + '0';
			if (c2 >= c) break;
			string s2 = ss + c2;
			v[cnt+1].push_back(s2);
			cur++;
		}
	}
	dfs(cnt + 1);
}

int main() {
	cin >> num;
	v[0].push_back("");
	dfs(0);
	if (!finish) cout << -1;
	else {
		sort(v[idx].begin(), v[idx].end());
		int sum = 0;
		for (int i = 1; i < idx; i++)
			sum += v[i].size();
		cout << v[idx][num - sum];
	}
	return 0;
}