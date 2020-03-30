#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int alpha[26];		//현재 입력된 알파벳 수
vector<string> v;
vector<int> ans;
bool finish;

void dfs(int idx, int remain) {
	if (finish) return;		//이미 결과가 나온 경우
	if (idx == 2 || idx == 6 || idx == 8)	dfs(idx + 1, remain);		//이미 검사한 숫자들
	if (remain == 0) {		//끝난 경우
		finish = true;
		return;
	}
	if (idx == 10) return;

	bool avail = true;
	for (int i = 0; i < v[idx].size(); i++) {
		int c = v[idx][i] - 'A';
		if (alpha[c] == 0) {
			avail = false;
			break;
		}		
	}
	if (avail) {
		for (int i = 0; i < v[idx].size(); i++) {
			int c = v[idx][i] - 'A';
			alpha[c]--;
		}
		ans.push_back(idx);
		dfs(idx, remain - v[idx].size());		//숫자를 채울 수 있는 경우
		if (finish) return;
		ans.pop_back();
		for (int i = 0; i < v[idx].size(); i++) {
			int c = v[idx][i] - 'A';
			alpha[c]++;
		}
	}
	dfs(idx + 1, remain);		//다음 숫자로 넘어가는 경우
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	v.push_back("ZERO");
	v.push_back("ONE");
	v.push_back("TWO");
	v.push_back("THREE");
	v.push_back("FOUR");
	v.push_back("FIVE");
	v.push_back("SIX");
	v.push_back("SEVEN");
	v.push_back("EIGHT");
	v.push_back("NINE");
	int num, cnt;
	cin >> num;
	string str;
	for (int i = 0; i < num; i++) {
		cin >> str;
		//초기화
		for (int j = 0; j < 26; j++)
			alpha[j] = 0;
		ans.clear();
		cnt = 0;
		finish = false;

		for (int j = 0; j < str.size(); j++) {
			char c = str[j];
			alpha[c - 'A']++;
			cnt++;
			if (c == 'Z') {			//ZERO가 포함된 경우
				ans.push_back(0);
				for (int k = 0; k < v[0].size(); k++) {
					alpha[v[0][k] - 'A']--;
					cnt--;
				}
			}
			else if (c == 'W') {		//TWO가 포함된 경우
				ans.push_back(2);
				for (int k = 0; k < v[2].size(); k++) {
					alpha[v[2][k] - 'A']--;
					cnt--;
				}
			}
			else if (c == 'X') {		//SIX가 포함된 경우
				ans.push_back(6);
				for (int k = 0; k < v[6].size(); k++) {
					alpha[v[6][k] - 'A']--;
					cnt--;
				}
			}
			else if (c == 'G') {		//EIGHT이 포함된 경우
				ans.push_back(8);
				for (int k = 0; k < v[8].size(); k++) {
					alpha[v[8][k] - 'A']--;
					cnt--;
				}
			}
		}
		dfs(1, cnt);
		sort(ans.begin(), ans.end());
		cout << "Case #" << i+1 << ": ";
		for (int k = 0; k < ans.size(); k++)
			cout << ans[k];
		cout << '\n';
	}
	system("pause");
	return 0;
}