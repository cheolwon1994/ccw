#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int result = 0;
int question;

struct info {
	string str;
	int s, b;
};
info tmp;
vector<info> v;

void start(vector<int> temp) {
	bool avail = true;
	for (int i = 0; i < question; i++) {
		string t_str = v[i].str;
		int st = 0;
		int ba = 0;
		for (int j = 0; j < 3; j++) {
			int num = temp[j];
			if (num == t_str[j] - '0') {
				st++;
				continue;
			}
			for (int k = 0; k < 3; k++) {
				if (k == j)
					continue;
				else {
					if (num == t_str[k] - '0')
						ba++;
				}
			}
		}
		if (st == v[i].s && ba == v[i].b)
			continue;
		else {
			avail = false;
			break;
		}
	}
	if (avail) 
		result++;	
}

int main() {
	int strike, ball;
	string str;
	cin >> question;

	for (int i = 0; i < question; i++) {
		cin >> str >> strike >> ball;
		tmp.str = str;
		tmp.s = strike;
		tmp.b = ball;
		v.push_back(tmp);
	}
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			if (j == i)
				continue;
			for (int k = 1; k < 10; k++) {
				if (k == i)
					continue;
				if (k == j)
					continue;
				vector<int> temp;
				temp.push_back(i);
				temp.push_back(j);
				temp.push_back(k);
				start(temp);
			}
		}
	}
	cout << result;
	system("pause");
	return 0;
}