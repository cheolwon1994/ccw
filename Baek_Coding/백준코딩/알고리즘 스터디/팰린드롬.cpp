#include <iostream>
#include <string>
using namespace std;
bool dp[2001][2001] = { false, };
int result[2001];
string str;

void palindrome() {
	for (int i = 2; i < str.size(); i++) 
		for (int j = 1; j < str.size() - i; j++) 
			if (str[j] == str[j + i] && dp[j + 1][j + i - 1]) 
				dp[j][j + i] = dp[j + i][j] = true;	
}

int main() {
	cin >> str;
	str = " " + str;
	//���� 1��¥���� �׻� �縰���
	for (int i = 1; i <= str.size(); i++) 
		dp[i][i] = true;
	//�ٷ� ���� ĭ�� ���ٸ� �縰���
	for (int i = 1; i < str.size(); i++) {
		if (str[i] == str[i + 1]) {
			dp[i][i + 1] = true;
			dp[i + 1][i] = true;
		}
	}
	palindrome();
	for (int i = 1; i <= str.size(); i++) {
		for (int j = 1; j <= i; j++) {
			if (dp[i][j]) {
				if (result[i] == 0 || result[i] > result[j - 1] + 1)
					result[i] = result[j - 1] + 1;
			}
		}
	}
	cout << result[str.size()-1];
	system("pause");
	return 0;
}