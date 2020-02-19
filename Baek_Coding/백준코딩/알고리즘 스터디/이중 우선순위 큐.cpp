#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main() {
	int test;
	cin >> test;
	for (int t = 0; t < test; t++) {
		int num;
		cin >> num;
		map<long long, long long> m;
		map<long long, long long> ::iterator it;
		int cnt = 0;
		for (int i = 0; i < num; i++) {
			char c;
			int tt;
			cin >> c >> tt;
			if (c == 'I') { 
				if (m.find(tt) == m.end())
					m[tt] = 1;
				else
					m[tt]++;
			}
			else{
				if (!m.empty()) {
					if (tt == 1) 		//최대삭제
						it = --m.end();
					else
						it = m.begin();
					if (it->second == 1)
						m.erase(it);
					else
						it->second--;
				}				
			}
		}
		if (m.size()==0) cout << "EMPTY\n";
		else {
			it = --m.end();
			cout << it->first << " " << m.begin()->first << '\n';
		}
	}
	system("pause");
	return 0;
}