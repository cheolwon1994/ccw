#include <iostream>
#include <string>
#include <queue>
#include <sstream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int test, num;
	cin >> test;
	string order, str;
	for (int t = 0; t < test; t++) {
		cin >> order >> num >> str;
		str = str.substr(1);		//앞에 자르고
		str = str.substr(0, str.size() - 1);		//뒤 자르고
		istringstream ss(str);
		string buf;
		deque<int> dq;
		while (getline(ss, buf, ',')) {
			int val = atoi(buf.c_str());
			dq.push_back(val);
		}
		bool flag = false;		///false: 앞에서부터, true: 뒤에서부터
		bool isError = false;
		for (int i = 0; i < order.size(); i++) {
			if (order[i] == 'R') flag = !flag;
			else {
				if (dq.empty()) {
					isError = true;
					break;
				}
				else {
					if (!flag) dq.pop_front();
					else dq.pop_back();
				}
			}
		}
		if (isError) cout << "error\n";
		else {
			cout << "[";
			if (!flag) {
				for (int i = 0; i < dq.size(); i++) {
					cout << dq[i];
					if (i != dq.size() - 1)
						cout << ",";
				}
			}
			else {
				for (int i = dq.size() - 1; i >= 0; i--) {
					cout << dq[i];
					if (i != 0)
						cout << ",";
				}
			}
			cout << "]\n";
		}
	}
	return 0;
}