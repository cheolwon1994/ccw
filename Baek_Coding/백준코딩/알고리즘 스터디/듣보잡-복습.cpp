#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, int> m;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M, cnt = 0;
	cin >> N >> M;
	string str;
	for (int i = 0; i < N + M; i++) {
		cin >> str;
		if (m.find(str) == m.end())
			m[str] = 1;
		else {
			m[str]++;
			cnt++;
		}
	}
	cout << cnt << '\n';
	for (auto it = m.begin(); it != m.end(); it++) 
		if (it->second == 2)
			cout << it->first << '\n';	
	system("pause");
	return 0;
}