#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
long long num;
vector<int> v;

void cal() {
	for (int i = 1; i*i <= num; i++) {
		if (num%i == 0) {
			v.push_back(i);
			if (i*i != num)
				v.push_back(num / i);
		}
	}
}
map<int, int> a;
map<int, int> b;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int alen, blen, tt;
	cin >> alen >> blen >> num;
	int cnt = 0;
	cal();		//약수 구하기
	sort(v.begin(), v.end());
	for (int i = 0; i < alen; i++) {
		cin >> tt;
		if (tt == 1) cnt++;
		else {
			if (cnt != 0) {
				if (a.find(cnt) == a.end())
					a[cnt] = 1;
				else
					a[cnt]++;
				cnt = 0;
			}
		}
	}
	if (cnt != 0) {
		if (a.find(cnt) == a.end())	a[cnt] = 1;
		else	a[cnt]++;
	}
	cnt = 0;
	for (int i = 0; i < blen; i++) {
		cin >> tt;
		if (tt == 1) cnt++;
		else {
			if (cnt != 0) {
				if (b.find(cnt) == b.end())
					b[cnt] = 1;
				else
					b[cnt]++;
				cnt = 0;
			}
		}
	}
	if (cnt != 0) {
		if (b.find(cnt) == b.end())	b[cnt] = 1;
		else	b[cnt]++;
	}
	long long ans = 0;
	for (int i = 0; i < v.size(); i++) {
		int first = v[i];
		int second = v[v.size() - 1 - i];
		long long cnt1 = 0, cnt2 = 0;
		for (auto it = a.begin(); it != a.end(); it++) {
			if (it->first >= first) {
				cnt1 += ((it->first - first + 1)*(it->second));
			}
		}
		for (auto it = b.begin(); it != b.end(); it++) {
			if (it->first >= second) {
				cnt2 += ((it->first - second + 1)*(it->second));
			}
		}
		ans += cnt1 * cnt2;
	}
	cout << ans;
	return 0;
}