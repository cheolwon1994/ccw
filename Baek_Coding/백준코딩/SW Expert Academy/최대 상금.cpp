#define CRT_NO_SECURE_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
using namespace std;
int change_num;
vector<char> v;
string str;
string str_ans;


void change(int a, int cnt) {
	//cout << str<<endl;
	int size = str.size();
	if (cnt == change_num) {
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == str_ans[i]) {
				//다음거 비교
			}
			else if (str[i] > str_ans[i]) {		//새로운게 더 큰 경우
				str_ans = str;
				break;
			}
			else if (str[i] < str_ans[i]) {		//기존이 더 큰 경우
				break;
			}
		}
		return;
	}
	if (change_num - cnt == size - a || a == size - 1) {
		int remain = size - a;
		remain = remain % 2;
		if (remain == 1) {
			char temp = str[size - 2];
			str[size - 2] = str[size - 1];
			str[size - 1] = temp;
			change(a, change_num);
			str[size - 1] = str[size - 2];
			str[size - 2] = temp;
		}
		else
			change(a, change_num);
		return;
	}
	char big = v[size - (1+a)];
	int idx;
	for (int i = size - 1; i >= a; i--) {
		if (str[i] == big) {		//첫번째가 가장 높은수가 아닐 경우
			if (i != a) {
				char temp = str[a];
				str[a] = big;
				str[i] = temp;
				change(a + 1, cnt + 1);
				str[a] = str[i];
				str[i] = big;
			}
			else if (i == a) 		//첫번째가 가장 높은 수일 경우
				change(a + 1, cnt);			
		}
	}
}

int main() {
	int test_Case;
	cin >> test_Case;

	for (int i = 0; i < test_Case; i++) {
		v.clear();
		str.clear();
		str_ans.clear();
		cin >> str >> change_num;
		for (int i = 0; i < str.size(); i++)
			v.push_back(str[i]);
		sort(v.begin(), v.end());
		str_ans = str;		
		change(0,0);
		cout << "#" << i + 1 << " " << str_ans << endl;
	}
	system("PAUSE");
	return 0;
}