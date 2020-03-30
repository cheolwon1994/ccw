#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int alpha[26];		//���� �Էµ� ���ĺ� ��
vector<string> v;
vector<int> ans;
bool finish;

void dfs(int idx, int remain) {
	if (finish) return;		//�̹� ����� ���� ���
	if (idx == 2 || idx == 6 || idx == 8)	dfs(idx + 1, remain);		//�̹� �˻��� ���ڵ�
	if (remain == 0) {		//���� ���
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
		dfs(idx, remain - v[idx].size());		//���ڸ� ä�� �� �ִ� ���
		if (finish) return;
		ans.pop_back();
		for (int i = 0; i < v[idx].size(); i++) {
			int c = v[idx][i] - 'A';
			alpha[c]++;
		}
	}
	dfs(idx + 1, remain);		//���� ���ڷ� �Ѿ�� ���
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
		//�ʱ�ȭ
		for (int j = 0; j < 26; j++)
			alpha[j] = 0;
		ans.clear();
		cnt = 0;
		finish = false;

		for (int j = 0; j < str.size(); j++) {
			char c = str[j];
			alpha[c - 'A']++;
			cnt++;
			if (c == 'Z') {			//ZERO�� ���Ե� ���
				ans.push_back(0);
				for (int k = 0; k < v[0].size(); k++) {
					alpha[v[0][k] - 'A']--;
					cnt--;
				}
			}
			else if (c == 'W') {		//TWO�� ���Ե� ���
				ans.push_back(2);
				for (int k = 0; k < v[2].size(); k++) {
					alpha[v[2][k] - 'A']--;
					cnt--;
				}
			}
			else if (c == 'X') {		//SIX�� ���Ե� ���
				ans.push_back(6);
				for (int k = 0; k < v[6].size(); k++) {
					alpha[v[6][k] - 'A']--;
					cnt--;
				}
			}
			else if (c == 'G') {		//EIGHT�� ���Ե� ���
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