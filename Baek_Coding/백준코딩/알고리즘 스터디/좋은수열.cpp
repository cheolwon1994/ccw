#include <iostream>
#include <string>
using namespace std;
int num;
bool finish = false;
string result;
void back_tracking(string str, int idx) {
	if (finish) return;
	if (idx == num) {
		result = str;
		finish = true;
		return;
	}
	if (idx == 0) {
		back_tracking(str + to_string(1), idx + 1);
		back_tracking(str + to_string(2), idx + 1);
		back_tracking(str + to_string(3), idx + 1);
	}
	else {
		for (int j = 1; j < 4; j++) {
			char c = j + '0';
			string t1;
			string t2 = to_string(j);
			int t = idx / 2;
			if (idx % 2 == 1) t += 1;
			bool avail = true;
			if (str[idx - 1] == c) 
				continue;
			if (t > 1) {
				for (int i = 0; i < t; i++) {		//뒤에서 몇개를 더할건지
					t2 = str.substr(idx - i) + to_string(j);
					t1 = str.substr(idx - 1 - 2 * i, i + 1);
					if (t1 == t2) {
						avail = false;
						break;
					}
				}
			}
			if (avail)
				back_tracking(str + to_string(j), idx + 1);
		}
	}
}

int main() {
	cin >> num;
	result = "";
	back_tracking("", 0);
	cout << result;
	system("pause");
	return 0;
}