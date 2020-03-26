#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<string> word;
int result = -1;
vector<char> alpha;				//들어있는 알파벳
bool type[26] = { false, };		//어떤 알파벳이 사용되었는지 확인
bool check[10];
vector<int> v;			//각 알파벳에 해당하는 숫자

void cal() {
	int t_result = 0;
	int cnt = 0;
	int a[26];
	for (int i = 0; i < alpha.size(); i++) {
		char c = alpha[i];
		int num = v[i];
		a[c - 'A'] = num;
	}
	for (int i = 0; i < word.size(); i++) {
		int temp = 0;
		for (int j = 0; j < word[i].size(); j++) {
			temp *= 10;
			temp += a[word[i][j] - 'A'];
		}
		t_result += temp;
	}
	result = max(result, t_result);
}

void dfs(int cnt) {
	if (cnt == 10) {
		cal();
		return;
	}
	for (int i = 10 - alpha.size(); i < 10; i++) {
		if (!check[i]) {
			v.push_back(i);
			check[i] = true;
			dfs(cnt + 1);
			check[i] = false;
			v.pop_back();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int num;
	string ss;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> ss;
		word.push_back(ss);
		for (int j = 0; j < ss.size(); j++) {
			int c = ss[j] - 'A';
			if (!type[c]) {
				type[c] = true;
				alpha.push_back(ss[j]);
			}
		}
	}
	dfs(10 - alpha.size());
	cout << result;
	system("pause");
	return 0;
}