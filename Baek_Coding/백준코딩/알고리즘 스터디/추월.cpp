#include <iostream>
#include <string>
#include <map>
using namespace std;
bool check[1001] = { false, };
int fin[1001];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int num;
	cin >> num;
	map<string, int> m;
	string str;
	for (int i = 0; i < num; i++) {
		cin >> str;
		m[str] = i;
	}
	int pass = 0;		//추월한 차량 수
	for (int i = 0; i < num; i++) {
		cin >> str;
		int val = m[str];
		fin[i] = val;
	}
	for (int i = 0; i < num - 1; i++) {
		for (int j = i + 1; j < num; j++) {
			if (fin[i] > fin[j]) {
				pass++;
				break;
			}
		}
	}
	cout << pass;
	return 0;
}