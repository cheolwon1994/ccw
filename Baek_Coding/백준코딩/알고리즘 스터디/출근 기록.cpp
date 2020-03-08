#include <iostream>
#include <string>
using namespace std;
int have_alpha[3];	//입력받은 alphabet 개수 체크
string s;
bool dp[51][51][51][3][3] = { false, };
char ans[51];
bool start(int a, int b, int c, int back1,int back2) {
	if (a==have_alpha[0] && b == have_alpha[1] && c == have_alpha[2]) {
		return true;
	}
	if (dp[a][b][c][back1][back2]) return false;
	dp[a][b][c][back1][back2] = true;

	if (a+1<=have_alpha[0]) {		//a 사용 가능
		ans[a + b + c] = 'A';
		if (start(a + 1, b, c, back2, 0))
			return true;

	}
	if (b + 1 <= have_alpha[1]) {
		ans[a + b + c] = 'B';
		if (back2 != 1) {		//b 사용 가능
			if (start(a, b + 1, c, back2, 1))
				return true;
		}
	}
	if (c + 1 <= have_alpha[2]) {
		ans[a + b + c] = 'C';
		if (back1 != 2 && back2 != 2) {		//c 사용 가능
			if (start(a, b, c + 1, back2, 2))
				return true;
		}
	}
	return false;
}

int main() {
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'A') have_alpha[0]++;
		else if (s[i] == 'B') have_alpha[1]++;
		else have_alpha[2]++;
	}
	if (start(0, 0, 0, -1, -1))
		for (int i = 0; i < s.size(); i++)
			cout << ans[i];
	else	cout << -1;
	system("pause");
	return 0;
}