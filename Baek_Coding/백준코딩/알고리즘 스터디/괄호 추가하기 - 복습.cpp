#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;
int num;
long long result = -987654321;
string str;

void start(int idx,long long sum) {
	if (idx == num-1) {
		result = max(result, sum);
		return;
	}
	//°ýÈ£ Ãß°¡
	if (idx + 4 < num) {
		int tt;
		if (str[idx + 3] == '+')
			tt = (str[idx + 2] - '0') + (str[idx + 4] - '0');
		else if (str[idx + 3] == '-')
			tt = (str[idx + 2] - '0') - (str[idx + 4] - '0');
		else if (str[idx + 3] == '*')
			tt = (str[idx + 2] - '0') * (str[idx + 4] - '0');

		if (str[idx + 1] == '+')
			start(idx + 4, sum + tt);
		else if (str[idx + 1] == '-')
			start(idx + 4, sum - tt);
		else if (str[idx + 1] == '*')
			start(idx + 4, sum * tt);
	}
	if (str[idx + 1] == '+')
		start(idx + 2, sum + (str[idx + 2] - '0'));
	else if (str[idx + 1] == '-')
		start(idx + 2, sum - (str[idx + 2] - '0'));
	else if (str[idx + 1] == '*')
		start(idx + 2, sum * (str[idx + 2] - '0'));
}

int main() {
	cin >> num;
	cin >> str;
	start(0,(str[0]-'0'));
	cout << result;
	system("pause");
	return 0;
}