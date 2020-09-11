#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
string str, ss;
int len;
vector<string> v;

int solution(string s) {
	len = s.size();
    int answer = len;
	for (int i = 1; i <= len/ 2; i++) {
		v.clear();
		str = "";
		for (int j = 0; j < len; j += i) {
			if (j + i <= len) 
				ss = s.substr(j, i);
			else 
				ss = s.substr(j);			
			v.push_back(ss);
		}
		string pre, cs;
		int cnt = 1;
		for (int j = 0; j < v.size()-1; j++) {
			pre = v[j];
			cs = v[j+1];
			if (pre == cs) cnt++;
			else {
				if (cnt > 1) {
					str += to_string(cnt);
					cnt = 1;
				}
				str += pre;
			}
		}
		if (cnt > 1) {
			str += to_string(cnt);
			str += pre;
		}
		else {
			str += cs;
		}
		int temp = str.size();
		answer = min(answer, temp);
	}
	return answer;
}