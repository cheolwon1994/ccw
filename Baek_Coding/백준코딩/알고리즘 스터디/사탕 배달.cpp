#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<long long> v3, v5;
long long val, weight, t, s, result = 0, three[250001], five[250001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, bag;
	cin >> n >> bag;
	for (int i = 0; i < n; i++) {
		cin >> weight >> val;
		if (weight == 3) v3.push_back(val);
		else v5.push_back(val);
	}
	sort(v3.begin(), v3.end());
	reverse(v3.begin(), v3.end());
	sort(v5.begin(), v5.end());
	reverse(v5.begin(), v5.end());

	three[0] = 0;
	five[0] = 0;
	if (!v5.empty()) {
		for (int i = 1; i <= v5.size(); i++)
			five[i] = (five[i - 1] + v5[i - 1]);
	}
	if (!v3.empty()) {
		for (int i = 1; i <= v3.size(); i++)
			three[i] = (three[i - 1] + v3[i - 1]);
	}
	int lenf = v5.size(), lent = v3.size();
	int avail = bag / 5, idx = 0;
	while (idx <= min(avail,lenf)) {
		long long temp = five[idx];
		int remain = (bag - (idx * 5)) / 3;		//남은 공간에 채울 수 있는 3짜리 사탕의 최대 수
		remain = min(remain, lent);
		temp += three[remain];
		result = max(result, temp);
		idx++;
	}
	cout << result;
	system("pause");
	return 0;
}