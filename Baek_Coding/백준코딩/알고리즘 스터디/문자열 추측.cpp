#include <string>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
string v[2] = { "","" };
vector<string> temp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int num;
	string str, result = "", result2 = "", answer;
	cin >> num;
	for (int i = 0; i < 2 * (num - 1); i++) {
		cin >> str;
		if (str.size() == num - 1) {
			if(v[0]=="")
				v[0] = str;
			else v[1] = str;
		}
		temp.push_back(str);
	}
	
	result = v[0] + v[1][num - 2];
	result2 = v[1] + v[0][num - 2];
	v[0] = result;
	v[1] = result2;
	set<string> s;
	set<string> ::iterator it;
	string ss = "";
	bool avail = true;
	for (int k = 0; k < 2; k++) {
		s.clear();
		answer = "";
		for (int i = 0; i < 2*(num-1); i++) {		
			bool avail = false;
			for (int j = 1; j < num; j++) {
				ss = v[k].substr(0, j);
				if (ss == temp[i]) {
					avail = true;
					break;
				}
			}
			if (avail) {
				if (s.find(temp[i]) == s.end()) {
					s.insert(temp[i]);
					answer += "P";
				}
				else	answer += "S";
			}
			else {
				if (temp[i][temp[i].size() - 1] == v[k][num - 1])
					answer += "S";
			}
			if (answer.size() == 2 * (num - 1)) {
				cout << v[k] << '\n' << answer;
				system("pause");
				return 0;
			}
		}
	}
	cout << v[1] << '\n' << answer;
	system("pause");
	return 0;
}