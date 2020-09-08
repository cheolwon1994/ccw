#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
map<long long, long long> ma;
int arr[2][1000];
long long target, result = 0, diff;
int na, nb, val;

void cal(int num) {
	int len = (num == 0) ? na : nb;
	int sum = arr[num][0];
	map<long long, long long> m;
	vector<long long > v, dup;
	map<long long, long long> ::iterator it;
	for (int i = 0; i < len; i++) {
		val = arr[num][i];
		if (num == 0) {
			if (m.find(val) == m.end()) 
				m[val] = 1;			
			else 
				m[val] += 1;			
		}
		else {
			diff = target - val;
			it = ma.find(diff);
			if (it != ma.end()) 
				result += (it->second);			
		}
		v.push_back(val);
	}
	for (int t = 1; t <= len; t++) {
		for (int i = t; i < len; i++) {
			val = arr[num][i] + v[i - t];
			if (num == 0) {
				if (m.find(val) == m.end())
					m[val] = 1;
				else
					m[val] += 1;
			}
			else {
				diff = target - val;
				it = ma.find(diff);
				if (it != ma.end())
					result += (it->second);
			}
			dup.push_back(val);
		}
		v = dup;
		dup.clear();
	}
	if (num == 0) ma = m;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> target >> na;
	for (int i = 0; i < na; i++)
		cin >> arr[0][i];
	cin >> nb;
	for (int i = 0; i < nb; i++)
		cin >> arr[1][i];
	cal(0);
	cal(1);
	cout << result;
	return 0;
}